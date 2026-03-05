cmake_minimum_required(VERSION 3.14)
project(MusicPlaylist)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)

find_package(SFML 2.5 COMPONENTS audio QUIET)

if(NOT SFML_FOUND)
    message(STATUS "SFML not found, downloading...")
    FetchContent_Declare(
        sfml
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.1
    )
    FetchContent_MakeAvailable(sfml)
endif()

add_subdirectory(src)
