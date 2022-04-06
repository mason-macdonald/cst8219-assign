
cmake_minimum_required(VERSION 3.13)

project (part2)

set(CMAKE_BUILD_TYPE Debug)

add_executable(
    part2 part2.cpp
    Animation.h Animation.cpp
    Frame.h Frame.cpp
)
