cmake_minimum_required(VERSION 3.28)
project(RubiksCubeSolver)

set(CMAKE_CXX_STANDARD 20)

add_executable(RubiksCubeSolver main.cpp
        model/RubiksCube3DArray.cpp
        model/RubiksCube.cpp
        model/RubiksCube.h
)
