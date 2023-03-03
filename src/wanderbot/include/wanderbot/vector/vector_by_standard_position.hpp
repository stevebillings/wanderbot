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

#ifndef WANDERBOT__VECTOR__VECTOR_BY_STANDARD_POSITION_HPP_
#define WANDERBOT__VECTOR__VECTOR_BY_STANDARD_POSITION_HPP_

class VectorByStandardPosition
{
public:
  VectorByStandardPosition(double endpoint_x, double endpoint_y)
  : endpoint_x_(endpoint_x), endpoint_y_(endpoint_y)
  {
  }
  double getEndpointX() const;
  double getEndpointY() const;

private:
  double endpoint_x_;
  double endpoint_y_;
};

#endif  // WANDERBOT__VECTOR__VECTOR_BY_STANDARD_POSITION_HPP_
