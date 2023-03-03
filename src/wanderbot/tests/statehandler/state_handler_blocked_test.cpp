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

#include "wanderbot/fsm/statehandler/state_handler_blocked.hpp"

#include <gtest/gtest.h>

#include "../test_constants.hpp"

TEST(StateHandlerBlockedTest, Name)
{
  StateHandlerBlocked state_handler = StateHandlerBlocked();
  EXPECT_STREQ("Blocked", state_handler.name());
}

TEST(StateHandlerBlockedTest, RecentlyBlocked)
{
  LaserCharacteristics laser_characteristics =
    LaserCharacteristics(LASER_ANGLE_MINIMUM, LASER_ANGLE_INCREMENT, 4ul, 2ul);
  auto vector_to_obstacle = VectorByMagnitudeAngle(4.0l, 0.0l);
  LaserAnalysis laser_analysis = LaserAnalysis(true, false, false, vector_to_obstacle);
  StateHandlerBlocked state_handler = StateHandlerBlocked();

  Action action = state_handler.act(0.01l, laser_characteristics, laser_analysis);

  EXPECT_EQ(action.get_state(), State::BLOCKED);
  // Ensure the values are reasonable without being overly sensitive to magnitude
  EXPECT_FALSE(action.get_velocity().has_value());
}

TEST(StateHandlerBlockedTest, BlockedForAWhile)
{
  LaserCharacteristics laser_characteristics =
    LaserCharacteristics(LASER_ANGLE_MINIMUM, LASER_ANGLE_INCREMENT, 4ul, 2ul);
  auto vector_to_obstacle = VectorByMagnitudeAngle(4.0l, 0.0l);
  LaserAnalysis laser_analysis = LaserAnalysis(true, false, false, vector_to_obstacle);
  StateHandlerBlocked state_handler = StateHandlerBlocked();

  Action action = state_handler.act(5.0l, laser_characteristics, laser_analysis);

  EXPECT_EQ(action.get_state(), State::CHANGE_DIRECTION);
  // Ensure the values are reasonable without being overly sensitive to magnitude
  EXPECT_TRUE(action.get_velocity().has_value());
  EXPECT_NEAR(action.get_velocity().value().get_yaw(), 3.0l, 0.001L);
  EXPECT_NEAR(action.get_velocity().value().get_forward(), 0.0l, 0.001L);
}

int main(int argc, char ** argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
