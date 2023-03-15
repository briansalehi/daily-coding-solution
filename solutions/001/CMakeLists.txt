cmake_minimum_required(VERSION 3.15 FATAL_ERROR)
project(problem LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Boost COMPONENTS program_options)
find_package(GTest)

add_executable(problem main.cpp)
target_sources(problem PRIVATE ksum.hpp)
target_link_libraries(problem PRIVATE Boost::program_options)
target_include_directories(problem PRIVATE ${CMAKE_SOURCE_DIR})

add_executable(ksum-test EXCLUDE_FROM_ALL test.cpp)
target_sources(ksum-test PRIVATE ksum.hpp)
target_include_directories(ksum-test PRIVATE ${CMAKE_SOURCE_DIR})
target_link_libraries(ksum-test PRIVATE gtest)
add_test(NAME test COMMAND ksum-test)
