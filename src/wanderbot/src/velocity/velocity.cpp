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

#include "wanderbot/velocity/velocity.hpp"

Velocity::Velocity(double forward, double yaw)
{
  forward_ = forward;
  yaw_ = yaw;
}

Velocity Velocity::create_stopped() {return Velocity(0.0, 0.0);}

Velocity Velocity::create_spin_left() {return Velocity(0.0, SPIN_VELOCITY_);}

Velocity Velocity::create_reverse() {return Velocity(-1.0, 0.0);}

double Velocity::get_forward() const {return forward_;}

double Velocity::get_yaw() const {return yaw_;}
