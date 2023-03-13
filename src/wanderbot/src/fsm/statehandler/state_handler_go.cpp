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

#include "wanderbot/fsm/statehandler/state_handler_go.hpp"

Action StateHandlerGo::act(
  const Config & config, __attribute__((unused)) const double seconds_in_this_state,
  const Vector & vector_to_obstacle) const
{
  if (vector_to_obstacle.getMagnitude() < config.getObstacleMinimumSafeDistance()) {
    return Action(Velocity::create_stopped(), State::BACK_UP);
  }
  auto new_motion_vector = obstacle_avoider_->calculateNewMotionVector(config, vector_to_obstacle);
  if (fabs(new_motion_vector.getAngleRadians()) >= (M_PI / 2.0L)) {
    return Action(Velocity::create_stopped(), State::BACK_UP);
  }
  auto new_velocity = Velocity(
    new_motion_vector.getMagnitude() * config.getThrottleSettingForward(),
    new_motion_vector.getAngleRadians() * config.getThrottleSettingYaw());
  return Action(new_velocity, State::GO);
}

const char * StateHandlerGo::getName() const {return "Go";}

State StateHandlerGo::getState() const {return State::GO;}
