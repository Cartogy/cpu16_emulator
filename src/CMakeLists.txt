project(CPUEMU)

add_executable(${PROJECT_NAME} main.cpp emu_utils.cpp)

add_subdirectory(Cpu)

target_link_libraries(${PROJECT_NAME} cpu)
