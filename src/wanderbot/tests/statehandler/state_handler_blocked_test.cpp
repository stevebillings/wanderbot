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

#include <gtest/gtest.h>

#include "wanderbot/fsm/statehandler/state_handler_back_up.hpp"

TEST(StateHandlerBackUpTest, Name)
{
  StateHandlerBackUp state_handler = StateHandlerBackUp();
  EXPECT_STREQ("Back up", state_handler.getName());
}

TEST(StateHandlerBackUpTest, RecentlyBlocked)
{
  auto vector_to_obstacle = Vector::createUsingMagnitudeAngle(4.0l, 0.0l);
  StateHandlerBackUp state_handler = StateHandlerBackUp();

  Action action = state_handler.act(0.01l, vector_to_obstacle);

  EXPECT_EQ(action.get_state(), State::BACK_UP);
  EXPECT_TRUE(action.get_velocity().has_value());
  EXPECT_TRUE(action.get_velocity().value().get_forward() < 0.1);
  EXPECT_NEAR(action.get_velocity().value().get_yaw(), 0.0, 0.01);
}

TEST(StateHandlerBackUpTest, BlockedForAWhile)
{
  auto vector_to_obstacle = Vector::createUsingMagnitudeAngle(4.0l, 0.0l);
  StateHandlerBackUp state_handler = StateHandlerBackUp();

  Action action = state_handler.act(5.0l, vector_to_obstacle);

  EXPECT_EQ(action.get_state(), State::CHANGE_DIRECTION);
  EXPECT_TRUE(action.get_velocity().has_value());
  EXPECT_NEAR(action.get_velocity().value().get_forward(), 0.0, 0.0);
  EXPECT_NEAR(action.get_velocity().value().get_yaw(), 0.0, 0.01);
}

int main(int argc, char ** argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
