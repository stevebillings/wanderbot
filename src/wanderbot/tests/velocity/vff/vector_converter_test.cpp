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

#include "wanderbot/vector/vector_converter.hpp"

#include <gtest/gtest.h>

TEST(VectorConverter, Ahead)
{
  auto vc = VectorConverter();
  auto vsp = VectorByStandardPosition(1.0, 0.0);
  auto vma = vc.standardPositionToMagnitudeAngle(vsp);

  ASSERT_NEAR(vma.getAngleRadians(), 0.0, 0.001);
  ASSERT_NEAR(vma.getMagnitude(), 1.0, 0.001);
}

TEST(VectorConverter, Left)
{
  auto vc = VectorConverter();
  auto vsp = VectorByStandardPosition(0.0, 1.0);
  auto vma = vc.standardPositionToMagnitudeAngle(vsp);

  ASSERT_NEAR(vma.getAngleRadians(), M_PI / 2.0, 0.01);
  ASSERT_NEAR(vma.getMagnitude(), 1.0, 0.001);
}

TEST(VectorConverter, Right45)
{
  auto vc = VectorConverter();
  auto vsp = VectorByStandardPosition(1.0, -1.0);
  auto vma = vc.standardPositionToMagnitudeAngle(vsp);

  ASSERT_NEAR(vma.getAngleRadians(), -1 * M_PI / 4.0, 0.01);
  ASSERT_NEAR(vma.getMagnitude(), sqrt(2.0), 0.001);
}

int main(int argc, char ** argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
