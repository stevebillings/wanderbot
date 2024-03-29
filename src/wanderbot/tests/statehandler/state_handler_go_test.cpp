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

#include "mock/mock_obstacle_avoider.hpp"
#include "wanderbot/motion/vff/vector_force_field_calculator.hpp"

TEST(StateHandlerGoTest, StraightAhead)
{
  Vector vector_to_obstacle = Vector::createUsingMagnitudeAngle(5.0l, 0.0l);
  StateHandlerGo state_handler = StateHandlerGo(new VectorForceFieldCalculator());

  Action action = state_handler.act(Config(), 10.0l, vector_to_obstacle);

  EXPECT_EQ(action.get_state(), State::GO);
  // Ensure the values are reasonable without being overly sensitive to magnitude
  EXPECT_TRUE(action.get_velocity().has_value());
  EXPECT_TRUE(action.get_velocity().value().get_forward() > 0.5l);
  EXPECT_NEAR(action.get_velocity().value().get_yaw(), 0.0, 0.01l);
}

TEST(StateHandlerGoTest, Blocked)
{
  Vector vector_to_obstacle = Vector::createUsingMagnitudeAngle(0.5l, 0.0l);
  StateHandlerGo state_handler = StateHandlerGo(new VectorForceFieldCalculator());

  Action action = state_handler.act(Config(), 10.0l, vector_to_obstacle);

  EXPECT_EQ(action.get_state(), State::BACK_UP);
  // Ensure the values are reasonable without being overly sensitive to magnitude
  EXPECT_TRUE(action.get_velocity().has_value());
  EXPECT_NEAR(action.get_velocity().value().get_forward(), 0.0, 0.0);
  EXPECT_NEAR(action.get_velocity().value().get_yaw(), 0.0, 0.01);
}

TEST(StateHandlerGoTest, AheadRight)
{
  Vector vector_to_obstacle = Vector::createUsingMagnitudeAngle(2.0l, -1 * M_PI / 4.0);
  StateHandlerGo state_handler = StateHandlerGo(new VectorForceFieldCalculator());

  Action action = state_handler.act(Config(), 10.0l, vector_to_obstacle);

  EXPECT_EQ(action.get_state(), State::GO);
  // Ensure the values are reasonable without being overly sensitive to magnitude
  EXPECT_TRUE(action.get_velocity().has_value());
  EXPECT_TRUE(action.get_velocity().value().get_forward() > 0.5l);
  EXPECT_TRUE(action.get_velocity().value().get_forward() < 8.0l);
  EXPECT_TRUE(action.get_velocity().value().get_yaw() > 0.2l);
}

TEST(StateHandlerGoTest, InvalidAngleLeft)
{
  Vector vector_to_obstacle = Vector::createUsingMagnitudeAngle(2.0l, -1 * M_PI / 4.0);
  StateHandlerGo state_handler = StateHandlerGo(new MockObstacleAvoider(M_PI));

  Action action = state_handler.act(Config(), 10.0l, vector_to_obstacle);

  EXPECT_EQ(action.get_state(), State::BACK_UP);
}

TEST(StateHandlerGoTest, InvalidAngleRight)
{
  Vector vector_to_obstacle = Vector::createUsingMagnitudeAngle(2.0l, -1 * M_PI / 4.0);
  StateHandlerGo state_handler = StateHandlerGo(new MockObstacleAvoider(-1.0 * M_PI));

  Action action = state_handler.act(Config(), 10.0l, vector_to_obstacle);

  EXPECT_EQ(action.get_state(), State::BACK_UP);
}

int main(int argc, char ** argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
