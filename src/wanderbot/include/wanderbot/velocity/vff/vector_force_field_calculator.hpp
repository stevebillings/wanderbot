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

#ifndef WANDERBOT__VELOCITY__VFF__VECTOR_FORCE_FIELD_CALCULATOR_HPP_
#define WANDERBOT__VELOCITY__VFF__VECTOR_FORCE_FIELD_CALCULATOR_HPP_

#include "wanderbot/config/config.hpp"
#include <algorithm>
#include <cmath>
#include <vector>

#include "wanderbot/linearalgebra/vector.hpp"

class VectorForceFieldCalculator
{
public:
  Vector getVffResult(const Vector & vector_to_obstacle, const Vector & goal_vector) const;
  Vector getVffResult(const Vector & vector_to_obstacle) const;
};

#endif  // WANDERBOT__VELOCITY__VFF__VECTOR_FORCE_FIELD_CALCULATOR_HPP_
