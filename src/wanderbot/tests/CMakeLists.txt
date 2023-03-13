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

ament_add_gtest(laser_analysis_test
        laser/laser_analysis_test.cpp
        test_constants.hpp
        ../include/wanderbot/laser/laser_analyzer.hpp ../src/laser/laser_analyzer.cpp
        ../include/wanderbot/laser/laser_characteristics.hpp ../src/laser/laser_characteristics.cpp
        ../include/wanderbot/linearalgebra/vector.hpp ../src/linearalgebra/vector.cpp)

ament_add_gtest(laser_characteristics_test
        laser/laser_characteristics_test.cpp
        test_constants.hpp
        ../include/wanderbot/laser/laser_analyzer.hpp ../src/laser/laser_analyzer.cpp
        ../include/wanderbot/laser/laser_characteristics.hpp ../src/laser/laser_characteristics.cpp
        ../include/wanderbot/linearalgebra/vector.hpp ../src/linearalgebra/vector.cpp)

ament_add_gtest(state_handler_go_test
        statehandler/state_handler_go_test.cpp
        ../include/wanderbot/config/config.hpp ../src/config/config.cpp
        ../src/fsm/statehandler/state_handler_go.cpp ../include/wanderbot/fsm/statehandler/state_handler_go.hpp
        ../include/wanderbot/laser/laser_characteristics.hpp ../src/laser/laser_characteristics.cpp
        ../include/wanderbot/motion/velocity.hpp ../src/motion/velocity.cpp
        ../include/wanderbot/motion/vff/vector_force_field_calculator.hpp ../src/motion/vff/vector_force_field_calculator.cpp
        ../include/wanderbot/linearalgebra/vector.hpp ../src/linearalgebra/vector.cpp
        ../src/fsm/action.cpp ../include/wanderbot/fsm/action.hpp
        ../include/wanderbot/linearalgebra/vector.hpp ../src/linearalgebra/vector.cpp)

ament_add_gtest(state_handler_blocked_test
        statehandler/state_handler_blocked_test.cpp
        ../include/wanderbot/config/config.hpp ../src/config/config.cpp
        ../src/fsm/statehandler/state_handler_back_up.cpp ../include/wanderbot/fsm/statehandler/state_handler_back_up.hpp
        ../include/wanderbot/laser/laser_characteristics.hpp ../src/laser/laser_characteristics.cpp
        ../include/wanderbot/motion/velocity.hpp ../src/motion/velocity.cpp
        ../src/fsm/action.cpp ../include/wanderbot/fsm/action.hpp
        ../include/wanderbot/linearalgebra/vector.hpp ../src/linearalgebra/vector.cpp)

ament_add_gtest(vector_force_field_calculator_test
        velocity/vff/vector_force_field_calculator_test.cpp
        test_constants.hpp
        ../include/wanderbot/config/config.hpp ../src/config/config.cpp
        ../include/wanderbot/motion/vff/vector_force_field_calculator.hpp ../src/motion/vff/vector_force_field_calculator.cpp
        ../include/wanderbot/linearalgebra/vector.hpp ../src/linearalgebra/vector.cpp)


ament_target_dependencies(laser_characteristics_test ${dependencies})
ament_target_dependencies(laser_analysis_test ${dependencies})
ament_target_dependencies(state_handler_go_test ${dependencies})
ament_target_dependencies(state_handler_blocked_test ${dependencies})
ament_target_dependencies(vector_force_field_calculator_test ${dependencies})
