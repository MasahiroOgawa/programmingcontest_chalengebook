project(challengebook CXX)

add_library(progchallenge bellman_ford.cpp number_theory.cpp search.cpp print.cpp unionfind_tree.cpp
    dijkstra.cpp dijkstra_heap.cpp dijkstra_getpath.cpp warshall_floyd.cpp minimum_spanning_tree.cpp
    kruskal.cpp)
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

add_executable(bellman_ford_test bellman_ford.test.cpp)
target_link_libraries(bellman_ford_test progchallenge gtest_main)
add_test(NAME bellman_ford_test COMMAND bellman_ford_test)

add_executable(dijkstra_test dijkstra.test.cpp)
target_link_libraries(dijkstra_test progchallenge gtest_main)
add_test(NAME dijkstra_test COMMAND dijkstra_test)

add_executable(warshall_floyd_test warshall_floyd.test.cpp)
target_link_libraries(warshall_floyd_test progchallenge gtest_main)
add_test(NAME warshall_floyd_test COMMAND warshall_floyd_test)

add_executable(minimum_spanning_tree_test minimum_spanning_tree.test.cpp)
target_link_libraries(minimum_spanning_tree_test progchallenge gtest_main)
add_test(NAME minimum_spanning_tree_test COMMAND minimum_spanning_tree_test)
