# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jonas/Dev/Programming/cpp/emu/cpu16/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jonas/Dev/Programming/cpp/emu/cpu16/src/out/build

# Include any dependencies generated for this target.
include OperatorTable/CMakeFiles/operators.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include OperatorTable/CMakeFiles/operators.dir/compiler_depend.make

# Include the progress variables for this target.
include OperatorTable/CMakeFiles/operators.dir/progress.make

# Include the compile flags for this target's objects.
include OperatorTable/CMakeFiles/operators.dir/flags.make

OperatorTable/CMakeFiles/operators.dir/operator_table.o: OperatorTable/CMakeFiles/operators.dir/flags.make
OperatorTable/CMakeFiles/operators.dir/operator_table.o: ../../OperatorTable/operator_table.cpp
OperatorTable/CMakeFiles/operators.dir/operator_table.o: OperatorTable/CMakeFiles/operators.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jonas/Dev/Programming/cpp/emu/cpu16/src/out/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object OperatorTable/CMakeFiles/operators.dir/operator_table.o"
	cd /home/jonas/Dev/Programming/cpp/emu/cpu16/src/out/build/OperatorTable && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT OperatorTable/CMakeFiles/operators.dir/operator_table.o -MF CMakeFiles/operators.dir/operator_table.o.d -o CMakeFiles/operators.dir/operator_table.o -c /home/jonas/Dev/Programming/cpp/emu/cpu16/src/OperatorTable/operator_table.cpp

OperatorTable/CMakeFiles/operators.dir/operator_table.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/operators.dir/operator_table.i"
	cd /home/jonas/Dev/Programming/cpp/emu/cpu16/src/out/build/OperatorTable && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jonas/Dev/Programming/cpp/emu/cpu16/src/OperatorTable/operator_table.cpp > CMakeFiles/operators.dir/operator_table.i

OperatorTable/CMakeFiles/operators.dir/operator_table.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/operators.dir/operator_table.s"
	cd /home/jonas/Dev/Programming/cpp/emu/cpu16/src/out/build/OperatorTable && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jonas/Dev/Programming/cpp/emu/cpu16/src/OperatorTable/operator_table.cpp -o CMakeFiles/operators.dir/operator_table.s

OperatorTable/CMakeFiles/operators.dir/operator.o: OperatorTable/CMakeFiles/operators.dir/flags.make
OperatorTable/CMakeFiles/operators.dir/operator.o: ../../OperatorTable/operator.cpp
OperatorTable/CMakeFiles/operators.dir/operator.o: OperatorTable/CMakeFiles/operators.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jonas/Dev/Programming/cpp/emu/cpu16/src/out/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object OperatorTable/CMakeFiles/operators.dir/operator.o"
	cd /home/jonas/Dev/Programming/cpp/emu/cpu16/src/out/build/OperatorTable && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT OperatorTable/CMakeFiles/operators.dir/operator.o -MF CMakeFiles/operators.dir/operator.o.d -o CMakeFiles/operators.dir/operator.o -c /home/jonas/Dev/Programming/cpp/emu/cpu16/src/OperatorTable/operator.cpp

OperatorTable/CMakeFiles/operators.dir/operator.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/operators.dir/operator.i"
	cd /home/jonas/Dev/Programming/cpp/emu/cpu16/src/out/build/OperatorTable && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jonas/Dev/Programming/cpp/emu/cpu16/src/OperatorTable/operator.cpp > CMakeFiles/operators.dir/operator.i

OperatorTable/CMakeFiles/operators.dir/operator.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/operators.dir/operator.s"
	cd /home/jonas/Dev/Programming/cpp/emu/cpu16/src/out/build/OperatorTable && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jonas/Dev/Programming/cpp/emu/cpu16/src/OperatorTable/operator.cpp -o CMakeFiles/operators.dir/operator.s

