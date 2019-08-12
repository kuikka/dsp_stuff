cmake_minimum_required (VERSION 2.6)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project (goertzel)
add_executable(goertzel goertzel.cpp)

add_executable(fm fm_modulation.cpp)
