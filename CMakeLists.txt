cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)

project(json CXX)

# make sure we are using c++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(json json.cpp)
