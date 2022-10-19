

add_executable(test_stuff test.cc memory_test.cc)

target_link_libraries(test_stuff GTest::gtest_main src)

include(GoogleTest)
gtest_discover_tests(test_stuff)

target_include_directories(test_stuff PUBLIC ${PROJECT_SOURCE_DIR}/src/Memory)