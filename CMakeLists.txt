cmake_minimum_required(VERSION 4.0.2)
project(AugustChiffre)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)
add_executable(AugustChiffre ../src/main.cpp)