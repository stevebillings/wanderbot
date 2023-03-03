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

#ifndef WANDERBOT__VECTOR__VECTOR_CONVERTER_HPP_
#define WANDERBOT__VECTOR__VECTOR_CONVERTER_HPP_

#include <cmath>
#include <vector>

#include "vector_by_magnitude_angle.hpp"
#include "vector_by_standard_position.hpp"

class VectorConverter
{
public:
  VectorByMagnitudeAngle standardPositionToMagnitudeAngle(
    const VectorByStandardPosition & vectorByStandardPosition) const;
};

#endif  // WANDERBOT__VECTOR__VECTOR_CONVERTER_HPP_