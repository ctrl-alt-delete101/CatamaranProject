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
CMAKE_SOURCE_DIR = /home/arjun/ArjunCode/CatamaranCode

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/arjun/ArjunCode/CatamaranCode/build

# Include any dependencies generated for this target.
include CMakeFiles/laptop.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/laptop.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/laptop.dir/flags.make

CMakeFiles/laptop.dir/src/laptop.cpp.o: CMakeFiles/laptop.dir/flags.make
CMakeFiles/laptop.dir/src/laptop.cpp.o: ../src/laptop.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/arjun/ArjunCode/CatamaranCode/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/laptop.dir/src/laptop.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/laptop.dir/src/laptop.cpp.o -c /home/arjun/ArjunCode/CatamaranCode/src/laptop.cpp

CMakeFiles/laptop.dir/src/laptop.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/laptop.dir/src/laptop.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/arjun/ArjunCode/CatamaranCode/src/laptop.cpp > CMakeFiles/laptop.dir/src/laptop.cpp.i

CMakeFiles/laptop.dir/src/laptop.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/laptop.dir/src/laptop.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/arjun/ArjunCode/CatamaranCode/src/laptop.cpp -o CMakeFiles/laptop.dir/src/laptop.cpp.s

# Object files for target laptop
laptop_OBJECTS = \
"CMakeFiles/laptop.dir/src/laptop.cpp.o"

# External object files for target laptop
laptop_EXTERNAL_OBJECTS =

laptop: CMakeFiles/laptop.dir/src/laptop.cpp.o
laptop: CMakeFiles/laptop.dir/build.make
laptop: CMakeFiles/laptop.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/arjun/ArjunCode/CatamaranCode/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable laptop"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/laptop.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/laptop.dir/build: laptop

.PHONY : CMakeFiles/laptop.dir/build

CMakeFiles/laptop.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/laptop.dir/cmake_clean.cmake
.PHONY : CMakeFiles/laptop.dir/clean

CMakeFiles/laptop.dir/depend:
	cd /home/arjun/ArjunCode/CatamaranCode/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/arjun/ArjunCode/CatamaranCode /home/arjun/ArjunCode/CatamaranCode /home/arjun/ArjunCode/CatamaranCode/build /home/arjun/ArjunCode/CatamaranCode/build /home/arjun/ArjunCode/CatamaranCode/build/CMakeFiles/laptop.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/laptop.dir/depend

