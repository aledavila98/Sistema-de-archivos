# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /home/alejandro/clion-2017.1.3/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/alejandro/clion-2017.1.3/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/alejandro/Documentos/ED2/SistemaArchivos

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/alejandro/Documentos/ED2/SistemaArchivos/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/SistemaArchivos.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SistemaArchivos.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SistemaArchivos.dir/flags.make

CMakeFiles/SistemaArchivos.dir/main.cpp.o: CMakeFiles/SistemaArchivos.dir/flags.make
CMakeFiles/SistemaArchivos.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alejandro/Documentos/ED2/SistemaArchivos/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SistemaArchivos.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SistemaArchivos.dir/main.cpp.o -c /home/alejandro/Documentos/ED2/SistemaArchivos/main.cpp

CMakeFiles/SistemaArchivos.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SistemaArchivos.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alejandro/Documentos/ED2/SistemaArchivos/main.cpp > CMakeFiles/SistemaArchivos.dir/main.cpp.i

CMakeFiles/SistemaArchivos.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SistemaArchivos.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alejandro/Documentos/ED2/SistemaArchivos/main.cpp -o CMakeFiles/SistemaArchivos.dir/main.cpp.s

CMakeFiles/SistemaArchivos.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/SistemaArchivos.dir/main.cpp.o.requires

CMakeFiles/SistemaArchivos.dir/main.cpp.o.provides: CMakeFiles/SistemaArchivos.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/SistemaArchivos.dir/build.make CMakeFiles/SistemaArchivos.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/SistemaArchivos.dir/main.cpp.o.provides

CMakeFiles/SistemaArchivos.dir/main.cpp.o.provides.build: CMakeFiles/SistemaArchivos.dir/main.cpp.o


# Object files for target SistemaArchivos
SistemaArchivos_OBJECTS = \
"CMakeFiles/SistemaArchivos.dir/main.cpp.o"

# External object files for target SistemaArchivos
SistemaArchivos_EXTERNAL_OBJECTS =

SistemaArchivos: CMakeFiles/SistemaArchivos.dir/main.cpp.o
SistemaArchivos: CMakeFiles/SistemaArchivos.dir/build.make
SistemaArchivos: CMakeFiles/SistemaArchivos.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/alejandro/Documentos/ED2/SistemaArchivos/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable SistemaArchivos"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SistemaArchivos.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SistemaArchivos.dir/build: SistemaArchivos

.PHONY : CMakeFiles/SistemaArchivos.dir/build

CMakeFiles/SistemaArchivos.dir/requires: CMakeFiles/SistemaArchivos.dir/main.cpp.o.requires

.PHONY : CMakeFiles/SistemaArchivos.dir/requires

CMakeFiles/SistemaArchivos.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SistemaArchivos.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SistemaArchivos.dir/clean

CMakeFiles/SistemaArchivos.dir/depend:
	cd /home/alejandro/Documentos/ED2/SistemaArchivos/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alejandro/Documentos/ED2/SistemaArchivos /home/alejandro/Documentos/ED2/SistemaArchivos /home/alejandro/Documentos/ED2/SistemaArchivos/cmake-build-debug /home/alejandro/Documentos/ED2/SistemaArchivos/cmake-build-debug /home/alejandro/Documentos/ED2/SistemaArchivos/cmake-build-debug/CMakeFiles/SistemaArchivos.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SistemaArchivos.dir/depend

