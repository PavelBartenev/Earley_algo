cmake_minimum_required(VERSION 3.0)

project(Earley_algo)

add_executable(Earley_algo Algo.cpp Earley_algo.cpp Grammar.cpp Production.cpp Situation.cpp)

add_executable(Earley_test test.cpp run_tests.cpp)
target_link_libraries(Earley_test ${GTEST_LIBRARIES} Threads::Threads)