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

#ifndef WANDERBOT__TESTS__STATEHANDLER__MOCK__MOCK_OBSTACLE_AVOIDER_HPP_
#define WANDERBOT__TESTS__STATEHANDLER__MOCK__MOCK_OBSTACLE_AVOIDER_HPP_

#include "wanderbot/motion/obstacle_avoider.hpp"

// This mock returns an acute left angle to see how the go state handler deals with it
class MockObstacleAvoider : public ObstacleAvoider
{
public:
  explicit MockObstacleAvoider(const double angle_to_return)
  : angle_to_return_(angle_to_return) {}
  Vector calculateNewMotionVector(
    const Config & config, const Vector & vector_to_obstacle) const;

private:
  const double angle_to_return_;
};
#endif  // WANDERBOT__TESTS__STATEHANDLER__MOCK__MOCK_OBSTACLE_AVOIDER_HPP_
