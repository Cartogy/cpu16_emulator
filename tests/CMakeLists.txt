

add_executable(test_stuff test.cc)

target_link_libraries(test_stuff GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(test_stuff)

