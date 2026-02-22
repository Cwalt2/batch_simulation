cmake_minimum_required(VERSION 4.1)
project(batch_simulation)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

add_executable(batch_simulation main.cpp)
