cmake_minimum_required(VERSION 3.10)
project(TestingBasics)

set(CMAKE_CXX_STANDARD 17)

enable_testing()

add_library(calculator src/calculator.cpp)

target_include_directories(calculator PUBLIC inc)

find_package(GTest REQUIRED)

add_executable(runTests tests/calculator_test.cpp)

target_link_libraries(runTests calculator GTest::GTest GTest::Main pthread)

add_test(NAME runTests COMMAND runTests)