OperatorTable/CMakeFiles/operators.dir/opers.o: OperatorTable/CMakeFiles/operators.dir/flags.make
OperatorTable/CMakeFiles/operators.dir/opers.o: ../../OperatorTable/opers.cpp
OperatorTable/CMakeFiles/operators.dir/opers.o: OperatorTable/CMakeFiles/operators.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jonas/Dev/Programming/cpp/emu/cpu16/src/out/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object OperatorTable/CMakeFiles/operators.dir/opers.o"
	cd /home/jonas/Dev/Programming/cpp/emu/cpu16/src/out/build/OperatorTable && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT OperatorTable/CMakeFiles/operators.dir/opers.o -MF CMakeFiles/operators.dir/opers.o.d -o CMakeFiles/operators.dir/opers.o -c /home/jonas/Dev/Programming/cpp/emu/cpu16/src/OperatorTable/opers.cpp

OperatorTable/CMakeFiles/operators.dir/opers.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/operators.dir/opers.i"
	cd /home/jonas/Dev/Programming/cpp/emu/cpu16/src/out/build/OperatorTable && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jonas/Dev/Programming/cpp/emu/cpu16/src/OperatorTable/opers.cpp > CMakeFiles/operators.dir/opers.i

OperatorTable/CMakeFiles/operators.dir/opers.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/operators.dir/opers.s"
	cd /home/jonas/Dev/Programming/cpp/emu/cpu16/src/out/build/OperatorTable && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jonas/Dev/Programming/cpp/emu/cpu16/src/OperatorTable/opers.cpp -o CMakeFiles/operators.dir/opers.s

# Object files for target operators
operators_OBJECTS = \
"CMakeFiles/operators.dir/operator_table.o" \
"CMakeFiles/operators.dir/operator.o" \
"CMakeFiles/operators.dir/opers.o"

# External object files for target operators
operators_EXTERNAL_OBJECTS =

OperatorTable/liboperators.a: OperatorTable/CMakeFiles/operators.dir/operator_table.o
OperatorTable/liboperators.a: OperatorTable/CMakeFiles/operators.dir/operator.o
OperatorTable/liboperators.a: OperatorTable/CMakeFiles/operators.dir/opers.o
OperatorTable/liboperators.a: OperatorTable/CMakeFiles/operators.dir/build.make
OperatorTable/liboperators.a: OperatorTable/CMakeFiles/operators.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jonas/Dev/Programming/cpp/emu/cpu16/src/out/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX static library liboperators.a"
	cd /home/jonas/Dev/Programming/cpp/emu/cpu16/src/out/build/OperatorTable && $(CMAKE_COMMAND) -P CMakeFiles/operators.dir/cmake_clean_target.cmake
	cd /home/jonas/Dev/Programming/cpp/emu/cpu16/src/out/build/OperatorTable && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/operators.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
OperatorTable/CMakeFiles/operators.dir/build: OperatorTable/liboperators.a
.PHONY : OperatorTable/CMakeFiles/operators.dir/build

OperatorTable/CMakeFiles/operators.dir/clean:
	cd /home/jonas/Dev/Programming/cpp/emu/cpu16/src/out/build/OperatorTable && $(CMAKE_COMMAND) -P CMakeFiles/operators.dir/cmake_clean.cmake
.PHONY : OperatorTable/CMakeFiles/operators.dir/clean

OperatorTable/CMakeFiles/operators.dir/depend:
	cd /home/jonas/Dev/Programming/cpp/emu/cpu16/src/out/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jonas/Dev/Programming/cpp/emu/cpu16/src /home/jonas/Dev/Programming/cpp/emu/cpu16/src/OperatorTable /home/jonas/Dev/Programming/cpp/emu/cpu16/src/out/build /home/jonas/Dev/Programming/cpp/emu/cpu16/src/out/build/OperatorTable /home/jonas/Dev/Programming/cpp/emu/cpu16/src/out/build/OperatorTable/CMakeFiles/operators.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : OperatorTable/CMakeFiles/operators.dir/depend

