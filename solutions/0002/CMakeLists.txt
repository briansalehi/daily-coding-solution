cmake_minimum_required(VERSION 3.15)
project(adjacent_products DESCRIPTION "Solution #2" VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(adjacent-products-test EXCLUDE_FROM_ALL)
target_sources(adjacent-products-test PRIVATE test.cpp)
target_include_directories(adjacent-products-test PRIVATE ${CMAKE_SOURCE_DIR})
target_link_libraries(adjacent-products-test PRIVATE gtest)
add_test(NAME test COMMAND adjacent-products-test)
