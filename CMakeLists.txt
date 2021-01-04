cmake_minimum_required(VERSION 3.13)
project(Early_with_test)
set(CMAKE_CXX_STANDARD 14)

include_directories(Earley)
add_subdirectory(Earley)
add_subdirectory(Earley_test)