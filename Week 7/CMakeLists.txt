cmake_minimum_required(VERSION 3.14)
project(BankingSystem)

set(CMAKE_CXX_STANDARD 17)

find_package(GTest REQUIRED)

file(GLOB SOURCES "src/*.cpp")

add_library(banking_lib ${SOURCES})
target_include_directories(banking_lib PUBLIC inc)

add_executable(banking_app main.cpp)
target_link_libraries(banking_app banking_lib)

file(GLOB TEST_SOURCES "tests/src/*.cpp")

add_executable(banking_tests ${TEST_SOURCES})

target_link_libraries(banking_tests
    banking_lib
    GTest::GTest
    GTest::Main
    gmock
)

target_include_directories(banking_tests PRIVATE
    inc
    tests/inc
)

include(GoogleTest)
gtest_discover_tests(banking_tests)
