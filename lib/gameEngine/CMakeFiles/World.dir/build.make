# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_SOURCE_DIR = /home/mariyant/Desktop/project/textadventure

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mariyant/Desktop/project/textadventure

# Include any dependencies generated for this target.
include lib/gameEngine/CMakeFiles/World.dir/depend.make

# Include the progress variables for this target.
include lib/gameEngine/CMakeFiles/World.dir/progress.make

# Include the compile flags for this target's objects.
include lib/gameEngine/CMakeFiles/World.dir/flags.make

lib/gameEngine/CMakeFiles/World.dir/World.cpp.o: lib/gameEngine/CMakeFiles/World.dir/flags.make
lib/gameEngine/CMakeFiles/World.dir/World.cpp.o: lib/gameEngine/World.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/mariyant/Desktop/project/textadventure/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object lib/gameEngine/CMakeFiles/World.dir/World.cpp.o"
	cd /home/mariyant/Desktop/project/textadventure/lib/gameEngine && /usr/bin/clang++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/World.dir/World.cpp.o -c /home/mariyant/Desktop/project/textadventure/lib/gameEngine/World.cpp

lib/gameEngine/CMakeFiles/World.dir/World.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/World.dir/World.cpp.i"
	cd /home/mariyant/Desktop/project/textadventure/lib/gameEngine && /usr/bin/clang++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/mariyant/Desktop/project/textadventure/lib/gameEngine/World.cpp > CMakeFiles/World.dir/World.cpp.i

lib/gameEngine/CMakeFiles/World.dir/World.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/World.dir/World.cpp.s"
	cd /home/mariyant/Desktop/project/textadventure/lib/gameEngine && /usr/bin/clang++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/mariyant/Desktop/project/textadventure/lib/gameEngine/World.cpp -o CMakeFiles/World.dir/World.cpp.s

lib/gameEngine/CMakeFiles/World.dir/World.cpp.o.requires:
.PHONY : lib/gameEngine/CMakeFiles/World.dir/World.cpp.o.requires

lib/gameEngine/CMakeFiles/World.dir/World.cpp.o.provides: lib/gameEngine/CMakeFiles/World.dir/World.cpp.o.requires
	$(MAKE) -f lib/gameEngine/CMakeFiles/World.dir/build.make lib/gameEngine/CMakeFiles/World.dir/World.cpp.o.provides.build
.PHONY : lib/gameEngine/CMakeFiles/World.dir/World.cpp.o.provides

lib/gameEngine/CMakeFiles/World.dir/World.cpp.o.provides.build: lib/gameEngine/CMakeFiles/World.dir/World.cpp.o

# Object files for target World
World_OBJECTS = \
"CMakeFiles/World.dir/World.cpp.o"

# External object files for target World
World_EXTERNAL_OBJECTS =

lib/libWorld.a: lib/gameEngine/CMakeFiles/World.dir/World.cpp.o
lib/libWorld.a: lib/gameEngine/CMakeFiles/World.dir/build.make
lib/libWorld.a: lib/gameEngine/CMakeFiles/World.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX static library ../libWorld.a"
	cd /home/mariyant/Desktop/project/textadventure/lib/gameEngine && $(CMAKE_COMMAND) -P CMakeFiles/World.dir/cmake_clean_target.cmake
	cd /home/mariyant/Desktop/project/textadventure/lib/gameEngine && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/World.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/gameEngine/CMakeFiles/World.dir/build: lib/libWorld.a
.PHONY : lib/gameEngine/CMakeFiles/World.dir/build

lib/gameEngine/CMakeFiles/World.dir/requires: lib/gameEngine/CMakeFiles/World.dir/World.cpp.o.requires
.PHONY : lib/gameEngine/CMakeFiles/World.dir/requires

lib/gameEngine/CMakeFiles/World.dir/clean:
	cd /home/mariyant/Desktop/project/textadventure/lib/gameEngine && $(CMAKE_COMMAND) -P CMakeFiles/World.dir/cmake_clean.cmake
.PHONY : lib/gameEngine/CMakeFiles/World.dir/clean

lib/gameEngine/CMakeFiles/World.dir/depend:
	cd /home/mariyant/Desktop/project/textadventure && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mariyant/Desktop/project/textadventure /home/mariyant/Desktop/project/textadventure/lib/gameEngine /home/mariyant/Desktop/project/textadventure /home/mariyant/Desktop/project/textadventure/lib/gameEngine /home/mariyant/Desktop/project/textadventure/lib/gameEngine/CMakeFiles/World.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/gameEngine/CMakeFiles/World.dir/depend

