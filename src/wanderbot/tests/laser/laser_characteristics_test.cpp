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

#include "../test_constants.hpp"
#include "rclcpp/rclcpp.hpp"
#include "wanderbot/laser/laser_analyzer.hpp"

TEST(LaserCharacteristicsTest, CharacteristicsTest)
{
  LaserAnalyzer laserAnalyzer;
  std::vector<float> laser_ranges;
  laser_ranges.push_back(10.0);
  laser_ranges.push_back(8.0);
  laser_ranges.push_back(2.0);
  laser_ranges.push_back(8.0);
  laser_ranges.push_back(10.0);

  LaserCharacteristics laser_characteristics = laserAnalyzer.determineCharacteristics(
    TestConstants::LASER_ANGLE_MINIMUM, TestConstants::LASER_ANGLE_INCREMENT, laser_ranges);
  EXPECT_NEAR(laser_characteristics.getAngleMin(), TestConstants::LASER_ANGLE_MINIMUM, 0.001);
  EXPECT_NEAR(
    laser_characteristics.getAngleIncrement(), TestConstants::LASER_ANGLE_INCREMENT, 0.001);
  EXPECT_EQ(laser_characteristics.getLeftmostIndex(), 4ul);
  EXPECT_EQ(laser_characteristics.getStraightIndex(), 2ul);
}

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
