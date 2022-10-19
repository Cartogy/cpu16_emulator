add_library(src main.cpp)
project(CPUEMU)

add_executable(${PROJECT_NAME} main.cpp emu_utils.cpp emulator.cpp my_emulator.cpp)

add_subdirectory(Cpu)
add_subdirectory(Memory)
add_subdirectory(OperatorTable)

target_link_libraries(${PROJECT_NAME} cpu operators memory)
# Have libraries be associated with 'src'.
target_link_libraries(src cpu memory operators)

target_include_directories(${PROJECT_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
