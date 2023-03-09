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

#include "wanderbot/laser/laser_analyzer.hpp"

LaserCharacteristics LaserAnalyzer::determineCharacteristics(
  const double laser_angle_min, const double laser_angle_increment,
  const std::vector<float> & laser_ranges) const
{
  uint32_t straight_index = laser_ranges.size() / 2;
  uint32_t leftmost_index = laser_ranges.size() - 1;
  return LaserCharacteristics(
    laser_angle_min, laser_angle_increment, leftmost_index, straight_index);
}

Vector LaserAnalyzer::analyze(
  const LaserCharacteristics & laserCharacteristics, const std::vector<float> & laser_ranges) const
{
  int cur_range_index = 0;
  double obstacle_distance = 1000.0;
  uint32_t obstacle_index = laserCharacteristics.getStraightIndex();
  for (float this_range : laser_ranges) {
    if (this_range < obstacle_distance) {
      obstacle_distance = this_range;
      obstacle_index = cur_range_index;
    }
    cur_range_index++;
  }

  int32_t obstacle_index_rel_to_straight =
    obstacle_index - (laserCharacteristics.getLeftmostIndex() / 2 - 1);
  double obstacle_angle = laserCharacteristics.getAngleIncrement() * obstacle_index_rel_to_straight;
  return Vector::createUsingMagnitudeAngle(obstacle_distance, obstacle_angle);
}
