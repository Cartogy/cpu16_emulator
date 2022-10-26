add_library(compiler compiler.cpp)

target_include_directories(${PROJECT_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

# Use the library in machine code generator.
target_link_libraries(compiler machinecodegenerator tokenizer parser)
