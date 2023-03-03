cmake_minimum_required(VERSION 3.15 FATAL_ERROR)
project(problem LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(problem problem.cpp)
target_include_directories(problem PRIVATE ${CMAKE_SOURCE_DIR})

add_executable(problem-test EXCLUDE_FROM_ALL problem.cpp test.cpp)
target_include_directories(problem-test PRIVATE ${CMAKE_SOURCE_DIR})
target_link_libraries(problem-test PRIVATE gtest)
add_test(NAME test COMMAND problem-test)
