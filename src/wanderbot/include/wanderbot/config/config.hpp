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

#ifndef WANDERBOT__CONFIG__CONFIG_HPP_
#define WANDERBOT__CONFIG__CONFIG_HPP_

class Config
{
public:
  static constexpr double VFF_MINIMUM_IGNORABLE_DISTANCE = 6.0;
  static constexpr double OBSTACLE_MINIMUM_SAFE_DISTANCE = 1.5;
  static constexpr double THROTTLE_SETTING = 0.5;
  static constexpr double BACK_UP_SECONDS = 1.0;
  static constexpr double SPIN_SECONDS = 0.75;
};

#endif  // WANDERBOT__CONFIG__CONFIG_HPP_
