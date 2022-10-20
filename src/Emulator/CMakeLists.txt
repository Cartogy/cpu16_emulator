add_library(emulator emulator.cpp)

#target_include_directories(emulator PUBLIC src)
# Include a directory outside of this sub-directory
#include_directories(${PROJECT_SOURCE_DIR}/src/)

target_include_directories(${PROJECT_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(emulator PUBLIC ${PROJECT_SOURCE_DIR}/src)

# Link the src libraries.
target_link_libraries(emulator src)
