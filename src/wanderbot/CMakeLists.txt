# Copyright 2023 Steve Billings
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

cmake_minimum_required(VERSION 3.8)
project(wanderbot)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Debug)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(std_msgs REQUIRED)

include_directories(include)

add_executable(wanderbot
        src/ros2/wanderbot_node.cpp
        include/wanderbot/fsm/state.hpp
        src/fsm/statehandler/state_handler_go.cpp include/wanderbot/fsm/statehandler/state_handler_go.hpp
        src/fsm/statehandler/state_handler_change_direction.cpp include/wanderbot/fsm/statehandler/state_handler_change_direction.hpp
        src/fsm/statehandler/state_handler_back_up.cpp include/wanderbot/fsm/statehandler/state_handler_back_up.hpp
        src/fsm/statehandler/state_handler_error.cpp include/wanderbot/fsm/statehandler/state_handler_error.hpp
        src/velocity/vff/vector_force_field_calculator.cpp include/wanderbot/velocity/vff/vector_force_field_calculator.hpp
        src/velocity/velocity.cpp include/wanderbot/velocity/velocity.hpp
        src/linearalgebra/vector.cpp include/wanderbot/linearalgebra/vector.hpp
        src/laser/laser_analyzer.cpp include/wanderbot/laser/laser_analyzer.hpp
        src/laser/laser_characteristics.cpp include/wanderbot/laser/laser_characteristics.hpp
        include/wanderbot/fsm/statehandler/state_handler.hpp
        src/fsm/statehandler/state_handlers.cpp include/wanderbot/fsm/statehandler/state_handlers.hpp
        src/fsm/action.cpp include/wanderbot/fsm/action.hpp
        include/wanderbot/config/config.hpp src/config/config.cpp)

set(dependencies
  rclcpp
  sensor_msgs
  geometry_msgs
)

ament_target_dependencies(wanderbot ${dependencies})

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()

  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()

  set(ament_cmake_copyright_FOUND TRUE)

  find_package(ament_cmake_gtest REQUIRED)
  #find_package(ament_cmake_gmock REQUIRED)
  add_subdirectory(tests)
endif()

install(TARGETS
        wanderbot
        DESTINATION lib/${PROJECT_NAME})

ament_export_dependencies(${dependencies})
ament_package()
