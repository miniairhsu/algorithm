# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
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
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/len/algorithm/state_machine_utility

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/len/algorithm/state_machine_utility/build

# Include any dependencies generated for this target.
include st/CMakeFiles/st_util.dir/depend.make

# Include the progress variables for this target.
include st/CMakeFiles/st_util.dir/progress.make

# Include the compile flags for this target's objects.
include st/CMakeFiles/st_util.dir/flags.make

st/CMakeFiles/st_util.dir/st_util.c.o: st/CMakeFiles/st_util.dir/flags.make
st/CMakeFiles/st_util.dir/st_util.c.o: ../st/st_util.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/len/algorithm/state_machine_utility/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object st/CMakeFiles/st_util.dir/st_util.c.o"
	cd /home/len/algorithm/state_machine_utility/build/st && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/st_util.dir/st_util.c.o   -c /home/len/algorithm/state_machine_utility/st/st_util.c

st/CMakeFiles/st_util.dir/st_util.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/st_util.dir/st_util.c.i"
	cd /home/len/algorithm/state_machine_utility/build/st && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/len/algorithm/state_machine_utility/st/st_util.c > CMakeFiles/st_util.dir/st_util.c.i

st/CMakeFiles/st_util.dir/st_util.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/st_util.dir/st_util.c.s"
	cd /home/len/algorithm/state_machine_utility/build/st && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/len/algorithm/state_machine_utility/st/st_util.c -o CMakeFiles/st_util.dir/st_util.c.s

# Object files for target st_util
st_util_OBJECTS = \
"CMakeFiles/st_util.dir/st_util.c.o"

# External object files for target st_util
st_util_EXTERNAL_OBJECTS =

st/libst_util.a: st/CMakeFiles/st_util.dir/st_util.c.o
st/libst_util.a: st/CMakeFiles/st_util.dir/build.make
st/libst_util.a: st/CMakeFiles/st_util.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/len/algorithm/state_machine_utility/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libst_util.a"
	cd /home/len/algorithm/state_machine_utility/build/st && $(CMAKE_COMMAND) -P CMakeFiles/st_util.dir/cmake_clean_target.cmake
	cd /home/len/algorithm/state_machine_utility/build/st && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/st_util.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
st/CMakeFiles/st_util.dir/build: st/libst_util.a

.PHONY : st/CMakeFiles/st_util.dir/build

st/CMakeFiles/st_util.dir/clean:
	cd /home/len/algorithm/state_machine_utility/build/st && $(CMAKE_COMMAND) -P CMakeFiles/st_util.dir/cmake_clean.cmake
.PHONY : st/CMakeFiles/st_util.dir/clean

st/CMakeFiles/st_util.dir/depend:
	cd /home/len/algorithm/state_machine_utility/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/len/algorithm/state_machine_utility /home/len/algorithm/state_machine_utility/st /home/len/algorithm/state_machine_utility/build /home/len/algorithm/state_machine_utility/build/st /home/len/algorithm/state_machine_utility/build/st/CMakeFiles/st_util.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : st/CMakeFiles/st_util.dir/depend

