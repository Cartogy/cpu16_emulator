project(CPUEMU)

add_executable(${PROJECT_NAME} main.cpp emu_utils.cpp emulator.cpp my_emulator.cpp)

add_subdirectory(Cpu)
add_subdirectory(Memory)
add_subdirectory(OperatorTable)

target_link_libraries(${PROJECT_NAME} cpu)
target_link_libraries(${PROJECT_NAME} operators)
target_link_libraries(${PROJECT_NAME} memory)

target_include_directories(${PROJECT_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
