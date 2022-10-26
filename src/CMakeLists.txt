# This makes the implementation be linkable to other CMake directories.
add_library(src main.cpp emu_utils.cpp emu16.cpp)

add_executable(${PROJECT_NAME} main.cpp emu_utils.cpp my_emulator.cpp)

add_subdirectory(Cpu)
add_subdirectory(Memory)
add_subdirectory(OperatorTable)
add_subdirectory(Emulator)
add_subdirectory(Tokenizer)
add_subdirectory(Parser)
add_subdirectory(MachineCodeGenerator)
add_subdirectory(Compiler)

# Have the executable be linked with the project executable
## Have to link all the libraries you want to include.
target_link_libraries(${PROJECT_NAME} cpu operator_table operator memory emulator tokenizer parser popertable inscategory machinecodegenerator compiler)
# Have libraries be associated with 'src'.
target_link_libraries(src cpu memory operator_table operator emulator tokenizer parser popertable inscategory machinecodegenerator compiler) 

target_include_directories(${PROJECT_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
