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

TEST(LaserAnalysisTest, AnalysisStraight)
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
    TestConstants::LASER_ANGLE_MINIMUM, TestConstants::LASER_ANGLE_INCREMENT, laser_ranges);
  Vector vector_to_obstacle = laserAnalyzer.analyze(laser_characteristics, laser_ranges);
  EXPECT_NEAR(vector_to_obstacle.getAngleRadians(), 0.0l, 0.01);
  EXPECT_NEAR(vector_to_obstacle.getMagnitude(), 1.5, 0.001);
}

TEST(LaserAnalysisTest, AnalysisRight)
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
    TestConstants::LASER_ANGLE_MINIMUM, TestConstants::LASER_ANGLE_INCREMENT, laser_ranges);
  Vector vector_to_obstacle = laserAnalyzer.analyze(laser_characteristics, laser_ranges);
  EXPECT_NEAR(vector_to_obstacle.getMagnitude(), 1.6, 0.001);
  EXPECT_TRUE(vector_to_obstacle.getAngleRadians() < -1.0l);
}

TEST(LaserAnalysisTest, AnalysisTooNear)
{
  LaserAnalyzer laserAnalyzer;
  std::vector<float> laser_ranges;
  laser_ranges.push_back(3.0);
  laser_ranges.push_back(1.4);
  laser_ranges.push_back(6.0);
  laser_ranges.push_back(8.0);
  laser_ranges.push_back(10.0);

  LaserCharacteristics laser_characteristics = laserAnalyzer.determineCharacteristics(
    TestConstants::LASER_ANGLE_MINIMUM, TestConstants::LASER_ANGLE_INCREMENT, laser_ranges);
  Vector vector_to_obstacle = laserAnalyzer.analyze(laser_characteristics, laser_ranges);
  EXPECT_NEAR(vector_to_obstacle.getMagnitude(), 1.4, 0.001);
}

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
