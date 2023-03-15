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

#include "wanderbot/config/config.hpp"

double Config::getVffMinimumIgnorableDistance() const {return VFF_MINIMUM_IGNORABLE_DISTANCE_;}
double Config::getObstacleMinimumSafeDistance() const {return OBSTACLE_MINIMUM_SAFE_DISTANCE_;}
double Config::getThrottleSettingForward() const {return THROTTLE_SETTING_FORWARD_;}
double Config::getThrottleSettingYaw() const {return THROTTLE_SETTING_YAW_;}
double Config::getMaxForwardVelocity() const {return MAX_FORWARD_VELOCITY_;}
double Config::getMaxYaw() const {return MAX_YAW_;}
double Config::getBackUpVelocity() const {return BACK_UP_VELOCITY_;}
double Config::getChangeDirectionSpinVelocity() const {return CHANGE_DIRECTION_SPIN_VELOCITY_;}
double Config::getBackUpDurationSeconds() const {return BACK_UP_SECONDS_;}
double Config::getSpinDurationSeconds() const {return SPIN_SECONDS_;}

const double Config::VFF_MINIMUM_IGNORABLE_DISTANCE_ = 6.0;
const double Config::OBSTACLE_MINIMUM_SAFE_DISTANCE_ = 1.5;
const double Config::THROTTLE_SETTING_FORWARD_ = 0.55;
const double Config::THROTTLE_SETTING_YAW_ = 1.0;
const double Config::MAX_FORWARD_VELOCITY_ = 5.0;
const double Config::MAX_YAW_ = M_PI;
const double Config::BACK_UP_VELOCITY_ = -1.0;
const double Config::CHANGE_DIRECTION_SPIN_VELOCITY_ = 3.0;
const double Config::BACK_UP_SECONDS_ = 1.0;
const double Config::SPIN_SECONDS_ = 0.75;
