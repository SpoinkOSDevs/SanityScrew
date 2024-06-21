cmake_minimum_required(VERSION 3.10)
project(SSJITCompiler)

set(CMAKE_CXX_STANDARD 11)

add_executable(SSJITCompiler main.cpp)

target_include_directories(SSJITCompiler PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
