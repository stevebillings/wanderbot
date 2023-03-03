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
  auto vector_to_obstacle = VectorByMagnitudeAngle(10.0l, 0.0l);
  VectorByStandardPosition result = vff.getVffResult(vector_to_obstacle);

  ASSERT_TRUE(result.getEndpointX() > 2.0l);
  ASSERT_NEAR(result.getEndpointY(), 0.0, 0.001);
}

TEST(VectorForceField, AheadClose)
{
  auto vff = VectorForceFieldCalculator();
  auto vector_to_obstacle = VectorByMagnitudeAngle(3.0l, 0.0l);
  VectorByStandardPosition result = vff.getVffResult(vector_to_obstacle);

  ASSERT_NEAR(result.getEndpointX(), 0.1, 0.1);
}

TEST(VectorForceField, RightClose)
{
  auto vff = VectorForceFieldCalculator();
  auto vector_to_obstacle = VectorByMagnitudeAngle(0.1l, M_PI / 4.0);
  VectorByStandardPosition result = vff.getVffResult(vector_to_obstacle);

  ASSERT_TRUE(result.getEndpointY() < 1.0);
}

int main(int argc, char ** argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
