project(challengebook CXX)

add_library(graph graph/bellman_ford.cpp)
target_sources(graph INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/graph/adjacencylist.hpp) # to see this header in IDE.


###
# unit tests
add_executable(euclidean_algo_test mathmatic/euclidean_algo.test.cpp)
target_link_libraries(euclidean_algo_test gtest_main)
add_test(NAME euclidean_algo_test COMMAND euclidean_algo_test)
