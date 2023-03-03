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

#ifndef WANDERBOT__VELOCITY__VELOCITY_CALCULATOR_HPP_
#define WANDERBOT__VELOCITY__VELOCITY_CALCULATOR_HPP_

#include "wanderbot/laser/laser_analysis.hpp"
#include "wanderbot/laser/laser_characteristics.hpp"
#include "wanderbot/vector/vector_converter.hpp"
#include "wanderbot/velocity/velocity.hpp"
#include "wanderbot/velocity/vff/vector_force_field_calculator.hpp"

class VelocityCalculator
{
public:
  VelocityCalculator() {}
  Velocity toApproach(const LaserAnalysis & laser_analysis) const;
  Velocity toParallel(const LaserAnalysis & laser_analysis) const;

private:
  double PARALLEL_X_VELOCITY = 1.5;
  double DELTA_TO_YAW_MULTIPLIER = 0.01;
  // TODO inject these dependencies
  VectorForceFieldCalculator vectorForceFieldCalculator_;
  VectorConverter vectorConverter_;
};

#endif  // WANDERBOT__VELOCITY__VELOCITY_CALCULATOR_HPP_
