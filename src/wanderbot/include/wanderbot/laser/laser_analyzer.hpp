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

#ifndef WANDERBOT__LASER__LASER_ANALYZER_HPP_
#define WANDERBOT__LASER__LASER_ANALYZER_HPP_

#include <vector>

#include "laser_analysis.hpp"
#include "laser_characteristics.hpp"

class LaserAnalyzer
{
public:
  LaserCharacteristics determineCharacteristics(
    const double laser_angle_min, const double laser_angle_increment,
    const std::vector<float> & laser_ranges) const;
  LaserAnalysis analyze(
    const LaserCharacteristics & laserCharacteristics,
    const std::vector<float> & laser_ranges) const;

private:
  // TODO: consolidate tuning parameters like these:
  constexpr static double DIST_WITHIN_SIGHT = 9.5;
  constexpr static double DIST_NEAR = 4.0;
  constexpr static double DIST_TOO_NEAR = 1.5;
};

#endif  // WANDERBOT__LASER__LASER_ANALYZER_HPP_
