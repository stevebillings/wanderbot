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

//
// Created by stevebillings on 12/4/22.
//

#include "wanderbot/laser/laser_characteristics.hpp"

double LaserCharacteristics::getAngleMin() const {return angle_min_;}

double LaserCharacteristics::getAngleIncrement() const {return angle_increment_;}

uint32_t LaserCharacteristics::getLeftmostIndex() const {return leftmost_index_;}

uint32_t LaserCharacteristics::getStraightIndex() const {return straight_index_;}
