make_minimum_required(VERSION 3.13)
project(Early_test)
enable_testing()
set(CMAKE_CXX_STANDARD 14)

find_package(GTest REQUIRED)

SET(CMAKE_CXX_FLAGS -pthread)
enable_testing()

include_directories(${GTEST_INCLUDE_DIRS})

add_executable(Earley_test run_tests.cpp test.cpp Algo.cpp Algo.h Grammar.cpp Grammar.h Production.cpp Production.h Situation.cpp Situation.h)
target_link_libraries(Earley_test ${GTEST_LIBRARIES})
add_test(NAME Test COMMAND Earley_test)