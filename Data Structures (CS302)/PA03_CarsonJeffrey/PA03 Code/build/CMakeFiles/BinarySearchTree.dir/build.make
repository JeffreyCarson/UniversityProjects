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
CMAKE_SOURCE_DIR = "/home/jeffreycarson/Desktop/cs302/Project 3/hw4"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/jeffreycarson/Desktop/cs302/Project 3/hw4/build"

# Include any dependencies generated for this target.
include CMakeFiles/BinarySearchTree.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/BinarySearchTree.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/BinarySearchTree.dir/flags.make

CMakeFiles/BinarySearchTree.dir/src/BinarySearchTree.cpp.o: CMakeFiles/BinarySearchTree.dir/flags.make
CMakeFiles/BinarySearchTree.dir/src/BinarySearchTree.cpp.o: ../src/BinarySearchTree.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/jeffreycarson/Desktop/cs302/Project 3/hw4/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/BinarySearchTree.dir/src/BinarySearchTree.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/BinarySearchTree.dir/src/BinarySearchTree.cpp.o -c "/home/jeffreycarson/Desktop/cs302/Project 3/hw4/src/BinarySearchTree.cpp"

CMakeFiles/BinarySearchTree.dir/src/BinarySearchTree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BinarySearchTree.dir/src/BinarySearchTree.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/jeffreycarson/Desktop/cs302/Project 3/hw4/src/BinarySearchTree.cpp" > CMakeFiles/BinarySearchTree.dir/src/BinarySearchTree.cpp.i

CMakeFiles/BinarySearchTree.dir/src/BinarySearchTree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BinarySearchTree.dir/src/BinarySearchTree.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/jeffreycarson/Desktop/cs302/Project 3/hw4/src/BinarySearchTree.cpp" -o CMakeFiles/BinarySearchTree.dir/src/BinarySearchTree.cpp.s

CMakeFiles/BinarySearchTree.dir/src/BinarySearchTree.cpp.o.requires:

.PHONY : CMakeFiles/BinarySearchTree.dir/src/BinarySearchTree.cpp.o.requires

CMakeFiles/BinarySearchTree.dir/src/BinarySearchTree.cpp.o.provides: CMakeFiles/BinarySearchTree.dir/src/BinarySearchTree.cpp.o.requires
	$(MAKE) -f CMakeFiles/BinarySearchTree.dir/build.make CMakeFiles/BinarySearchTree.dir/src/BinarySearchTree.cpp.o.provides.build
.PHONY : CMakeFiles/BinarySearchTree.dir/src/BinarySearchTree.cpp.o.provides

CMakeFiles/BinarySearchTree.dir/src/BinarySearchTree.cpp.o.provides.build: CMakeFiles/BinarySearchTree.dir/src/BinarySearchTree.cpp.o


# Object files for target BinarySearchTree
BinarySearchTree_OBJECTS = \
"CMakeFiles/BinarySearchTree.dir/src/BinarySearchTree.cpp.o"

# External object files for target BinarySearchTree
BinarySearchTree_EXTERNAL_OBJECTS =

libBinarySearchTree.a: CMakeFiles/BinarySearchTree.dir/src/BinarySearchTree.cpp.o
libBinarySearchTree.a: CMakeFiles/BinarySearchTree.dir/build.make
libBinarySearchTree.a: CMakeFiles/BinarySearchTree.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/jeffreycarson/Desktop/cs302/Project 3/hw4/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libBinarySearchTree.a"
	$(CMAKE_COMMAND) -P CMakeFiles/BinarySearchTree.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/BinarySearchTree.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/BinarySearchTree.dir/build: libBinarySearchTree.a

.PHONY : CMakeFiles/BinarySearchTree.dir/build

CMakeFiles/BinarySearchTree.dir/requires: CMakeFiles/BinarySearchTree.dir/src/BinarySearchTree.cpp.o.requires

.PHONY : CMakeFiles/BinarySearchTree.dir/requires

CMakeFiles/BinarySearchTree.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/BinarySearchTree.dir/cmake_clean.cmake
.PHONY : CMakeFiles/BinarySearchTree.dir/clean

CMakeFiles/BinarySearchTree.dir/depend:
	cd "/home/jeffreycarson/Desktop/cs302/Project 3/hw4/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/jeffreycarson/Desktop/cs302/Project 3/hw4" "/home/jeffreycarson/Desktop/cs302/Project 3/hw4" "/home/jeffreycarson/Desktop/cs302/Project 3/hw4/build" "/home/jeffreycarson/Desktop/cs302/Project 3/hw4/build" "/home/jeffreycarson/Desktop/cs302/Project 3/hw4/build/CMakeFiles/BinarySearchTree.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/BinarySearchTree.dir/depend
