project(challengebook CXX)

add_executable(triangle triangle.cpp)
add_executable(ants_poj1852 ants_poj1852.cpp)

add_executable(lottery_n3logn lottery_n3logn.cpp)
target_link_libraries(lottery_n3logn progchallenge)

add_executable(lottery_n2logn lottery_n2logn.cpp)
target_link_libraries(lottery_n2logn progchallenge)
