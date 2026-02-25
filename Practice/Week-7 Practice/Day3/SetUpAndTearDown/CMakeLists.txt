cmake_minimum_required(VERSION 3.10)
project(TestingBasics)

set(CMAKE_CXX_STANDARD 17)

enable_testing()

add_library(stack src/stack.cpp)

target_include_directories(stack PUBLIC inc)

find_package(GTest REQUIRED)

add_executable(runTests tests/stackTest.cpp)

target_link_libraries(runTests stack GTest::GTest GTest::Main pthread)

add_test(NAME runTests COMMAND runTests)
