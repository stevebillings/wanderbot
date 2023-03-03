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

#ifndef WANDERBOT__VELOCITY__VELOCITY_HPP_
#define WANDERBOT__VELOCITY__VELOCITY_HPP_

class Velocity
{
public:
  Velocity(double forward, double yaw);
  static Velocity create_stopped();
  static Velocity create_spin_right();
  static Velocity create_spin_left();
  static Velocity create_reverse();
  static Velocity create_reverse_left();
  static Velocity create_reverse_right();
  double get_forward() const;
  double get_yaw() const;

private:
  static constexpr double SPIN_VELOCITY_ = 3.0L;
  double forward_;
  double yaw_;
};

#endif  // WANDERBOT__VELOCITY__VELOCITY_HPP_
