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
include ext/glfw/tests/CMakeFiles/opacity.dir/depend.make

# Include the progress variables for this target.
include ext/glfw/tests/CMakeFiles/opacity.dir/progress.make

# Include the compile flags for this target's objects.
include ext/glfw/tests/CMakeFiles/opacity.dir/flags.make

ext/glfw/tests/CMakeFiles/opacity.dir/opacity.c.o: ext/glfw/tests/CMakeFiles/opacity.dir/flags.make
ext/glfw/tests/CMakeFiles/opacity.dir/opacity.c.o: ../ext/glfw/tests/opacity.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/serendipita/Documents/glfwexample/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object ext/glfw/tests/CMakeFiles/opacity.dir/opacity.c.o"
	cd /home/serendipita/Documents/glfwexample/build/ext/glfw/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/opacity.dir/opacity.c.o   -c /home/serendipita/Documents/glfwexample/ext/glfw/tests/opacity.c

ext/glfw/tests/CMakeFiles/opacity.dir/opacity.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/opacity.dir/opacity.c.i"
	cd /home/serendipita/Documents/glfwexample/build/ext/glfw/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/serendipita/Documents/glfwexample/ext/glfw/tests/opacity.c > CMakeFiles/opacity.dir/opacity.c.i

ext/glfw/tests/CMakeFiles/opacity.dir/opacity.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/opacity.dir/opacity.c.s"
	cd /home/serendipita/Documents/glfwexample/build/ext/glfw/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/serendipita/Documents/glfwexample/ext/glfw/tests/opacity.c -o CMakeFiles/opacity.dir/opacity.c.s

ext/glfw/tests/CMakeFiles/opacity.dir/opacity.c.o.requires:

.PHONY : ext/glfw/tests/CMakeFiles/opacity.dir/opacity.c.o.requires

ext/glfw/tests/CMakeFiles/opacity.dir/opacity.c.o.provides: ext/glfw/tests/CMakeFiles/opacity.dir/opacity.c.o.requires
	$(MAKE) -f ext/glfw/tests/CMakeFiles/opacity.dir/build.make ext/glfw/tests/CMakeFiles/opacity.dir/opacity.c.o.provides.build
.PHONY : ext/glfw/tests/CMakeFiles/opacity.dir/opacity.c.o.provides

ext/glfw/tests/CMakeFiles/opacity.dir/opacity.c.o.provides.build: ext/glfw/tests/CMakeFiles/opacity.dir/opacity.c.o


ext/glfw/tests/CMakeFiles/opacity.dir/__/deps/glad.c.o: ext/glfw/tests/CMakeFiles/opacity.dir/flags.make
ext/glfw/tests/CMakeFiles/opacity.dir/__/deps/glad.c.o: ../ext/glfw/deps/glad.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/serendipita/Documents/glfwexample/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object ext/glfw/tests/CMakeFiles/opacity.dir/__/deps/glad.c.o"
	cd /home/serendipita/Documents/glfwexample/build/ext/glfw/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/opacity.dir/__/deps/glad.c.o   -c /home/serendipita/Documents/glfwexample/ext/glfw/deps/glad.c

ext/glfw/tests/CMakeFiles/opacity.dir/__/deps/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/opacity.dir/__/deps/glad.c.i"
	cd /home/serendipita/Documents/glfwexample/build/ext/glfw/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/serendipita/Documents/glfwexample/ext/glfw/deps/glad.c > CMakeFiles/opacity.dir/__/deps/glad.c.i

ext/glfw/tests/CMakeFiles/opacity.dir/__/deps/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/opacity.dir/__/deps/glad.c.s"
	cd /home/serendipita/Documents/glfwexample/build/ext/glfw/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/serendipita/Documents/glfwexample/ext/glfw/deps/glad.c -o CMakeFiles/opacity.dir/__/deps/glad.c.s

ext/glfw/tests/CMakeFiles/opacity.dir/__/deps/glad.c.o.requires:

.PHONY : ext/glfw/tests/CMakeFiles/opacity.dir/__/deps/glad.c.o.requires

ext/glfw/tests/CMakeFiles/opacity.dir/__/deps/glad.c.o.provides: ext/glfw/tests/CMakeFiles/opacity.dir/__/deps/glad.c.o.requires
	$(MAKE) -f ext/glfw/tests/CMakeFiles/opacity.dir/build.make ext/glfw/tests/CMakeFiles/opacity.dir/__/deps/glad.c.o.provides.build
.PHONY : ext/glfw/tests/CMakeFiles/opacity.dir/__/deps/glad.c.o.provides

ext/glfw/tests/CMakeFiles/opacity.dir/__/deps/glad.c.o.provides.build: ext/glfw/tests/CMakeFiles/opacity.dir/__/deps/glad.c.o


# Object files for target opacity
opacity_OBJECTS = \
"CMakeFiles/opacity.dir/opacity.c.o" \
"CMakeFiles/opacity.dir/__/deps/glad.c.o"

# External object files for target opacity
opacity_EXTERNAL_OBJECTS =

ext/glfw/tests/opacity: ext/glfw/tests/CMakeFiles/opacity.dir/opacity.c.o
ext/glfw/tests/opacity: ext/glfw/tests/CMakeFiles/opacity.dir/__/deps/glad.c.o
ext/glfw/tests/opacity: ext/glfw/tests/CMakeFiles/opacity.dir/build.make
ext/glfw/tests/opacity: ext/glfw/src/libglfw3.a
ext/glfw/tests/opacity: /usr/lib/x86_64-linux-gnu/libm.so
ext/glfw/tests/opacity: /usr/lib/x86_64-linux-gnu/librt.so
ext/glfw/tests/opacity: /usr/lib/x86_64-linux-gnu/libm.so
ext/glfw/tests/opacity: /usr/lib/x86_64-linux-gnu/libX11.so
ext/glfw/tests/opacity: ext/glfw/tests/CMakeFiles/opacity.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/serendipita/Documents/glfwexample/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable opacity"
	cd /home/serendipita/Documents/glfwexample/build/ext/glfw/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/opacity.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
ext/glfw/tests/CMakeFiles/opacity.dir/build: ext/glfw/tests/opacity

.PHONY : ext/glfw/tests/CMakeFiles/opacity.dir/build

ext/glfw/tests/CMakeFiles/opacity.dir/requires: ext/glfw/tests/CMakeFiles/opacity.dir/opacity.c.o.requires
ext/glfw/tests/CMakeFiles/opacity.dir/requires: ext/glfw/tests/CMakeFiles/opacity.dir/__/deps/glad.c.o.requires

.PHONY : ext/glfw/tests/CMakeFiles/opacity.dir/requires

ext/glfw/tests/CMakeFiles/opacity.dir/clean:
	cd /home/serendipita/Documents/glfwexample/build/ext/glfw/tests && $(CMAKE_COMMAND) -P CMakeFiles/opacity.dir/cmake_clean.cmake
.PHONY : ext/glfw/tests/CMakeFiles/opacity.dir/clean

ext/glfw/tests/CMakeFiles/opacity.dir/depend:
	cd /home/serendipita/Documents/glfwexample/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/serendipita/Documents/glfwexample /home/serendipita/Documents/glfwexample/ext/glfw/tests /home/serendipita/Documents/glfwexample/build /home/serendipita/Documents/glfwexample/build/ext/glfw/tests /home/serendipita/Documents/glfwexample/build/ext/glfw/tests/CMakeFiles/opacity.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : ext/glfw/tests/CMakeFiles/opacity.dir/depend

