cmake_minimum_required(VERSION 3.3)
project(InsertionSort)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp SelectionSort.h)
add_executable(InsertionSort ${SOURCE_FILES})