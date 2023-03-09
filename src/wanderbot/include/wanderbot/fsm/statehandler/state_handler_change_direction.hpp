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

#ifndef WANDERBOT__FSM__STATEHANDLER__STATE_HANDLER_CHANGE_DIRECTION_HPP_
#define WANDERBOT__FSM__STATEHANDLER__STATE_HANDLER_CHANGE_DIRECTION_HPP_

#include "state_handler.hpp"

class StateHandlerChangeDirection : public StateHandler
{
public:
  Action act(
    const double seconds_in_this_state,
    const Vector & vector_to_obstacle) const override;
  const char * getName() const override;
  State getState() const override;
};

#endif  // WANDERBOT__FSM__STATEHANDLER__STATE_HANDLER_CHANGE_DIRECTION_HPP_
