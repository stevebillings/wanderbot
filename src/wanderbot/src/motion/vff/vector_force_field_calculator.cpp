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

#include "wanderbot/motion/vff/vector_force_field_calculator.hpp"

Vector VectorForceFieldCalculator::calculateNewMotionVector(
  const Config & config, const Vector & vector_to_obstacle) const
{
  auto goal_vector = Vector::createUsingMagnitudeAngle(3.0, 0.0L);
  double repulsive_vector_endpoint_x = 0.0L;
  double repulsive_vector_endpoint_y = 0.0L;

  if (vector_to_obstacle.getMagnitude() < config.getVffMinimumIgnorableDistance()) {
    float obstacle_opposite_angle = vector_to_obstacle.getAngleRadians() + M_PI;
    float repulsive_vector_magnitude =
      config.getVffMinimumIgnorableDistance() - vector_to_obstacle.getMagnitude();
    // Calculate cartesian (x, y) components from polar (angle, distance)
    repulsive_vector_endpoint_x = cos(obstacle_opposite_angle) * repulsive_vector_magnitude;
    repulsive_vector_endpoint_y = sin(obstacle_opposite_angle) * repulsive_vector_magnitude;
  }
  // Add the repulsive vector to the goal vector to get the result vector (path to avoid obstacle)
  double result_endpoint_x = repulsive_vector_endpoint_x + goal_vector.getStandardPositionX();
  double result_endpoint_y = repulsive_vector_endpoint_y + goal_vector.getStandardPositionY();
  return Vector::createUsingStandardPosition(result_endpoint_x, result_endpoint_y);
}
