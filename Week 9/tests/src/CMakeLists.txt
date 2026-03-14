file(GLOB TEST_SOURCES "*.cpp")
add_executable(traffic_tests ${TEST_SOURCES})
target_link_libraries(traffic_tests
    traffic_lib
    GTest::gtest
    GTest::gtest_main
    GTest::gmock
)
target_include_directories(traffic_tests PRIVATE
    ${PROJECT_SOURCE_DIR}/inc
    ${PROJECT_SOURCE_DIR}/tests/inc
)
set_target_properties(traffic_tests PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
)
include(GoogleTest)
gtest_discover_tests(traffic_tests)
