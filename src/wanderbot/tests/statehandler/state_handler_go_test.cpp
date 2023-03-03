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

#include "wanderbot/fsm/statehandler/state_handler_go.hpp"

#include <gtest/gtest.h>

#include "../test_constants.hpp"

TEST(StateHandlerGoTest, StraightAhead)
{
  LaserCharacteristics laser_characteristics =
    LaserCharacteristics(LASER_ANGLE_MINIMUM, LASER_ANGLE_INCREMENT, 4ul, 2ul);
  VectorByMagnitudeAngle vector_to_obstacle = VectorByMagnitudeAngle(5.0l, 0.0l);
  LaserAnalysis laser_analysis = LaserAnalysis(true, false, false, vector_to_obstacle);
  StateHandlerGo state_handler = StateHandlerGo();

  Action action = state_handler.act(10.0l, laser_characteristics, laser_analysis);

  EXPECT_EQ(action.get_state(), State::GO);
  // Ensure the values are reasonable without being overly sensitive to magnitude
  EXPECT_TRUE(action.get_velocity().has_value());
  EXPECT_TRUE(action.get_velocity().value().get_forward() > 0.5l);
  EXPECT_NEAR(action.get_velocity().value().get_yaw(), 0.0, 0.01l);
}

TEST(StateHandlerGoTest, Blocked)
{
  LaserCharacteristics laser_characteristics =
    LaserCharacteristics(LASER_ANGLE_MINIMUM, LASER_ANGLE_INCREMENT, 4ul, 2ul);
  VectorByMagnitudeAngle vector_to_obstacle = VectorByMagnitudeAngle(0.5l, 0.0l);
  LaserAnalysis laser_analysis = LaserAnalysis(true, false, false, vector_to_obstacle);
  StateHandlerGo state_handler = StateHandlerGo();

  Action action = state_handler.act(10.0l, laser_characteristics, laser_analysis);

  EXPECT_EQ(action.get_state(), State::BLOCKED);
  // Ensure the values are reasonable without being overly sensitive to magnitude
  EXPECT_TRUE(action.get_velocity().has_value());
  EXPECT_TRUE(action.get_velocity().value().get_forward() < 0.0l);
  EXPECT_NEAR(action.get_velocity().value().get_yaw(), 0.0, 0.01l);
}

TEST(StateHandlerGoTest, AheadRight)
{
  LaserCharacteristics laser_characteristics =
    LaserCharacteristics(LASER_ANGLE_MINIMUM, LASER_ANGLE_INCREMENT, 4ul, 2ul);
  VectorByMagnitudeAngle vector_to_obstacle = VectorByMagnitudeAngle(2.0l, -1 * M_PI / 4.0);
  LaserAnalysis laser_analysis = LaserAnalysis(true, false, false, vector_to_obstacle);
  StateHandlerGo state_handler = StateHandlerGo();

  Action action = state_handler.act(10.0l, laser_characteristics, laser_analysis);

  EXPECT_EQ(action.get_state(), State::GO);
  // Ensure the values are reasonable without being overly sensitive to magnitude
  EXPECT_TRUE(action.get_velocity().has_value());
  EXPECT_TRUE(action.get_velocity().value().get_forward() > 0.5l);
  EXPECT_TRUE(action.get_velocity().value().get_forward() < 8.0l);
  EXPECT_TRUE(action.get_velocity().value().get_yaw() > 0.2l);
}

int main(int argc, char ** argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}