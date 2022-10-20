add_library(src main.cpp)
project(CPUEMU)

add_executable(${PROJECT_NAME} main.cpp emu_utils.cpp emulator.cpp my_emulator.cpp emu_opers.cpp)

add_subdirectory(Cpu)
add_subdirectory(Memory)
add_subdirectory(OperatorTable)

# Have the executable be linked with the project executable
## Have to link all the libraries you want to include.
target_link_libraries(${PROJECT_NAME} cpu operator_table operator memory)
# Have libraries be associated with 'src'.
target_link_libraries(src cpu memory operator_table operator)

target_include_directories(${PROJECT_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
