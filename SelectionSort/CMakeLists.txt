cmake_minimum_required(VERSION 3.3)
project(SelectionSort)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp SortTestHelper.h Student.h)
add_executable(SelectionSort ${SOURCE_FILES})