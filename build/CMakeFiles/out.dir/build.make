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
include CMakeFiles/out.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/out.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/out.dir/flags.make

CMakeFiles/out.dir/test.cpp.o: CMakeFiles/out.dir/flags.make
CMakeFiles/out.dir/test.cpp.o: ../test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/serendipita/Documents/glfwexample/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/out.dir/test.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/out.dir/test.cpp.o -c /home/serendipita/Documents/glfwexample/test.cpp

CMakeFiles/out.dir/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/out.dir/test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/serendipita/Documents/glfwexample/test.cpp > CMakeFiles/out.dir/test.cpp.i

CMakeFiles/out.dir/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/out.dir/test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/serendipita/Documents/glfwexample/test.cpp -o CMakeFiles/out.dir/test.cpp.s

CMakeFiles/out.dir/test.cpp.o.requires:

.PHONY : CMakeFiles/out.dir/test.cpp.o.requires

CMakeFiles/out.dir/test.cpp.o.provides: CMakeFiles/out.dir/test.cpp.o.requires
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/test.cpp.o.provides.build
.PHONY : CMakeFiles/out.dir/test.cpp.o.provides

CMakeFiles/out.dir/test.cpp.o.provides.build: CMakeFiles/out.dir/test.cpp.o


CMakeFiles/out.dir/ext/glfw/deps/glad.c.o: CMakeFiles/out.dir/flags.make
CMakeFiles/out.dir/ext/glfw/deps/glad.c.o: ../ext/glfw/deps/glad.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/serendipita/Documents/glfwexample/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/out.dir/ext/glfw/deps/glad.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/out.dir/ext/glfw/deps/glad.c.o   -c /home/serendipita/Documents/glfwexample/ext/glfw/deps/glad.c

CMakeFiles/out.dir/ext/glfw/deps/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/out.dir/ext/glfw/deps/glad.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/serendipita/Documents/glfwexample/ext/glfw/deps/glad.c > CMakeFiles/out.dir/ext/glfw/deps/glad.c.i

CMakeFiles/out.dir/ext/glfw/deps/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/out.dir/ext/glfw/deps/glad.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/serendipita/Documents/glfwexample/ext/glfw/deps/glad.c -o CMakeFiles/out.dir/ext/glfw/deps/glad.c.s

CMakeFiles/out.dir/ext/glfw/deps/glad.c.o.requires:

.PHONY : CMakeFiles/out.dir/ext/glfw/deps/glad.c.o.requires

CMakeFiles/out.dir/ext/glfw/deps/glad.c.o.provides: CMakeFiles/out.dir/ext/glfw/deps/glad.c.o.requires
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/ext/glfw/deps/glad.c.o.provides.build
.PHONY : CMakeFiles/out.dir/ext/glfw/deps/glad.c.o.provides

CMakeFiles/out.dir/ext/glfw/deps/glad.c.o.provides.build: CMakeFiles/out.dir/ext/glfw/deps/glad.c.o


# Object files for target out
out_OBJECTS = \
"CMakeFiles/out.dir/test.cpp.o" \
"CMakeFiles/out.dir/ext/glfw/deps/glad.c.o"

# External object files for target out
out_EXTERNAL_OBJECTS =

out: CMakeFiles/out.dir/test.cpp.o
out: CMakeFiles/out.dir/ext/glfw/deps/glad.c.o
out: CMakeFiles/out.dir/build.make
out: ext/glfw/src/libglfw3.a
out: /usr/local/lib/libopencv_dnn.so.4.2.0
out: /usr/local/lib/libopencv_gapi.so.4.2.0
out: /usr/local/lib/libopencv_highgui.so.4.2.0
out: /usr/local/lib/libopencv_ml.so.4.2.0
out: /usr/local/lib/libopencv_objdetect.so.4.2.0
out: /usr/local/lib/libopencv_photo.so.4.2.0
out: /usr/local/lib/libopencv_stitching.so.4.2.0
out: /usr/local/lib/libopencv_video.so.4.2.0
out: /usr/local/lib/libopencv_videoio.so.4.2.0
out: /usr/lib/x86_64-linux-gnu/libGL.so
out: /usr/lib/x86_64-linux-gnu/libGLU.so
out: /usr/lib/x86_64-linux-gnu/librt.so
out: /usr/lib/x86_64-linux-gnu/libm.so
out: /usr/lib/x86_64-linux-gnu/libX11.so
out: /usr/local/lib/libopencv_imgcodecs.so.4.2.0
out: /usr/local/lib/libopencv_calib3d.so.4.2.0
out: /usr/local/lib/libopencv_features2d.so.4.2.0
out: /usr/local/lib/libopencv_flann.so.4.2.0
out: /usr/local/lib/libopencv_imgproc.so.4.2.0
out: /usr/local/lib/libopencv_core.so.4.2.0
out: CMakeFiles/out.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/serendipita/Documents/glfwexample/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable out"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/out.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/out.dir/build: out

.PHONY : CMakeFiles/out.dir/build

CMakeFiles/out.dir/requires: CMakeFiles/out.dir/test.cpp.o.requires
CMakeFiles/out.dir/requires: CMakeFiles/out.dir/ext/glfw/deps/glad.c.o.requires

.PHONY : CMakeFiles/out.dir/requires

CMakeFiles/out.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/out.dir/cmake_clean.cmake
.PHONY : CMakeFiles/out.dir/clean

CMakeFiles/out.dir/depend:
	cd /home/serendipita/Documents/glfwexample/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/serendipita/Documents/glfwexample /home/serendipita/Documents/glfwexample /home/serendipita/Documents/glfwexample/build /home/serendipita/Documents/glfwexample/build /home/serendipita/Documents/glfwexample/build/CMakeFiles/out.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/out.dir/depend

