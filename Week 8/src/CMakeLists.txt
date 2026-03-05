file(GLOB SOURCES "*.cpp")

add_library(playlist_lib ${SOURCES})

target_include_directories(playlist_lib PUBLIC
    ${PROJECT_SOURCE_DIR}/inc
)

add_executable(playlist_app ${PROJECT_SOURCE_DIR}/main.cpp)

target_link_libraries(playlist_app
    playlist_lib
    sfml-audio
)

set_target_properties(playlist_app PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
)
