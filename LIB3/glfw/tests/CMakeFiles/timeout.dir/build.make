# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /goinfre/mafernan/.brew/Cellar/cmake/3.12.0/bin/cmake

# The command to remove a file.
RM = /goinfre/mafernan/.brew/Cellar/cmake/3.12.0/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /goinfre/mafernan/nibbler/LIB3/glfw

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /goinfre/mafernan/nibbler/LIB3/glfw

# Include any dependencies generated for this target.
include tests/CMakeFiles/timeout.dir/depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/timeout.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/timeout.dir/flags.make

tests/CMakeFiles/timeout.dir/timeout.c.o: tests/CMakeFiles/timeout.dir/flags.make
tests/CMakeFiles/timeout.dir/timeout.c.o: tests/timeout.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/goinfre/mafernan/nibbler/LIB3/glfw/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object tests/CMakeFiles/timeout.dir/timeout.c.o"
	cd /goinfre/mafernan/nibbler/LIB3/glfw/tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/timeout.dir/timeout.c.o   -c /goinfre/mafernan/nibbler/LIB3/glfw/tests/timeout.c

tests/CMakeFiles/timeout.dir/timeout.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/timeout.dir/timeout.c.i"
	cd /goinfre/mafernan/nibbler/LIB3/glfw/tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /goinfre/mafernan/nibbler/LIB3/glfw/tests/timeout.c > CMakeFiles/timeout.dir/timeout.c.i

tests/CMakeFiles/timeout.dir/timeout.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/timeout.dir/timeout.c.s"
	cd /goinfre/mafernan/nibbler/LIB3/glfw/tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /goinfre/mafernan/nibbler/LIB3/glfw/tests/timeout.c -o CMakeFiles/timeout.dir/timeout.c.s

tests/CMakeFiles/timeout.dir/__/deps/glad.c.o: tests/CMakeFiles/timeout.dir/flags.make
tests/CMakeFiles/timeout.dir/__/deps/glad.c.o: deps/glad.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/goinfre/mafernan/nibbler/LIB3/glfw/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object tests/CMakeFiles/timeout.dir/__/deps/glad.c.o"
	cd /goinfre/mafernan/nibbler/LIB3/glfw/tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/timeout.dir/__/deps/glad.c.o   -c /goinfre/mafernan/nibbler/LIB3/glfw/deps/glad.c

tests/CMakeFiles/timeout.dir/__/deps/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/timeout.dir/__/deps/glad.c.i"
	cd /goinfre/mafernan/nibbler/LIB3/glfw/tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /goinfre/mafernan/nibbler/LIB3/glfw/deps/glad.c > CMakeFiles/timeout.dir/__/deps/glad.c.i

tests/CMakeFiles/timeout.dir/__/deps/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/timeout.dir/__/deps/glad.c.s"
	cd /goinfre/mafernan/nibbler/LIB3/glfw/tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /goinfre/mafernan/nibbler/LIB3/glfw/deps/glad.c -o CMakeFiles/timeout.dir/__/deps/glad.c.s

# Object files for target timeout
timeout_OBJECTS = \
"CMakeFiles/timeout.dir/timeout.c.o" \
"CMakeFiles/timeout.dir/__/deps/glad.c.o"

# External object files for target timeout
timeout_EXTERNAL_OBJECTS =

tests/timeout.app/Contents/MacOS/timeout: tests/CMakeFiles/timeout.dir/timeout.c.o
tests/timeout.app/Contents/MacOS/timeout: tests/CMakeFiles/timeout.dir/__/deps/glad.c.o
tests/timeout.app/Contents/MacOS/timeout: tests/CMakeFiles/timeout.dir/build.make
tests/timeout.app/Contents/MacOS/timeout: src/libglfw3.a
tests/timeout.app/Contents/MacOS/timeout: tests/CMakeFiles/timeout.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/goinfre/mafernan/nibbler/LIB3/glfw/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable timeout.app/Contents/MacOS/timeout"
	cd /goinfre/mafernan/nibbler/LIB3/glfw/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/timeout.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/timeout.dir/build: tests/timeout.app/Contents/MacOS/timeout

.PHONY : tests/CMakeFiles/timeout.dir/build

tests/CMakeFiles/timeout.dir/clean:
	cd /goinfre/mafernan/nibbler/LIB3/glfw/tests && $(CMAKE_COMMAND) -P CMakeFiles/timeout.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/timeout.dir/clean

tests/CMakeFiles/timeout.dir/depend:
	cd /goinfre/mafernan/nibbler/LIB3/glfw && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /goinfre/mafernan/nibbler/LIB3/glfw /goinfre/mafernan/nibbler/LIB3/glfw/tests /goinfre/mafernan/nibbler/LIB3/glfw /goinfre/mafernan/nibbler/LIB3/glfw/tests /goinfre/mafernan/nibbler/LIB3/glfw/tests/CMakeFiles/timeout.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/timeout.dir/depend

