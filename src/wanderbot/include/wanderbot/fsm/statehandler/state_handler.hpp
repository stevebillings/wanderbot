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

#include "wanderbot/action.hpp"
#include "wanderbot/fsm/state.hpp"
#include "wanderbot/laser/laser_analysis.hpp"
#include "wanderbot/laser/laser_characteristics.hpp"
#include "wanderbot/velocity/velocity_calculator.hpp"

// the virtual class for State
// Each concrete state object implement the act() method for a specific state
class StateHandler
{
public:
  // TODO: rename to getName
  virtual const char * name() const = 0;
  virtual const State getState() const = 0;
  virtual Action act(
    const double seconds_in_this_state,
    const LaserCharacteristics & laser_characteristics,
    const LaserAnalysis & laser_analysis) const = 0;
  virtual ~StateHandler() = default;

protected:
  // TODO rethink this:
  const VelocityCalculator & getVelocityCalculator() const {return velocity_calculator_;}

private:
  // TODO: inject this dependency (require subclass to provide the dep via a virtual getter;
  //  inject dep into each subclass)
  // TODO: check for this same error elsewhere
  VelocityCalculator velocity_calculator_ = VelocityCalculator();
};

#endif  // WANDERBOT__FSM__STATEHANDLER__STATE_HANDLER_HPP_
