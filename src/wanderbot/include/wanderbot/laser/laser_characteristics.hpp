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

#ifndef WANDERBOT__LASER__LASER_CHARACTERISTICS_HPP_
#define WANDERBOT__LASER__LASER_CHARACTERISTICS_HPP_

#include <cstdint>

class LaserCharacteristics
{
public:
  // TODO this needs laser_angle_min + laser_angle_increment
  LaserCharacteristics(
    const double angle_min, const double angle_increment, const uint32_t leftmost_index,
    const uint32_t straight_index)
  : angle_min_(angle_min),
    angle_increment_(angle_increment),
    leftmost_index_(leftmost_index),
    straight_index_(straight_index)
  {
  }
  LaserCharacteristics(const LaserCharacteristics & other)
  : angle_min_(other.angle_min_),
    angle_increment_(other.angle_increment_),
    leftmost_index_(other.leftmost_index_),
    straight_index_(other.straight_index_)
  {
  }
  double getAngleMin() const;
  double getAngleIncrement() const;
  uint32_t getLeftmostIndex() const;
  uint32_t getStraightIndex() const;

private:
  double angle_min_;
  double angle_increment_;
  uint32_t leftmost_index_;
  uint32_t straight_index_;
};

#endif  // WANDERBOT__LASER__LASER_CHARACTERISTICS_HPP_
