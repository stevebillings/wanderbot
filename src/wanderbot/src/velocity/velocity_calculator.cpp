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

#include "wanderbot/velocity/velocity_calculator.hpp"

Velocity VelocityCalculator::toApproach(const LaserAnalysis & laser_analysis) const
{
  // TODO centralize tuning parameters like these:
  const double VELOCITY_FACTOR = 0.2L;
  if (laser_analysis.isNear() || laser_analysis.isTooNear()) {
    return Velocity(0.0, 0.0);
  }
  double x = laser_analysis.getVectorToObstacle().getMagnitude() * VELOCITY_FACTOR;
  double yaw = laser_analysis.getVectorToObstacle().getAngleRadians();
  return Velocity(x, yaw);
}
Velocity VelocityCalculator::toParallel(const LaserAnalysis & laser_analysis) const
{
  double yaw;
  if (laser_analysis.isInSight()) {
    // TODO this const seems kinda arbitrary
    yaw = laser_analysis.getVectorToObstacle().getAngleRadians() + 0.4 * M_PI;
  }
  return Velocity(PARALLEL_X_VELOCITY, yaw);
}
