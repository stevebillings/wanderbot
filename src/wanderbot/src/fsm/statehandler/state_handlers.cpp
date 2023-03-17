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

#include "wanderbot/fsm/statehandler/state_handlers.hpp"

StateHandlers::StateHandlers()
{
  obstacle_avoider_ = new VectorForceFieldCalculator();
  state_handler_just_go_ = new StateHandlerGo(obstacle_avoider_);
  state_handler_change_direction_ = new StateHandlerChangeDirection();
  state_handler_too_near_ = new StateHandlerBackUp();
  state_handler_error_ = new StateHandlerError();
}

StateHandler * StateHandlers::get_state_handler(State state) const
{
  switch (state) {
    case State::GO:
      return state_handler_just_go_;
    case State::CHANGE_DIRECTION:
      return state_handler_change_direction_;
    case State::BACK_UP:
      return state_handler_too_near_;
    default:
      return state_handler_error_;
  }
}

StateHandlers::~StateHandlers()
{
  delete state_handler_just_go_;
  delete state_handler_change_direction_;
  delete state_handler_too_near_;
  delete state_handler_error_;
  delete obstacle_avoider_;
}
