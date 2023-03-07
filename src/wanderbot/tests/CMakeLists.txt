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
        ../src/fsm/statehandler/state_handler_go.cpp ../include/wanderbot/fsm/statehandler/state_handler_go.hpp
        ../include/wanderbot/laser/laser_characteristics.hpp ../src/laser/laser_characteristics.cpp
        ../include/wanderbot/velocity/velocity.hpp ../src/velocity/velocity.cpp
        ../include/wanderbot/velocity/vff/vector_force_field_calculator.hpp ../src/velocity/vff/vector_force_field_calculator.cpp
        ../include/wanderbot/linearalgebra/vector.hpp ../src/linearalgebra/vector.cpp
        ../src/fsm/action.cpp ../include/wanderbot/fsm/action.hpp
        ../include/wanderbot/linearalgebra/vector.hpp ../src/linearalgebra/vector.cpp)

ament_add_gtest(state_handler_blocked_test
        statehandler/state_handler_blocked_test.cpp
        ../src/fsm/statehandler/state_handler_blocked.cpp ../include/wanderbot/fsm/statehandler/state_handler_blocked.hpp
        ../include/wanderbot/laser/laser_characteristics.hpp ../src/laser/laser_characteristics.cpp
        ../include/wanderbot/velocity/velocity.hpp ../src/velocity/velocity.cpp
        ../src/fsm/action.cpp ../include/wanderbot/fsm/action.hpp
        ../include/wanderbot/linearalgebra/vector.hpp ../src/linearalgebra/vector.cpp)

ament_add_gtest(vector_force_field_calculator_test
        velocity/vff/vector_force_field_calculator_test.cpp
        test_constants.hpp
        ../include/wanderbot/velocity/vff/vector_force_field_calculator.hpp ../src/velocity/vff/vector_force_field_calculator.cpp
        ../include/wanderbot/linearalgebra/vector.hpp ../src/linearalgebra/vector.cpp)


ament_target_dependencies(laser_characteristics_test ${dependencies})
ament_target_dependencies(laser_analysis_test ${dependencies})
ament_target_dependencies(state_handler_go_test ${dependencies})
ament_target_dependencies(state_handler_blocked_test ${dependencies})
ament_target_dependencies(vector_force_field_calculator_test ${dependencies})
