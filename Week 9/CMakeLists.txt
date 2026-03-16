cmake_minimum_required(VERSION 3.14)
project(TrafficLight)

set(CMAKE_CXX_STANDARD 17)

find_package(GTest QUIET)
if(NOT GTest_FOUND)
    message(STATUS "GTest not found, downloading via FetchContent...")
    include(FetchContent)
    FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.14.0
    )
    FetchContent_MakeAvailable(googletest)
endif()

add_subdirectory(src)
enable_testing()
add_subdirectory(tests/src)
