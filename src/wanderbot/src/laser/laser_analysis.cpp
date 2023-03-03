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

//
// Created by stevebillings on 11/21/22.
//

#include "wanderbot/laser/laser_analysis.hpp"

bool LaserAnalysis::isInSight() const {return in_sight_;}

bool LaserAnalysis::isNear() const {return near_;}

bool LaserAnalysis::isTooNear() const {return too_near_;}

VectorByMagnitudeAngle LaserAnalysis::getVectorToObstacle() const
{
  return vector_to_obstacle_;
}


bool LaserAnalysis::isToRight() const {return getVectorToObstacle().getAngleRadians() < 0.0l;}

std::string LaserAnalysis::toString() const
{
  std::string description = "";

  description.append("in sight?: ");
  description.append(std::to_string(in_sight_));

  description.append("; too near?: ");
  description.append(std::to_string(too_near_));

  description.append("; vector to obstacle: ");
  description.append(getVectorToObstacle().toString());

  description.append("; to right?: ");
  description.append(std::to_string(isToRight()));

  return description;
}
