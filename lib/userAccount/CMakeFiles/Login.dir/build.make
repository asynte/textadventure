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
include lib/userAccount/CMakeFiles/Login.dir/depend.make

# Include the progress variables for this target.
include lib/userAccount/CMakeFiles/Login.dir/progress.make

# Include the compile flags for this target's objects.
include lib/userAccount/CMakeFiles/Login.dir/flags.make

lib/userAccount/CMakeFiles/Login.dir/login.cpp.o: lib/userAccount/CMakeFiles/Login.dir/flags.make
lib/userAccount/CMakeFiles/Login.dir/login.cpp.o: lib/userAccount/login.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/mariyant/Desktop/project/textadventure/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object lib/userAccount/CMakeFiles/Login.dir/login.cpp.o"
	cd /home/mariyant/Desktop/project/textadventure/lib/userAccount && /usr/bin/clang++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Login.dir/login.cpp.o -c /home/mariyant/Desktop/project/textadventure/lib/userAccount/login.cpp

lib/userAccount/CMakeFiles/Login.dir/login.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Login.dir/login.cpp.i"
	cd /home/mariyant/Desktop/project/textadventure/lib/userAccount && /usr/bin/clang++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/mariyant/Desktop/project/textadventure/lib/userAccount/login.cpp > CMakeFiles/Login.dir/login.cpp.i

lib/userAccount/CMakeFiles/Login.dir/login.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Login.dir/login.cpp.s"
	cd /home/mariyant/Desktop/project/textadventure/lib/userAccount && /usr/bin/clang++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/mariyant/Desktop/project/textadventure/lib/userAccount/login.cpp -o CMakeFiles/Login.dir/login.cpp.s

lib/userAccount/CMakeFiles/Login.dir/login.cpp.o.requires:
.PHONY : lib/userAccount/CMakeFiles/Login.dir/login.cpp.o.requires

lib/userAccount/CMakeFiles/Login.dir/login.cpp.o.provides: lib/userAccount/CMakeFiles/Login.dir/login.cpp.o.requires
	$(MAKE) -f lib/userAccount/CMakeFiles/Login.dir/build.make lib/userAccount/CMakeFiles/Login.dir/login.cpp.o.provides.build
.PHONY : lib/userAccount/CMakeFiles/Login.dir/login.cpp.o.provides

lib/userAccount/CMakeFiles/Login.dir/login.cpp.o.provides.build: lib/userAccount/CMakeFiles/Login.dir/login.cpp.o

# Object files for target Login
Login_OBJECTS = \
"CMakeFiles/Login.dir/login.cpp.o"

# External object files for target Login
Login_EXTERNAL_OBJECTS =

lib/libLogin.a: lib/userAccount/CMakeFiles/Login.dir/login.cpp.o
lib/libLogin.a: lib/userAccount/CMakeFiles/Login.dir/build.make
lib/libLogin.a: lib/userAccount/CMakeFiles/Login.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX static library ../libLogin.a"
	cd /home/mariyant/Desktop/project/textadventure/lib/userAccount && $(CMAKE_COMMAND) -P CMakeFiles/Login.dir/cmake_clean_target.cmake
	cd /home/mariyant/Desktop/project/textadventure/lib/userAccount && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Login.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/userAccount/CMakeFiles/Login.dir/build: lib/libLogin.a
.PHONY : lib/userAccount/CMakeFiles/Login.dir/build

lib/userAccount/CMakeFiles/Login.dir/requires: lib/userAccount/CMakeFiles/Login.dir/login.cpp.o.requires
.PHONY : lib/userAccount/CMakeFiles/Login.dir/requires

lib/userAccount/CMakeFiles/Login.dir/clean:
	cd /home/mariyant/Desktop/project/textadventure/lib/userAccount && $(CMAKE_COMMAND) -P CMakeFiles/Login.dir/cmake_clean.cmake
.PHONY : lib/userAccount/CMakeFiles/Login.dir/clean

lib/userAccount/CMakeFiles/Login.dir/depend:
	cd /home/mariyant/Desktop/project/textadventure && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mariyant/Desktop/project/textadventure /home/mariyant/Desktop/project/textadventure/lib/userAccount /home/mariyant/Desktop/project/textadventure /home/mariyant/Desktop/project/textadventure/lib/userAccount /home/mariyant/Desktop/project/textadventure/lib/userAccount/CMakeFiles/Login.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/userAccount/CMakeFiles/Login.dir/depend
