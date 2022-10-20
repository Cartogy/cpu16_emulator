

add_executable(test_stuff test.cc memory_test.cc cpu_test.cc instruction_memory.cc operator_test.cc)

# The use of 'src' means all libraries from 'src' are linked to 'test_stuff'.
target_link_libraries(test_stuff GTest::gtest_main src)

include(GoogleTest)
gtest_discover_tests(test_stuff)

target_include_directories(test_stuff PUBLIC ${PROJECT_SOURCE_DIR}/src/Memory)
target_include_directories(test_stuff PUBLIC ${PROJECT_SOURCE_DIR}/src/Cpu/InstructionMemory)

# Have the 'src' folder be included in the directory.
target_include_directories(test_stuff PUBLIC ${PROJECT_SOURCE_DIR}/src)
