cmake_minimum_required(VERSION 3.3.2)
project(MergeSort)

set(CMAKE_CXX_STANDARD 11)

add_executable(MergeSort main.cpp SortTestHelper.h MergeSort.h InsertSort.h)