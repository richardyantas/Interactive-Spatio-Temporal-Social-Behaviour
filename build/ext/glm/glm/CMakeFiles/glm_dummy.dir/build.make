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
CMAKE_SOURCE_DIR = /home/serendipita/Documents/glfwexample

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/serendipita/Documents/glfwexample/build

# Include any dependencies generated for this target.
include ext/glm/glm/CMakeFiles/glm_dummy.dir/depend.make

# Include the progress variables for this target.
include ext/glm/glm/CMakeFiles/glm_dummy.dir/progress.make

# Include the compile flags for this target's objects.
include ext/glm/glm/CMakeFiles/glm_dummy.dir/flags.make

ext/glm/glm/CMakeFiles/glm_dummy.dir/detail/dummy.cpp.o: ext/glm/glm/CMakeFiles/glm_dummy.dir/flags.make
ext/glm/glm/CMakeFiles/glm_dummy.dir/detail/dummy.cpp.o: ../ext/glm/glm/detail/dummy.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/serendipita/Documents/glfwexample/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object ext/glm/glm/CMakeFiles/glm_dummy.dir/detail/dummy.cpp.o"
	cd /home/serendipita/Documents/glfwexample/build/ext/glm/glm && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/glm_dummy.dir/detail/dummy.cpp.o -c /home/serendipita/Documents/glfwexample/ext/glm/glm/detail/dummy.cpp

ext/glm/glm/CMakeFiles/glm_dummy.dir/detail/dummy.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/glm_dummy.dir/detail/dummy.cpp.i"
	cd /home/serendipita/Documents/glfwexample/build/ext/glm/glm && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/serendipita/Documents/glfwexample/ext/glm/glm/detail/dummy.cpp > CMakeFiles/glm_dummy.dir/detail/dummy.cpp.i

ext/glm/glm/CMakeFiles/glm_dummy.dir/detail/dummy.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/glm_dummy.dir/detail/dummy.cpp.s"
	cd /home/serendipita/Documents/glfwexample/build/ext/glm/glm && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/serendipita/Documents/glfwexample/ext/glm/glm/detail/dummy.cpp -o CMakeFiles/glm_dummy.dir/detail/dummy.cpp.s

ext/glm/glm/CMakeFiles/glm_dummy.dir/detail/dummy.cpp.o.requires:

.PHONY : ext/glm/glm/CMakeFiles/glm_dummy.dir/detail/dummy.cpp.o.requires

ext/glm/glm/CMakeFiles/glm_dummy.dir/detail/dummy.cpp.o.provides: ext/glm/glm/CMakeFiles/glm_dummy.dir/detail/dummy.cpp.o.requires
	$(MAKE) -f ext/glm/glm/CMakeFiles/glm_dummy.dir/build.make ext/glm/glm/CMakeFiles/glm_dummy.dir/detail/dummy.cpp.o.provides.build
.PHONY : ext/glm/glm/CMakeFiles/glm_dummy.dir/detail/dummy.cpp.o.provides

ext/glm/glm/CMakeFiles/glm_dummy.dir/detail/dummy.cpp.o.provides.build: ext/glm/glm/CMakeFiles/glm_dummy.dir/detail/dummy.cpp.o


ext/glm/glm/CMakeFiles/glm_dummy.dir/detail/glm.cpp.o: ext/glm/glm/CMakeFiles/glm_dummy.dir/flags.make
ext/glm/glm/CMakeFiles/glm_dummy.dir/detail/glm.cpp.o: ../ext/glm/glm/detail/glm.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/serendipita/Documents/glfwexample/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object ext/glm/glm/CMakeFiles/glm_dummy.dir/detail/glm.cpp.o"
	cd /home/serendipita/Documents/glfwexample/build/ext/glm/glm && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/glm_dummy.dir/detail/glm.cpp.o -c /home/serendipita/Documents/glfwexample/ext/glm/glm/detail/glm.cpp

ext/glm/glm/CMakeFiles/glm_dummy.dir/detail/glm.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/glm_dummy.dir/detail/glm.cpp.i"
	cd /home/serendipita/Documents/glfwexample/build/ext/glm/glm && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/serendipita/Documents/glfwexample/ext/glm/glm/detail/glm.cpp > CMakeFiles/glm_dummy.dir/detail/glm.cpp.i

