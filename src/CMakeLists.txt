project(challengebook CXX)

add_library(graph graph/bellman_ford.cpp)
target_sources(graph INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/graph/adjacencylist.hpp) # to see this header in IDE.

add_library(number_theory math/number_theory.cpp)

###
# unit tests
add_executable(number_theory_test math/number_theory.test.cpp)
target_link_libraries(number_theory_test number_theory gtest_main)
add_test(NAME number_theory_test COMMAND number_theory_test)
