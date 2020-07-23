project(challengebook CXX)

include_directories(../progchallenge)

add_executable(priorityque_imple priorityque_imple.cpp)
add_executable(priorityque_stl priorityque_stl.cpp)
add_executable(priorityque_poj2431 priorityque_poj2431.cpp)
add_executable(fence_repair_pku3253 fence_repair_pku3253.cpp)
add_executable(stlset stlset.cpp)
add_executable(stlmap stlmap.cpp)
add_executable(poj1182_foodchain poj1182_foodchain.cpp)
target_link_libraries(poj1182_foodchain progchallenge)

add_library(binarysearchtree binarysearchtree.cpp)

add_executable(test_binarysearch test_binarysearch.cpp)
target_link_libraries(test_binarysearch binarysearchtree)
