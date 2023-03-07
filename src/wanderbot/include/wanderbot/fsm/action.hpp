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

#ifndef WANDERBOT__ACTION_HPP_
#define WANDERBOT__ACTION_HPP_

#include <optional>

#include "state.hpp"
#include "wanderbot/velocity/velocity.hpp"

class Action
{
public:
  Action(const Velocity & velocity, const State state)
  : velocity_(velocity), state_(state) {}
  explicit Action(const State state)
  : velocity_(std::nullopt), state_(state) {}
  std::optional<Velocity> get_velocity() const;
  State get_state() const;

private:
  std::optional<Velocity> velocity_;
  State state_;
};

#endif  // WANDERBOT__ACTION_HPP_
