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

#ifndef WANDERBOT__LINEARALGEBRA__VECTOR_HPP_
#define WANDERBOT__LINEARALGEBRA__VECTOR_HPP_

#include <cmath>
#include <string>

class Vector
{
public:
  static Vector createUsingStandardPosition(double x, double y);
  static Vector createUsingMagnitudeAngle(double magnitude, double angle_radians);
  double getMagnitude() const;
  double getAngleRadians() const;
  double getStandardPositionX() const;
  double getStandardPositionY() const;
  std::string toString() const;

private:
  Vector(double magnitude, double angle_radians)
  : magnitude_(magnitude), angle_radians_(angle_radians)
  {
  }
  double magnitude_;
  double angle_radians_;
};

#endif  // WANDERBOT__LINEARALGEBRA__VECTOR_HPP_
