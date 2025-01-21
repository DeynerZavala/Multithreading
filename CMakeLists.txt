cmake_minimum_required(VERSION 3.30)
project(Multithreading)

set(CMAKE_CXX_STANDARD 20)

add_executable(Multithreading CpuWaste.cpp
        InfiniteGreeting.cpp
        CpuWateCalculator.cpp)
