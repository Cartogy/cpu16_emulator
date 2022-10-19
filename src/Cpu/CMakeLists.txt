add_library(cpu cpu.cpp)

add_subdirectory(InstructionMemory)


target_include_directories(cpu INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
