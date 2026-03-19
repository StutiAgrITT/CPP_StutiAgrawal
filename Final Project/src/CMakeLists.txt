file(GLOB SOURCES "*.cpp")

add_library(instagram_lib ${SOURCES})

target_include_directories(instagram_lib PUBLIC
    ${PROJECT_SOURCE_DIR}/inc
)

add_executable(instagram_app ${PROJECT_SOURCE_DIR}/main.cpp)

target_link_libraries(instagram_app
    instagram_lib
)

set_target_properties(instagram_app PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
)
