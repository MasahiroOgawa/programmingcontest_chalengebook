project(challengebook CXX)

add_library(graph graph/bellman_ford.cpp)
target_sources(graph INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/graph/adjacencylist.hpp) # to see this header in IDE.
