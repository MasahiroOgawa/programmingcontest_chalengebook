project(chapter2 CXX) #CXX means that we use c++ as the language

add_executable(bubunnwa bubunnwa/main.cpp)
add_executable(fibonacci fibonacci/main.cpp)
add_executable(lakecounting lakecounting/main.cpp)
add_executable(maze_shortestpath maze_shortestpath/main.cpp)
add_executable(perm2 perm2/main.cpp)
add_executable(sortpermutation sortpermutation/main.cpp)
add_executable(nolimnum_napsack_bad nolimnum_napsack/bad.cpp)
add_executable(nolimnum_napsack_good nolimnum_napsack/good.cpp)
add_executable(napsack_reusevector napsackproblem/reuse_vector.cpp)

