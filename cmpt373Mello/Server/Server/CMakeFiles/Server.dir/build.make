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
CMAKE_SOURCE_DIR = /home/mjajalo/Desktop/cmpt373Mello

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mjajalo/Desktop/cmpt373Mello

# Include any dependencies generated for this target.
include Server/Server/CMakeFiles/Server.dir/depend.make

# Include the progress variables for this target.
include Server/Server/CMakeFiles/Server.dir/progress.make

# Include the compile flags for this target's objects.
include Server/Server/CMakeFiles/Server.dir/flags.make

Server/Server/CMakeFiles/Server.dir/TCPServer.cpp.o: Server/Server/CMakeFiles/Server.dir/flags.make
Server/Server/CMakeFiles/Server.dir/TCPServer.cpp.o: Server/Server/TCPServer.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/mjajalo/Desktop/cmpt373Mello/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object Server/Server/CMakeFiles/Server.dir/TCPServer.cpp.o"
	cd /home/mjajalo/Desktop/cmpt373Mello/Server/Server && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Server.dir/TCPServer.cpp.o -c /home/mjajalo/Desktop/cmpt373Mello/Server/Server/TCPServer.cpp

Server/Server/CMakeFiles/Server.dir/TCPServer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Server.dir/TCPServer.cpp.i"
	cd /home/mjajalo/Desktop/cmpt373Mello/Server/Server && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/mjajalo/Desktop/cmpt373Mello/Server/Server/TCPServer.cpp > CMakeFiles/Server.dir/TCPServer.cpp.i

Server/Server/CMakeFiles/Server.dir/TCPServer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Server.dir/TCPServer.cpp.s"
	cd /home/mjajalo/Desktop/cmpt373Mello/Server/Server && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/mjajalo/Desktop/cmpt373Mello/Server/Server/TCPServer.cpp -o CMakeFiles/Server.dir/TCPServer.cpp.s

Server/Server/CMakeFiles/Server.dir/TCPServer.cpp.o.requires:
.PHONY : Server/Server/CMakeFiles/Server.dir/TCPServer.cpp.o.requires

Server/Server/CMakeFiles/Server.dir/TCPServer.cpp.o.provides: Server/Server/CMakeFiles/Server.dir/TCPServer.cpp.o.requires
	$(MAKE) -f Server/Server/CMakeFiles/Server.dir/build.make Server/Server/CMakeFiles/Server.dir/TCPServer.cpp.o.provides.build
.PHONY : Server/Server/CMakeFiles/Server.dir/TCPServer.cpp.o.provides

Server/Server/CMakeFiles/Server.dir/TCPServer.cpp.o.provides.build: Server/Server/CMakeFiles/Server.dir/TCPServer.cpp.o

# Object files for target Server
Server_OBJECTS = \
"CMakeFiles/Server.dir/TCPServer.cpp.o"

# External object files for target Server
Server_EXTERNAL_OBJECTS =

lib/libServer.a: Server/Server/CMakeFiles/Server.dir/TCPServer.cpp.o
lib/libServer.a: Server/Server/CMakeFiles/Server.dir/build.make
lib/libServer.a: Server/Server/CMakeFiles/Server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX static library ../../lib/libServer.a"
	cd /home/mjajalo/Desktop/cmpt373Mello/Server/Server && $(CMAKE_COMMAND) -P CMakeFiles/Server.dir/cmake_clean_target.cmake
	cd /home/mjajalo/Desktop/cmpt373Mello/Server/Server && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Server/Server/CMakeFiles/Server.dir/build: lib/libServer.a
.PHONY : Server/Server/CMakeFiles/Server.dir/build

Server/Server/CMakeFiles/Server.dir/requires: Server/Server/CMakeFiles/Server.dir/TCPServer.cpp.o.requires
.PHONY : Server/Server/CMakeFiles/Server.dir/requires

Server/Server/CMakeFiles/Server.dir/clean:
	cd /home/mjajalo/Desktop/cmpt373Mello/Server/Server && $(CMAKE_COMMAND) -P CMakeFiles/Server.dir/cmake_clean.cmake
.PHONY : Server/Server/CMakeFiles/Server.dir/clean

Server/Server/CMakeFiles/Server.dir/depend:
	cd /home/mjajalo/Desktop/cmpt373Mello && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mjajalo/Desktop/cmpt373Mello /home/mjajalo/Desktop/cmpt373Mello/Server/Server /home/mjajalo/Desktop/cmpt373Mello /home/mjajalo/Desktop/cmpt373Mello/Server/Server /home/mjajalo/Desktop/cmpt373Mello/Server/Server/CMakeFiles/Server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Server/Server/CMakeFiles/Server.dir/depend

