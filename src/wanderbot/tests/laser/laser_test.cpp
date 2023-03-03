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

// TODO probably not the best way:
#include "../test_constants.hpp"
#include "wanderbot/laser/laser_analyzer.hpp"
#include "rclcpp/rclcpp.hpp"

TEST(LaserTest, CharacteristicsTest)
{
  LaserAnalyzer laserAnalyzer;
  std::vector<float> laser_ranges;
  laser_ranges.push_back(10.0);
  laser_ranges.push_back(8.0);
  laser_ranges.push_back(2.0);
  laser_ranges.push_back(8.0);
  laser_ranges.push_back(10.0);

  LaserCharacteristics laser_characteristics = laserAnalyzer.determineCharacteristics(
    LASER_ANGLE_MINIMUM, LASER_ANGLE_INCREMENT, laser_ranges);
  EXPECT_NEAR(laser_characteristics.getAngleMin(), LASER_ANGLE_MINIMUM, 0.001);
  EXPECT_NEAR(laser_characteristics.getAngleIncrement(), LASER_ANGLE_INCREMENT, 0.001);
  EXPECT_EQ(laser_characteristics.getLeftmostIndex(), 4ul);
  EXPECT_EQ(laser_characteristics.getStraightIndex(), 2ul);
}

// TODO separate characteristics and analysis tests into separate test files

TEST(LaserTest, AnalysisStraight)
{
  LaserAnalyzer laserAnalyzer;
  std::vector<float> laser_ranges;
  for (int i = 0; i < 319; i++) {
    laser_ranges.push_back(10.0);
  }
  laser_ranges.push_back(1.5);
  for (int i = 0; i < 320; i++) {
    laser_ranges.push_back(10.0);
  }

  LaserCharacteristics laser_characteristics = laserAnalyzer.determineCharacteristics(
    LASER_ANGLE_MINIMUM, LASER_ANGLE_INCREMENT, laser_ranges);
  LaserAnalysis laser_analysis = laserAnalyzer.analyze(laser_characteristics, laser_ranges);
  EXPECT_TRUE(laser_analysis.isInSight());
  EXPECT_TRUE(laser_analysis.isNear());
  EXPECT_FALSE(laser_analysis.isTooNear());
  EXPECT_NEAR(laser_analysis.getVectorToObstacle().getAngleRadians(), 0.0l, 0.01);
  EXPECT_NEAR(laser_analysis.getVectorToObstacle().getMagnitude(), 1.5, 0.001);
}

TEST(LaserTest, AnalysisRight)
{
  LaserAnalyzer laserAnalyzer;
  std::vector<float> laser_ranges;
  laser_ranges.push_back(10.0);
  laser_ranges.push_back(10.0);
  laser_ranges.push_back(1.6);
  for (int i = 0; i < (640 - 3); i++) {
    laser_ranges.push_back(10.0);
  }

  LaserCharacteristics laser_characteristics = laserAnalyzer.determineCharacteristics(
    LASER_ANGLE_MINIMUM, LASER_ANGLE_INCREMENT, laser_ranges);
  LaserAnalysis laser_analysis = laserAnalyzer.analyze(laser_characteristics, laser_ranges);
  EXPECT_TRUE(laser_analysis.isInSight());
  EXPECT_TRUE(laser_analysis.isNear());
  EXPECT_FALSE(laser_analysis.isTooNear());
  EXPECT_TRUE(laser_analysis.isToRight());
  EXPECT_NEAR(laser_analysis.getVectorToObstacle().getMagnitude(), 1.6, 0.001);
  EXPECT_TRUE(laser_analysis.getVectorToObstacle().getAngleRadians() < -1.0l);
}

TEST(LaserTest, AnalysisTooNear)
{
  LaserAnalyzer laserAnalyzer;
  std::vector<float> laser_ranges;
  laser_ranges.push_back(3.0);
  laser_ranges.push_back(1.4);
  laser_ranges.push_back(6.0);
  laser_ranges.push_back(8.0);
  laser_ranges.push_back(10.0);

  LaserCharacteristics laser_characteristics = laserAnalyzer.determineCharacteristics(
    LASER_ANGLE_MINIMUM, LASER_ANGLE_INCREMENT, laser_ranges);
  LaserAnalysis laser_analysis = laserAnalyzer.analyze(laser_characteristics, laser_ranges);
  EXPECT_TRUE(laser_analysis.isTooNear());
  EXPECT_NEAR(laser_analysis.getVectorToObstacle().getMagnitude(), 1.4, 0.001);
}

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
