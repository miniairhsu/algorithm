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
CMAKE_SOURCE_DIR = /home/algorithm/minesweeper_8

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/algorithm/minesweeper_8/build

# Include any dependencies generated for this target.
include CMakeFiles/mine_layout.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/mine_layout.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mine_layout.dir/flags.make

CMakeFiles/mine_layout.dir/src/main.cpp.o: CMakeFiles/mine_layout.dir/flags.make
CMakeFiles/mine_layout.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/algorithm/minesweeper_8/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/mine_layout.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mine_layout.dir/src/main.cpp.o -c /home/algorithm/minesweeper_8/src/main.cpp

CMakeFiles/mine_layout.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mine_layout.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/algorithm/minesweeper_8/src/main.cpp > CMakeFiles/mine_layout.dir/src/main.cpp.i

CMakeFiles/mine_layout.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mine_layout.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/algorithm/minesweeper_8/src/main.cpp -o CMakeFiles/mine_layout.dir/src/main.cpp.s

# Object files for target mine_layout
mine_layout_OBJECTS = \
"CMakeFiles/mine_layout.dir/src/main.cpp.o"

# External object files for target mine_layout
mine_layout_EXTERNAL_OBJECTS =

mine_layout: CMakeFiles/mine_layout.dir/src/main.cpp.o
mine_layout: CMakeFiles/mine_layout.dir/build.make
mine_layout: sln/libmine_layout_solution.a
mine_layout: CMakeFiles/mine_layout.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/algorithm/minesweeper_8/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable mine_layout"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mine_layout.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mine_layout.dir/build: mine_layout

.PHONY : CMakeFiles/mine_layout.dir/build

CMakeFiles/mine_layout.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/mine_layout.dir/cmake_clean.cmake
.PHONY : CMakeFiles/mine_layout.dir/clean

CMakeFiles/mine_layout.dir/depend:
	cd /home/algorithm/minesweeper_8/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/algorithm/minesweeper_8 /home/algorithm/minesweeper_8 /home/algorithm/minesweeper_8/build /home/algorithm/minesweeper_8/build /home/algorithm/minesweeper_8/build/CMakeFiles/mine_layout.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/mine_layout.dir/depend

