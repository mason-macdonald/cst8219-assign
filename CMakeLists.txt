
cmake_minimum_required(VERSION 3.13)

project (part3)

set(CMAKE_BUILD_TYPE Debug)

add_executable(
    part3 part3.cpp
    Animation.h Animation.cpp
    AnimationManager.h AnimationManager.cpp
    Frame.h Frame.cpp
)
