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

#ifndef WANDERBOT__FSM__STATEHANDLER__STATE_HANDLER_HPP_
#define WANDERBOT__FSM__STATEHANDLER__STATE_HANDLER_HPP_

#include "wanderbot/fsm/action.hpp"
#include "wanderbot/fsm/state.hpp"
#include "wanderbot/laser/laser_characteristics.hpp"
#include "wanderbot/vector/vector_by_magnitude_angle.hpp"

// the virtual class for State
// Each concrete state object implement the act() method for a specific state
class StateHandler
{
public:
  virtual const char * getName() const = 0;
  virtual const State getState() const = 0;
  virtual Action act(
    const double seconds_in_this_state,
    const LaserCharacteristics & laser_characteristics,
    const VectorByMagnitudeAngle & vector_to_obstacle) const = 0;
  virtual ~StateHandler() = default;
};

#endif  // WANDERBOT__FSM__STATEHANDLER__STATE_HANDLER_HPP_
