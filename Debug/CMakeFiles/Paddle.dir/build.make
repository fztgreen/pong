# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/zach/Desktop/pong

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zach/Desktop/pong/Debug

# Include any dependencies generated for this target.
include CMakeFiles/Paddle.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Paddle.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Paddle.dir/flags.make

CMakeFiles/Paddle.dir/bin/Paddle.cpp.o: CMakeFiles/Paddle.dir/flags.make
CMakeFiles/Paddle.dir/bin/Paddle.cpp.o: ../bin/Paddle.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zach/Desktop/pong/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Paddle.dir/bin/Paddle.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Paddle.dir/bin/Paddle.cpp.o -c /home/zach/Desktop/pong/bin/Paddle.cpp

CMakeFiles/Paddle.dir/bin/Paddle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Paddle.dir/bin/Paddle.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zach/Desktop/pong/bin/Paddle.cpp > CMakeFiles/Paddle.dir/bin/Paddle.cpp.i

CMakeFiles/Paddle.dir/bin/Paddle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Paddle.dir/bin/Paddle.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zach/Desktop/pong/bin/Paddle.cpp -o CMakeFiles/Paddle.dir/bin/Paddle.cpp.s

CMakeFiles/Paddle.dir/bin/Paddle.cpp.o.requires:

.PHONY : CMakeFiles/Paddle.dir/bin/Paddle.cpp.o.requires

CMakeFiles/Paddle.dir/bin/Paddle.cpp.o.provides: CMakeFiles/Paddle.dir/bin/Paddle.cpp.o.requires
	$(MAKE) -f CMakeFiles/Paddle.dir/build.make CMakeFiles/Paddle.dir/bin/Paddle.cpp.o.provides.build
.PHONY : CMakeFiles/Paddle.dir/bin/Paddle.cpp.o.provides

CMakeFiles/Paddle.dir/bin/Paddle.cpp.o.provides.build: CMakeFiles/Paddle.dir/bin/Paddle.cpp.o


# Object files for target Paddle
Paddle_OBJECTS = \
"CMakeFiles/Paddle.dir/bin/Paddle.cpp.o"

# External object files for target Paddle
Paddle_EXTERNAL_OBJECTS =

Paddle: CMakeFiles/Paddle.dir/bin/Paddle.cpp.o
Paddle: CMakeFiles/Paddle.dir/build.make
Paddle: /usr/lib/x86_64-linux-gnu/libsfml-graphics.so
Paddle: /usr/lib/x86_64-linux-gnu/libsfml-window.so
Paddle: /usr/lib/x86_64-linux-gnu/libsfml-system.so
Paddle: /usr/lib/x86_64-linux-gnu/libsfml-audio.so
Paddle: /usr/lib/x86_64-linux-gnu/libsfml-network.so
Paddle: CMakeFiles/Paddle.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zach/Desktop/pong/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Paddle"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Paddle.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Paddle.dir/build: Paddle

.PHONY : CMakeFiles/Paddle.dir/build

CMakeFiles/Paddle.dir/requires: CMakeFiles/Paddle.dir/bin/Paddle.cpp.o.requires

.PHONY : CMakeFiles/Paddle.dir/requires

CMakeFiles/Paddle.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Paddle.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Paddle.dir/clean

CMakeFiles/Paddle.dir/depend:
	cd /home/zach/Desktop/pong/Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zach/Desktop/pong /home/zach/Desktop/pong /home/zach/Desktop/pong/Debug /home/zach/Desktop/pong/Debug /home/zach/Desktop/pong/Debug/CMakeFiles/Paddle.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Paddle.dir/depend

