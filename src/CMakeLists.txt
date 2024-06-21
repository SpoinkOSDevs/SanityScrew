cmake_minimum_required(VERSION 3.10)
project(SSJITCompiler)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find and link the required libraries
find_package(Threads REQUIRED)
find_package(Boost REQUIRED COMPONENTS system filesystem)

add_executable(SSJITCompiler main.cpp)

# Link required libraries
target_link_libraries(SSJITCompiler PRIVATE Threads::Threads Boost::system Boost::filesystem)
