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

#ifndef WANDERBOT__CONFIG__CONFIG_HPP_
#define WANDERBOT__CONFIG__CONFIG_HPP_

#include <cmath>

class Config
{
public:
  double getVffMinimumIgnorableDistance() const;
  double getObstacleMinimumSafeDistance() const;
  double getThrottleSettingForward() const;
  double getThrottleSettingYaw() const;
  double getMaxForwardVelocity() const;
  double getMaxYaw() const;
  double getBackUpVelocity() const;
  double getChangeDirectionSpinVelocity() const;
  double getBackUpDurationSeconds() const;
  double getSpinDurationSeconds() const;

private:
  static const double VFF_MINIMUM_IGNORABLE_DISTANCE_;
  static const double OBSTACLE_MINIMUM_SAFE_DISTANCE_;
  static const double THROTTLE_SETTING_FORWARD_;
  static const double THROTTLE_SETTING_YAW_;
  static const double MAX_FORWARD_VELOCITY_;
  static const double MAX_YAW_;
  static const double BACK_UP_VELOCITY_;
  static const double CHANGE_DIRECTION_SPIN_VELOCITY_;
  static const double BACK_UP_SECONDS_;
  static const double SPIN_SECONDS_;
};

#endif  // WANDERBOT__CONFIG__CONFIG_HPP_
