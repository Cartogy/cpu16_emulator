project(CPUEMU)

add_executable(${PROJECT_NAME} main.cpp emu_utils.cpp emulator.cpp my_emulator.cpp)

add_subdirectory(Cpu)
add_subdirectory(Memory)
add_subdirectory(OperatorTable)

target_link_libraries(${PROJECT_NAME} cpu)
