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

#include "wanderbot/fsm/statehandler/state_handler_change_direction.hpp"

Action StateHandlerChangeDirection::act(
  const double seconds_in_this_state,
  __attribute__((unused)) const Vector & vector_to_obstacle) const
{
  if (seconds_in_this_state > Config::SPIN_SECONDS) {
    return Action(Velocity::create_stopped(), State::GO);
  }
  return Action(Velocity::create_spin_left(), State::CHANGE_DIRECTION);
}

const char * StateHandlerChangeDirection::getName() const
{
  return "Change direction";
}

State StateHandlerChangeDirection::getState() const
{
  return State::CHANGE_DIRECTION;
}
