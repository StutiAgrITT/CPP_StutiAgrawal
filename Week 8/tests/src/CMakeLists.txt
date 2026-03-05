file(GLOB TEST_SOURCES "*.cpp")

add_executable(playlist_tests ${TEST_SOURCES})

target_link_libraries(playlist_tests
    playlist_lib
    GTest::gtest
    GTest::gtest_main
    GTest::gmock
)

target_include_directories(playlist_tests PRIVATE
    ${PROJECT_SOURCE_DIR}/inc
    ${PROJECT_SOURCE_DIR}/tests/inc
)

set_target_properties(playlist_tests PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
)

include(GoogleTest)
gtest_discover_tests(playlist_tests)