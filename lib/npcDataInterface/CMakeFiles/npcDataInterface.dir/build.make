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
include lib/npcDataInterface/CMakeFiles/npcDataInterface.dir/depend.make

# Include the progress variables for this target.
include lib/npcDataInterface/CMakeFiles/npcDataInterface.dir/progress.make

# Include the compile flags for this target's objects.
include lib/npcDataInterface/CMakeFiles/npcDataInterface.dir/flags.make

lib/npcDataInterface/CMakeFiles/npcDataInterface.dir/npcDataInterface.cpp.o: lib/npcDataInterface/CMakeFiles/npcDataInterface.dir/flags.make
lib/npcDataInterface/CMakeFiles/npcDataInterface.dir/npcDataInterface.cpp.o: lib/npcDataInterface/npcDataInterface.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/mariyant/Desktop/project/textadventure/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object lib/npcDataInterface/CMakeFiles/npcDataInterface.dir/npcDataInterface.cpp.o"
	cd /home/mariyant/Desktop/project/textadventure/lib/npcDataInterface && /usr/bin/clang++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/npcDataInterface.dir/npcDataInterface.cpp.o -c /home/mariyant/Desktop/project/textadventure/lib/npcDataInterface/npcDataInterface.cpp

lib/npcDataInterface/CMakeFiles/npcDataInterface.dir/npcDataInterface.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/npcDataInterface.dir/npcDataInterface.cpp.i"
	cd /home/mariyant/Desktop/project/textadventure/lib/npcDataInterface && /usr/bin/clang++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/mariyant/Desktop/project/textadventure/lib/npcDataInterface/npcDataInterface.cpp > CMakeFiles/npcDataInterface.dir/npcDataInterface.cpp.i

lib/npcDataInterface/CMakeFiles/npcDataInterface.dir/npcDataInterface.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/npcDataInterface.dir/npcDataInterface.cpp.s"
	cd /home/mariyant/Desktop/project/textadventure/lib/npcDataInterface && /usr/bin/clang++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/mariyant/Desktop/project/textadventure/lib/npcDataInterface/npcDataInterface.cpp -o CMakeFiles/npcDataInterface.dir/npcDataInterface.cpp.s

lib/npcDataInterface/CMakeFiles/npcDataInterface.dir/npcDataInterface.cpp.o.requires:
.PHONY : lib/npcDataInterface/CMakeFiles/npcDataInterface.dir/npcDataInterface.cpp.o.requires

lib/npcDataInterface/CMakeFiles/npcDataInterface.dir/npcDataInterface.cpp.o.provides: lib/npcDataInterface/CMakeFiles/npcDataInterface.dir/npcDataInterface.cpp.o.requires
	$(MAKE) -f lib/npcDataInterface/CMakeFiles/npcDataInterface.dir/build.make lib/npcDataInterface/CMakeFiles/npcDataInterface.dir/npcDataInterface.cpp.o.provides.build
.PHONY : lib/npcDataInterface/CMakeFiles/npcDataInterface.dir/npcDataInterface.cpp.o.provides

lib/npcDataInterface/CMakeFiles/npcDataInterface.dir/npcDataInterface.cpp.o.provides.build: lib/npcDataInterface/CMakeFiles/npcDataInterface.dir/npcDataInterface.cpp.o

# Object files for target npcDataInterface
npcDataInterface_OBJECTS = \
"CMakeFiles/npcDataInterface.dir/npcDataInterface.cpp.o"

# External object files for target npcDataInterface
npcDataInterface_EXTERNAL_OBJECTS =

lib/libnpcDataInterface.a: lib/npcDataInterface/CMakeFiles/npcDataInterface.dir/npcDataInterface.cpp.o
lib/libnpcDataInterface.a: lib/npcDataInterface/CMakeFiles/npcDataInterface.dir/build.make
lib/libnpcDataInterface.a: lib/npcDataInterface/CMakeFiles/npcDataInterface.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX static library ../libnpcDataInterface.a"
	cd /home/mariyant/Desktop/project/textadventure/lib/npcDataInterface && $(CMAKE_COMMAND) -P CMakeFiles/npcDataInterface.dir/cmake_clean_target.cmake
	cd /home/mariyant/Desktop/project/textadventure/lib/npcDataInterface && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/npcDataInterface.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/npcDataInterface/CMakeFiles/npcDataInterface.dir/build: lib/libnpcDataInterface.a
.PHONY : lib/npcDataInterface/CMakeFiles/npcDataInterface.dir/build

lib/npcDataInterface/CMakeFiles/npcDataInterface.dir/requires: lib/npcDataInterface/CMakeFiles/npcDataInterface.dir/npcDataInterface.cpp.o.requires
.PHONY : lib/npcDataInterface/CMakeFiles/npcDataInterface.dir/requires

lib/npcDataInterface/CMakeFiles/npcDataInterface.dir/clean:
	cd /home/mariyant/Desktop/project/textadventure/lib/npcDataInterface && $(CMAKE_COMMAND) -P CMakeFiles/npcDataInterface.dir/cmake_clean.cmake
.PHONY : lib/npcDataInterface/CMakeFiles/npcDataInterface.dir/clean

lib/npcDataInterface/CMakeFiles/npcDataInterface.dir/depend:
	cd /home/mariyant/Desktop/project/textadventure && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mariyant/Desktop/project/textadventure /home/mariyant/Desktop/project/textadventure/lib/npcDataInterface /home/mariyant/Desktop/project/textadventure /home/mariyant/Desktop/project/textadventure/lib/npcDataInterface /home/mariyant/Desktop/project/textadventure/lib/npcDataInterface/CMakeFiles/npcDataInterface.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/npcDataInterface/CMakeFiles/npcDataInterface.dir/depend
