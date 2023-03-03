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

#ifndef WANDERBOT__LASER__LASER_ANALYSIS_HPP_
#define WANDERBOT__LASER__LASER_ANALYSIS_HPP_

#include <string>
#include <vector>

#include "wanderbot/vector/vector_by_magnitude_angle.hpp"

class LaserAnalysis
{
public:
  LaserAnalysis(
    const bool in_sight, const bool near, const bool too_near,
    const VectorByMagnitudeAngle vector_to_obstacle)
  : in_sight_(in_sight),
    near_(near),
    too_near_(too_near),
    vector_to_obstacle_(vector_to_obstacle)
  {
  }
  LaserAnalysis(const LaserAnalysis & src)
  : in_sight_(src.isInSight()),
    near_(src.isNear()),
    too_near_(src.isTooNear()),
    vector_to_obstacle_(src.getVectorToObstacle())
  {
  }
  bool isInSight() const;
  // TODO Remove near and maybe toRight
  bool isNear() const;
  bool isTooNear() const;
  VectorByMagnitudeAngle getVectorToObstacle() const;
  bool isToRight() const;
  std::string toString() const;

private:
  const bool in_sight_;
  const bool near_;
  const bool too_near_;
  const VectorByMagnitudeAngle vector_to_obstacle_;
};

#endif  // WANDERBOT__LASER__LASER_ANALYSIS_HPP_
