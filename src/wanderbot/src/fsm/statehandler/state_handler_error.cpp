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

#include "wanderbot/fsm/statehandler/state_handler_error.hpp"

Action StateHandlerError::act(
  __attribute__((unused)) const double seconds_in_this_state,
  __attribute__((unused)) const Vector & vector_to_obstacle) const
{
  return Action(Velocity::create_stopped(), State::ERROR);
}

const char * StateHandlerError::getName() const
{
  return "Error";
}

State StateHandlerError::getState() const
{
  return State::ERROR;
}