ext/glm/glm/CMakeFiles/glm_dummy.dir/detail/glm.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/glm_dummy.dir/detail/glm.cpp.s"
	cd /home/serendipita/Documents/glfwexample/build/ext/glm/glm && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/serendipita/Documents/glfwexample/ext/glm/glm/detail/glm.cpp -o CMakeFiles/glm_dummy.dir/detail/glm.cpp.s

ext/glm/glm/CMakeFiles/glm_dummy.dir/detail/glm.cpp.o.requires:

.PHONY : ext/glm/glm/CMakeFiles/glm_dummy.dir/detail/glm.cpp.o.requires

ext/glm/glm/CMakeFiles/glm_dummy.dir/detail/glm.cpp.o.provides: ext/glm/glm/CMakeFiles/glm_dummy.dir/detail/glm.cpp.o.requires
	$(MAKE) -f ext/glm/glm/CMakeFiles/glm_dummy.dir/build.make ext/glm/glm/CMakeFiles/glm_dummy.dir/detail/glm.cpp.o.provides.build
.PHONY : ext/glm/glm/CMakeFiles/glm_dummy.dir/detail/glm.cpp.o.provides

ext/glm/glm/CMakeFiles/glm_dummy.dir/detail/glm.cpp.o.provides.build: ext/glm/glm/CMakeFiles/glm_dummy.dir/detail/glm.cpp.o


# Object files for target glm_dummy
glm_dummy_OBJECTS = \
"CMakeFiles/glm_dummy.dir/detail/dummy.cpp.o" \
"CMakeFiles/glm_dummy.dir/detail/glm.cpp.o"

# External object files for target glm_dummy
glm_dummy_EXTERNAL_OBJECTS =

ext/glm/glm/glm_dummy: ext/glm/glm/CMakeFiles/glm_dummy.dir/detail/dummy.cpp.o
ext/glm/glm/glm_dummy: ext/glm/glm/CMakeFiles/glm_dummy.dir/detail/glm.cpp.o
ext/glm/glm/glm_dummy: ext/glm/glm/CMakeFiles/glm_dummy.dir/build.make
ext/glm/glm/glm_dummy: ext/glm/glm/CMakeFiles/glm_dummy.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/serendipita/Documents/glfwexample/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable glm_dummy"
	cd /home/serendipita/Documents/glfwexample/build/ext/glm/glm && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/glm_dummy.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
ext/glm/glm/CMakeFiles/glm_dummy.dir/build: ext/glm/glm/glm_dummy

.PHONY : ext/glm/glm/CMakeFiles/glm_dummy.dir/build

ext/glm/glm/CMakeFiles/glm_dummy.dir/requires: ext/glm/glm/CMakeFiles/glm_dummy.dir/detail/dummy.cpp.o.requires
ext/glm/glm/CMakeFiles/glm_dummy.dir/requires: ext/glm/glm/CMakeFiles/glm_dummy.dir/detail/glm.cpp.o.requires

.PHONY : ext/glm/glm/CMakeFiles/glm_dummy.dir/requires

ext/glm/glm/CMakeFiles/glm_dummy.dir/clean:
	cd /home/serendipita/Documents/glfwexample/build/ext/glm/glm && $(CMAKE_COMMAND) -P CMakeFiles/glm_dummy.dir/cmake_clean.cmake
.PHONY : ext/glm/glm/CMakeFiles/glm_dummy.dir/clean

ext/glm/glm/CMakeFiles/glm_dummy.dir/depend:
	cd /home/serendipita/Documents/glfwexample/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/serendipita/Documents/glfwexample /home/serendipita/Documents/glfwexample/ext/glm/glm /home/serendipita/Documents/glfwexample/build /home/serendipita/Documents/glfwexample/build/ext/glm/glm /home/serendipita/Documents/glfwexample/build/ext/glm/glm/CMakeFiles/glm_dummy.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : ext/glm/glm/CMakeFiles/glm_dummy.dir/depend

