cmake_minimum_required(VERSION 3.14)
project(MusicPlaylist)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)

find_package(SFML 2.5 COMPONENTS audio QUIET)

if(NOT SFML_FOUND)
    message(STATUS "SFML not found, downloading via FetchContent...")
    FetchContent_Declare(
        sfml
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.1
    )
    FetchContent_MakeAvailable(sfml)
endif()

find_package(GTest QUIET)

if(NOT GTest_FOUND)
    message(STATUS "GTest not found, downloading via FetchContent...")
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