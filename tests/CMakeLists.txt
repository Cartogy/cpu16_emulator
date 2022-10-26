

add_executable(test_stuff test.cc memory_test.cc cpu_test.cc instruction_memory.cc operator_test.cc operator_table_test.cc tokenizer.cc parser.cc parser_token_test.cc machinecodegenerator_test.cc parsernodes_test.cc compiler_test.cc)
add_executable(emulation_test emulation_test.cc)

# The use of 'src' means all libraries from 'src' are linked to 'test_stuff'.
target_link_libraries(test_stuff GTest::gtest_main src)
target_link_libraries(emulation_test GTest::gtest_main src)

include(GoogleTest)
gtest_discover_tests(test_stuff)

target_include_directories(test_stuff PUBLIC ${PROJECT_SOURCE_DIR}/src/Memory)
target_include_directories(test_stuff PUBLIC ${PROJECT_SOURCE_DIR}/src/Cpu/InstructionMemory)

# Have the 'src' folder be included in the directory.
target_include_directories(test_stuff PUBLIC ${PROJECT_SOURCE_DIR}/src)
target_include_directories(emulation_test PUBLIC ${PROJECT_SOURCE_DIR}/src)

# have the test files be copied to the build folder.
configure_file("test_asm.asm" "test_asm.asm" COPYONLY)
configure_file("test_two_asm.asm" "test_two_asm.asm" COPYONLY)
configure_file("test_three_asm.asm" "test_three_asm.asm" COPYONLY)
