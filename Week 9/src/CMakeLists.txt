file(GLOB SOURCES "*.cpp")
add_library(traffic_lib ${SOURCES})
target_include_directories(traffic_lib PUBLIC
    ${PROJECT_SOURCE_DIR}/inc
)

add_executable(traffic_app ${PROJECT_SOURCE_DIR}/main.cpp)
target_link_libraries(traffic_app
    traffic_lib
)
set_target_properties(traffic_app PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
)
