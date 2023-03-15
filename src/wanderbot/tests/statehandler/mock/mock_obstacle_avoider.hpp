



#ifndef WANDERBOT_MOCK_OBSTACLE_AVOIDER_ACUTE_LEFT_HPP
#define WANDERBOT_MOCK_OBSTACLE_AVOIDER_ACUTE_LEFT_HPP

#include "wanderbot/motion/obstacle_avoider.hpp"

// This mock returns an acute left angle to see how the go state handler deals with it
class MockObstacleAvoiderAcuteLeft : public ObstacleAvoider {
public:
  MockObstacleAvoiderAcuteLeft(const double angle_to_return) : angle_to_return_(angle_to_return) {};
  Vector calculateNewMotionVector(
    const Config & config, const Vector & vector_to_obstacle) const;

private:
  const double angle_to_return_;
};
#endif  //WANDERBOT_MOCK_OBSTACLE_AVOIDER_ACUTE_LEFT_HPP
