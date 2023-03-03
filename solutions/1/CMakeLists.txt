cmake_minimum_required(VERSION 3.15 FATAL_ERROR)
project(ksum LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(ksum ksum.cpp)
target_include_directories(ksum PRIVATE ${CMAKE_SOURCE_DIR})

add_executable(ksum-test EXCLUDE_FROM_ALL ksum.cpp test.cpp)
target_include_directories(ksum-test PRIVATE ${CMAKE_SOURCE_DIR})
target_link_libraries(ksum-test PRIVATE gtest)
add_test(NAME test COMMAND ksum-test)
