cmake_minimum_required(VERSION 3.1)
project(challengebook CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-O2 -Wall")

ADD_SUBDIRECTORY(src)
ADD_SUBDIRECTORY(test)
