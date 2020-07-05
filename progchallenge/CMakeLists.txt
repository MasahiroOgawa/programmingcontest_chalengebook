project(challengebook CXX)

add_library(progchallenge bellman_ford.cpp number_theory.cpp search.cpp print.cpp unionfind_tree.cpp)
target_include_directories(progchallenge PUBLIC ${CMAKE_SOURCE_DIR})
target_sources(progchallenge INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/adjacencylist.hpp) # to see this header in IDE.

###
# unit tests
add_executable(number_theory_test number_theory.test.cpp)
target_link_libraries(number_theory_test progchallenge gtest_main)
add_test(NAME number_theory_test COMMAND number_theory_test)

add_executable(unionfind_tree_test unionfind_tree.test.cpp)
target_link_libraries(unionfind_tree_test progchallenge gtest_main)
add_test(NAME unionfind_tree_test COMMAND unionfind_tree_test)
