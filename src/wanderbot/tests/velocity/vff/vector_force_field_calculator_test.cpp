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

#include "wanderbot/velocity/vff/vector_force_field_calculator.hpp"

#include <gtest/gtest.h>

TEST(VectorForceField, Far)
{
  auto vff = VectorForceFieldCalculator();
  auto vector_to_obstacle = Vector::createUsingMagnituredAngle(10.0l, 0.0l);
  Vector result = vff.getVffResult(vector_to_obstacle);

  ASSERT_TRUE(result.getMagnitude() > 2.0l);
  ASSERT_NEAR(result.getAngleRadians(), 0.0, 0.001);
}

TEST(VectorForceField, AheadClose)
{
  auto vff = VectorForceFieldCalculator();
  auto vector_to_obstacle = Vector::createUsingMagnituredAngle(3.0l, 0.0l);
  Vector result = vff.getVffResult(vector_to_obstacle);

  ASSERT_NEAR(result.getMagnitude(), 0.1, 0.1);
}

TEST(VectorForceField, LeftVeryClose)
{
  auto vff = VectorForceFieldCalculator();
  auto vector_to_obstacle = Vector::createUsingMagnituredAngle(0.1l, M_PI / 4.0);
  Vector result = vff.getVffResult(vector_to_obstacle);

  // Obstacle should be pushing us back and to the right
  ASSERT_TRUE(result.getAngleRadians() < 0.0);
  ASSERT_TRUE(result.getAngleRadians() > -1 * M_PI);
}

int main(int argc, char ** argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
