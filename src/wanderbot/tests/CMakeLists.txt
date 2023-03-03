ament_add_gtest(laser_test
        laser/laser_test.cpp
        test_constants.hpp
        ../include/wanderbot/laser/laser_analyzer.hpp ../src/laser/laser_analyzer.cpp
        ../include/wanderbot/laser/laser_characteristics.hpp ../src/laser/laser_characteristics.cpp
        ../include/wanderbot/vector/vector_by_magnitude_angle.hpp ../src/vector/vector_by_magnitude_angle.cpp)

ament_add_gtest(state_handler_go_test
        statehandler/state_handler_go_test.cpp
        test_constants.hpp
        ../src/fsm/statehandler/state_handler_go.cpp ../include/wanderbot/fsm/statehandler/state_handler_go.hpp
        ../include/wanderbot/laser/laser_characteristics.hpp ../src/laser/laser_characteristics.cpp
        ../include/wanderbot/velocity/velocity.hpp ../src/velocity/velocity.cpp
        ../include/wanderbot/velocity/vff/vector_force_field_calculator.hpp ../src/velocity/vff/vector_force_field_calculator.cpp
        ../include/wanderbot/vector/vector_converter.hpp ../src/vector/vector_converter.cpp
        ../include/wanderbot/vector/vector_by_magnitude_angle.hpp ../src/vector/vector_by_magnitude_angle.cpp
        ../include/wanderbot/vector/vector_by_standard_position.hpp ../src/vector/vector_by_standard_position.cpp
        ../src/fsm/action.cpp ../include/wanderbot/fsm/action.hpp
        ../include/wanderbot/vector/vector_by_magnitude_angle.hpp ../src/vector/vector_by_magnitude_angle.cpp)

ament_add_gtest(state_handler_blocked_test
        statehandler/state_handler_blocked_test.cpp
        test_constants.hpp
        ../src/fsm/statehandler/state_handler_blocked.cpp ../include/wanderbot/fsm/statehandler/state_handler_blocked.hpp
        ../include/wanderbot/laser/laser_characteristics.hpp ../src/laser/laser_characteristics.cpp
        ../include/wanderbot/velocity/velocity.hpp ../src/velocity/velocity.cpp
        ../src/fsm/action.cpp ../include/wanderbot/fsm/action.hpp
        ../include/wanderbot/vector/vector_by_magnitude_angle.hpp ../src/vector/vector_by_magnitude_angle.cpp)

ament_add_gtest(vector_force_field_calculator_test
        velocity/vff/vector_force_field_calculator_test.cpp
        test_constants.hpp
        ../include/wanderbot/velocity/vff/vector_force_field_calculator.hpp
        ../src/velocity/vff/vector_force_field_calculator.cpp
        ../include/wanderbot/vector/vector_by_standard_position.hpp
        ../src/vector/vector_by_standard_position.cpp
        ../include/wanderbot/vector/vector_by_magnitude_angle.hpp ../src/vector/vector_by_magnitude_angle.cpp)

ament_add_gtest(vector_converter_test
        velocity/vff/vector_converter_test.cpp
        test_constants.hpp
        ../include/wanderbot/vector/vector_converter.hpp
        ../src/vector/vector_converter.cpp
        ../include/wanderbot/vector/vector_by_magnitude_angle.hpp
        ../src/vector/vector_by_magnitude_angle.cpp
        ../include/wanderbot/vector/vector_by_standard_position.hpp
        ../src/vector/vector_by_standard_position.cpp)

ament_target_dependencies(laser_test ${dependencies})
ament_target_dependencies(state_handler_go_test ${dependencies})
ament_target_dependencies(state_handler_blocked_test ${dependencies})
ament_target_dependencies(vector_force_field_calculator_test ${dependencies})
ament_target_dependencies(vector_converter_test ${dependencies})
