# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.28.3/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.28.3/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/elijahshifflett/Desktop/Penn State /Spring 2024/AERSP 424/AERSP424_HW2"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/elijahshifflett/Desktop/Penn State /Spring 2024/AERSP 424/AERSP424_HW2/build"

# Include any dependencies generated for this target.
include CMakeFiles/Question1.cpp.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Question1.cpp.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Question1.cpp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Question1.cpp.dir/flags.make

CMakeFiles/Question1.cpp.dir/Question2.cpp.o: CMakeFiles/Question1.cpp.dir/flags.make
CMakeFiles/Question1.cpp.dir/Question2.cpp.o: /Users/elijahshifflett/Desktop/Penn\ State\ /Spring\ 2024/AERSP\ 424/AERSP424_HW2/Question2.cpp
CMakeFiles/Question1.cpp.dir/Question2.cpp.o: CMakeFiles/Question1.cpp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/elijahshifflett/Desktop/Penn State /Spring 2024/AERSP 424/AERSP424_HW2/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Question1.cpp.dir/Question2.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Question1.cpp.dir/Question2.cpp.o -MF CMakeFiles/Question1.cpp.dir/Question2.cpp.o.d -o CMakeFiles/Question1.cpp.dir/Question2.cpp.o -c "/Users/elijahshifflett/Desktop/Penn State /Spring 2024/AERSP 424/AERSP424_HW2/Question2.cpp"

CMakeFiles/Question1.cpp.dir/Question2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Question1.cpp.dir/Question2.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/elijahshifflett/Desktop/Penn State /Spring 2024/AERSP 424/AERSP424_HW2/Question2.cpp" > CMakeFiles/Question1.cpp.dir/Question2.cpp.i

CMakeFiles/Question1.cpp.dir/Question2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Question1.cpp.dir/Question2.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/elijahshifflett/Desktop/Penn State /Spring 2024/AERSP 424/AERSP424_HW2/Question2.cpp" -o CMakeFiles/Question1.cpp.dir/Question2.cpp.s

CMakeFiles/Question1.cpp.dir/Question3.cpp.o: CMakeFiles/Question1.cpp.dir/flags.make
CMakeFiles/Question1.cpp.dir/Question3.cpp.o: /Users/elijahshifflett/Desktop/Penn\ State\ /Spring\ 2024/AERSP\ 424/AERSP424_HW2/Question3.cpp
CMakeFiles/Question1.cpp.dir/Question3.cpp.o: CMakeFiles/Question1.cpp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/elijahshifflett/Desktop/Penn State /Spring 2024/AERSP 424/AERSP424_HW2/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Question1.cpp.dir/Question3.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Question1.cpp.dir/Question3.cpp.o -MF CMakeFiles/Question1.cpp.dir/Question3.cpp.o.d -o CMakeFiles/Question1.cpp.dir/Question3.cpp.o -c "/Users/elijahshifflett/Desktop/Penn State /Spring 2024/AERSP 424/AERSP424_HW2/Question3.cpp"

CMakeFiles/Question1.cpp.dir/Question3.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Question1.cpp.dir/Question3.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/elijahshifflett/Desktop/Penn State /Spring 2024/AERSP 424/AERSP424_HW2/Question3.cpp" > CMakeFiles/Question1.cpp.dir/Question3.cpp.i

CMakeFiles/Question1.cpp.dir/Question3.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Question1.cpp.dir/Question3.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/elijahshifflett/Desktop/Penn State /Spring 2024/AERSP 424/AERSP424_HW2/Question3.cpp" -o CMakeFiles/Question1.cpp.dir/Question3.cpp.s

# Object files for target Question1.cpp
Question1_cpp_OBJECTS = \
"CMakeFiles/Question1.cpp.dir/Question2.cpp.o" \
"CMakeFiles/Question1.cpp.dir/Question3.cpp.o"

# External object files for target Question1.cpp
Question1_cpp_EXTERNAL_OBJECTS =

Question1.cpp: CMakeFiles/Question1.cpp.dir/Question2.cpp.o
Question1.cpp: CMakeFiles/Question1.cpp.dir/Question3.cpp.o
Question1.cpp: CMakeFiles/Question1.cpp.dir/build.make
Question1.cpp: CMakeFiles/Question1.cpp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="/Users/elijahshifflett/Desktop/Penn State /Spring 2024/AERSP 424/AERSP424_HW2/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Question1.cpp"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Question1.cpp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Question1.cpp.dir/build: Question1.cpp
.PHONY : CMakeFiles/Question1.cpp.dir/build

CMakeFiles/Question1.cpp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Question1.cpp.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Question1.cpp.dir/clean

CMakeFiles/Question1.cpp.dir/depend:
	cd "/Users/elijahshifflett/Desktop/Penn State /Spring 2024/AERSP 424/AERSP424_HW2/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/elijahshifflett/Desktop/Penn State /Spring 2024/AERSP 424/AERSP424_HW2" "/Users/elijahshifflett/Desktop/Penn State /Spring 2024/AERSP 424/AERSP424_HW2" "/Users/elijahshifflett/Desktop/Penn State /Spring 2024/AERSP 424/AERSP424_HW2/build" "/Users/elijahshifflett/Desktop/Penn State /Spring 2024/AERSP 424/AERSP424_HW2/build" "/Users/elijahshifflett/Desktop/Penn State /Spring 2024/AERSP 424/AERSP424_HW2/build/CMakeFiles/Question1.cpp.dir/DependInfo.cmake" "--color=$(COLOR)"
.PHONY : CMakeFiles/Question1.cpp.dir/depend

