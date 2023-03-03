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
  const double seconds_in_this_state,
  const LaserCharacteristics & laser_characteristics, const VectorByMagnitudeAngle & vector_to_obstacle) const
{
  // TODO centralize tunable parameters like this:
  constexpr static double DIST_TOO_NEAR = 1.5;

  if (vector_to_obstacle.getMagnitude() < DIST_TOO_NEAR) {
    return Action(Velocity::create_reverse(), State::BLOCKED);
  }
  auto new_motion_vector_by_standard_position = vff_calculator.getVffResult(vector_to_obstacle);
  auto new_motion_vector_by_magnitude_angle =
    vector_converter.standardPositionToMagnitudeAngle(new_motion_vector_by_standard_position);
  // TODO do we need both early returns?
  if (abs(new_motion_vector_by_magnitude_angle.getAngleRadians()) >= (M_PI / 2.0l)) {
    return Action(Velocity::create_reverse(), State::BLOCKED);
  }
  // TODO centralize tuning parameters like these:
  const double SPEED_FACTOR = 0.5l;
  auto new_velocity = Velocity(
    new_motion_vector_by_magnitude_angle.getMagnitude() * SPEED_FACTOR,
    new_motion_vector_by_magnitude_angle.getAngleRadians());
  return Action(new_velocity, State::GO);
}

const char * StateHandlerGo::getName() const
{
  return "Go";
}

const State StateHandlerGo::getState() const
{
  return State::GO;
}
