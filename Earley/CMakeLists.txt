cmake_minimum_required(VERSION 3.13)
project(Earley)
set(CMAKE_CXX_STANDARD 14)

add_executable(Earley Algo.cpp Algo.h Earley_algo.cpp Grammar.cpp Grammar.h Production.cpp Production.h Situation.cpp Situation.h)