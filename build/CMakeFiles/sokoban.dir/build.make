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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.22.3/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.22.3/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/ericharm/Documents/hello-c

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ericharm/Documents/hello-c/build

# Include any dependencies generated for this target.
include CMakeFiles/sokoban.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/sokoban.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/sokoban.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sokoban.dir/flags.make

CMakeFiles/sokoban.dir/main.c.o: CMakeFiles/sokoban.dir/flags.make
CMakeFiles/sokoban.dir/main.c.o: ../main.c
CMakeFiles/sokoban.dir/main.c.o: CMakeFiles/sokoban.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ericharm/Documents/hello-c/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/sokoban.dir/main.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/sokoban.dir/main.c.o -MF CMakeFiles/sokoban.dir/main.c.o.d -o CMakeFiles/sokoban.dir/main.c.o -c /Users/ericharm/Documents/hello-c/main.c

CMakeFiles/sokoban.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sokoban.dir/main.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ericharm/Documents/hello-c/main.c > CMakeFiles/sokoban.dir/main.c.i

CMakeFiles/sokoban.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sokoban.dir/main.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ericharm/Documents/hello-c/main.c -o CMakeFiles/sokoban.dir/main.c.s

# Object files for target sokoban
sokoban_OBJECTS = \
"CMakeFiles/sokoban.dir/main.c.o"

# External object files for target sokoban
sokoban_EXTERNAL_OBJECTS =

sokoban: CMakeFiles/sokoban.dir/main.c.o
sokoban: CMakeFiles/sokoban.dir/build.make
sokoban: src/libsrc.a
sokoban: /Library/Developer/CommandLineTools/SDKs/MacOSX12.0.sdk/usr/lib/libcurses.tbd
sokoban: /Library/Developer/CommandLineTools/SDKs/MacOSX12.0.sdk/usr/lib/libform.tbd
sokoban: CMakeFiles/sokoban.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ericharm/Documents/hello-c/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable sokoban"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sokoban.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sokoban.dir/build: sokoban
.PHONY : CMakeFiles/sokoban.dir/build

CMakeFiles/sokoban.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sokoban.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sokoban.dir/clean

CMakeFiles/sokoban.dir/depend:
	cd /Users/ericharm/Documents/hello-c/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ericharm/Documents/hello-c /Users/ericharm/Documents/hello-c /Users/ericharm/Documents/hello-c/build /Users/ericharm/Documents/hello-c/build /Users/ericharm/Documents/hello-c/build/CMakeFiles/sokoban.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sokoban.dir/depend

