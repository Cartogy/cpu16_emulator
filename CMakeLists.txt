cmake_minimum_required(VERSION 3.22.2)

# Include to satisfy the CMake requirements for the root file.
project(CPUEMU)


set(CMAKE_CXX_STANDARD 14)
# Have the build command generate the 'compile_commands.json'.
set(CMAKE_EXPORT_COMPILE_COMMANDS True)

include(FetchContent)
FetchContent_Declare(
	googletest
	GIT_REPOSITORY https://github.com/google/googletest.git
	GIT_TAG release-1.12.1
)
# Installs GoogleTest
FetchContent_MakeAvailable(googletest)

enable_testing()

add_subdirectory(src)
add_subdirectory(tests)
