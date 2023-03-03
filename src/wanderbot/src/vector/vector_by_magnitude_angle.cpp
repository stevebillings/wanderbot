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

#include "wanderbot/vector/vector_by_magnitude_angle.hpp"

double VectorByMagnitudeAngle::getMagnitude() const {return magnitude_;}

double VectorByMagnitudeAngle::getAngleRadians() const {return angle_radians_;}

std::string VectorByMagnitudeAngle::toString() const
{
  std::string description = "";

  description.append("distance: ");
  description.append(std::to_string(getMagnitude()));

  description.append("; angle (radians): ");
  description.append(std::to_string(getAngleRadians()));

  return description;
}
