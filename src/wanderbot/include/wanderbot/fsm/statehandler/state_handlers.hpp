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

#ifndef WANDERBOT__FSM__STATEHANDLER__STATE_HANDLERS_HPP_
#define WANDERBOT__FSM__STATEHANDLER__STATE_HANDLERS_HPP_

#include "state_handler.hpp"
#include "state_handler_back_up.hpp"
#include "state_handler_change_direction.hpp"
#include "state_handler_error.hpp"
#include "state_handler_go.hpp"
#include "wanderbot/motion/vff/vector_force_field_calculator.hpp"

// This class constructs and holds all state objects,
// and has a method that returns the state object for a given
// fsm_state enum value (state objects must be stateless).
// State handler objects 
class StateHandlers
{
public:
  StateHandler * get_state_handler(State state) const;
  StateHandlers();
  ~StateHandlers();

private:
  ObstacleAvoider * obstacle_avoider_;
  StateHandler * state_handler_just_go_;
  StateHandler * state_handler_change_direction_;
  StateHandler * state_handler_too_near_;
  StateHandler * state_handler_error_;
};

#endif  // WANDERBOT__FSM__STATEHANDLER__STATE_HANDLERS_HPP_
