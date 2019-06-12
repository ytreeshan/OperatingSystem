cmake_minimum_required(VERSION 3.14)
project(TestingHomeproject4)

set(CMAKE_CXX_STANDARD 14)

add_executable(TestingHomeproject4
        main.cpp
        CPU.cpp
        CPU.h
        disk.cpp
        disk.h
        Memory.cpp
        Memory.h
        OperatingSystem.cpp
        OperatingSystem.h
        Process.cpp
        Process.h)