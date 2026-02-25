cmake_minimum_required(VERSION 3.10)
project(TestingBasics)

set(CMAKE_CXX_STANDARD 17)

enable_testing()

add_library(utils src/utils.cpp)

target_include_directories(utils PUBLIC inc)

find_package(GTest REQUIRED)

add_executable(runTests tests/utilsTest.cpp)

target_link_libraries(runTests
    utils
    GTest::GTest
    GTest::Main
    GTest::gmock
    pthread
)
add_test(NAME runTests COMMAND runTests)
