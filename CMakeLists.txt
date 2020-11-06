cmake_minimum_required(VERSION 3.14)
project(proyecto-compilador)

set(CMAKE_CXX_STANDARD 14)

add_library(util util.cpp)
add_library(lexicalAnalyzer lexicalAnalyzer.cpp util)
add_executable(main main.cpp util lexicalAnalyzer)