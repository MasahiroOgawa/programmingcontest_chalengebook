project(challengebook CXX)

add_library(progchallenge bellman_ford.cpp number_theory.cpp)
target_sources(progchallenge INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/adjacencylist.hpp) # to see this header in IDE.

###
# unit tests
add_executable(number_theory_test number_theory.test.cpp)
target_link_libraries(number_theory_test progchallenge gtest_main)
add_test(NAME number_theory_test COMMAND number_theory_test)
