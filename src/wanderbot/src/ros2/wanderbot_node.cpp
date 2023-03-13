// Copyright 2023 Steve Billings
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "geometry_msgs/msg/twist.hpp"
#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/laser_scan.hpp"
#include "wanderbot/fsm/statehandler/state_handlers.hpp"
#include "wanderbot/laser/laser_analyzer.hpp"

using std::placeholders::_1;
using namespace std::chrono_literals;

class WanderBotNode : public rclcpp::Node
{
public:
  WanderBotNode()
  : Node("wanderbot_node")
  {
    laser_scan_subscriber_ = create_subscription<sensor_msgs::msg::LaserScan>(
      "laser_scan", 10, std::bind(&WanderBotNode::laserScanCallback, this, _1));
    timer_ = create_wall_timer(50ms, std::bind(&WanderBotNode::controlCallback, this));
    drive_publisher_ = create_publisher<geometry_msgs::msg::Twist>("cmd_vel", 10);
  }

private:
  void laserScanCallback(const sensor_msgs::msg::LaserScan::SharedPtr msg)
  {
    last_laser_scan_msg_ = std::move(msg);
  }

  void controlCallback()
  {
    if (last_laser_scan_msg_ == nullptr) {
      RCLCPP_INFO(logger_, "Haven't received a laser scan yet");
      return;
    }

    RCLCPP_INFO(logger_, "State: %s", cur_state_handler_->getName());
    double current_time = now().seconds();
    init_laser_characteristics();
    Vector vector_to_obstacle =
      laser_analyzer_.analyze(*laser_characteristics_, last_laser_scan_msg_->ranges);

    Action action = cur_state_handler_->act(
      config_, current_time - time_entered_state_seconds_, vector_to_obstacle);

    if (action.get_state() != cur_state_handler_->getState()) {
      time_entered_state_seconds_ = current_time;
      cur_state_handler_ = state_handlers_.get_state_handler(action.get_state());
    }

    std::optional<Velocity> new_velocity = action.get_velocity();
    if (new_velocity.has_value()) {
      set_velocity(new_velocity.value());
    }
  }

  void init_laser_characteristics()
  {
    if (laser_characteristics_ == nullptr) {
      LaserCharacteristics laser_characteristics = laser_analyzer_.determineCharacteristics(
        last_laser_scan_msg_->angle_min, last_laser_scan_msg_->angle_increment,
        last_laser_scan_msg_->ranges);
      // Toss characteristics object onto heap so it sticks around for the life of the node
      laser_characteristics_ = new LaserCharacteristics(laser_characteristics);
    }
  }

  void set_velocity(const Velocity & velocity)
  {
    double x = limitToMax(velocity.get_forward(), config_.getMaxForwardVelocity());
    double yaw = limitToMax(velocity.get_yaw(), config_.getMaxYaw());
    geometry_msgs::msg::Twist drive_message;
    drive_message.linear.x = x;
    drive_message.angular.z = yaw;
    drive_publisher_->publish(drive_message);
  }
  double limitToMax(const double proposed_value, const double max_magnitude) const
  {
    if (proposed_value > max_magnitude) {
      return max_magnitude;
    } else if (proposed_value < (-1 * max_magnitude)) {
      return -1 * max_magnitude;
    }
    return proposed_value;
  }

  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Subscription<sensor_msgs::msg::LaserScan>::SharedPtr laser_scan_subscriber_;
  sensor_msgs::msg::LaserScan::SharedPtr last_laser_scan_msg_;
  rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr drive_publisher_;
  StateHandlers state_handlers_ = StateHandlers();
  StateHandler * cur_state_handler_ = state_handlers_.get_state_handler(State::GO);
  LaserCharacteristics * laser_characteristics_ = nullptr;
  LaserAnalyzer laser_analyzer_;
  double time_entered_state_seconds_ = 0.0l;
  rclcpp::Logger logger_ = get_logger();
  Config config_ = Config();
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<WanderBotNode>();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}
