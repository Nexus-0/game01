# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

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
CMAKE_COMMAND = /opt/homebrew/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/liwenchao/Downloads/game01

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/liwenchao/Downloads/game01/build

# Include any dependencies generated for this target.
include CMakeFiles/game01-Darwin.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/game01-Darwin.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/game01-Darwin.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/game01-Darwin.dir/flags.make

CMakeFiles/game01-Darwin.dir/codegen:
.PHONY : CMakeFiles/game01-Darwin.dir/codegen

CMakeFiles/game01-Darwin.dir/src/main.cpp.o: CMakeFiles/game01-Darwin.dir/flags.make
CMakeFiles/game01-Darwin.dir/src/main.cpp.o: /Users/liwenchao/Downloads/game01/src/main.cpp
CMakeFiles/game01-Darwin.dir/src/main.cpp.o: CMakeFiles/game01-Darwin.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/liwenchao/Downloads/game01/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/game01-Darwin.dir/src/main.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/game01-Darwin.dir/src/main.cpp.o -MF CMakeFiles/game01-Darwin.dir/src/main.cpp.o.d -o CMakeFiles/game01-Darwin.dir/src/main.cpp.o -c /Users/liwenchao/Downloads/game01/src/main.cpp

CMakeFiles/game01-Darwin.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/game01-Darwin.dir/src/main.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/liwenchao/Downloads/game01/src/main.cpp > CMakeFiles/game01-Darwin.dir/src/main.cpp.i

CMakeFiles/game01-Darwin.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/game01-Darwin.dir/src/main.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/liwenchao/Downloads/game01/src/main.cpp -o CMakeFiles/game01-Darwin.dir/src/main.cpp.s

CMakeFiles/game01-Darwin.dir/src/Game.cpp.o: CMakeFiles/game01-Darwin.dir/flags.make
CMakeFiles/game01-Darwin.dir/src/Game.cpp.o: /Users/liwenchao/Downloads/game01/src/Game.cpp
CMakeFiles/game01-Darwin.dir/src/Game.cpp.o: CMakeFiles/game01-Darwin.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/liwenchao/Downloads/game01/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/game01-Darwin.dir/src/Game.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/game01-Darwin.dir/src/Game.cpp.o -MF CMakeFiles/game01-Darwin.dir/src/Game.cpp.o.d -o CMakeFiles/game01-Darwin.dir/src/Game.cpp.o -c /Users/liwenchao/Downloads/game01/src/Game.cpp

CMakeFiles/game01-Darwin.dir/src/Game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/game01-Darwin.dir/src/Game.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/liwenchao/Downloads/game01/src/Game.cpp > CMakeFiles/game01-Darwin.dir/src/Game.cpp.i

CMakeFiles/game01-Darwin.dir/src/Game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/game01-Darwin.dir/src/Game.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/liwenchao/Downloads/game01/src/Game.cpp -o CMakeFiles/game01-Darwin.dir/src/Game.cpp.s

CMakeFiles/game01-Darwin.dir/src/scene.cpp.o: CMakeFiles/game01-Darwin.dir/flags.make
CMakeFiles/game01-Darwin.dir/src/scene.cpp.o: /Users/liwenchao/Downloads/game01/src/scene.cpp
CMakeFiles/game01-Darwin.dir/src/scene.cpp.o: CMakeFiles/game01-Darwin.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/liwenchao/Downloads/game01/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/game01-Darwin.dir/src/scene.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/game01-Darwin.dir/src/scene.cpp.o -MF CMakeFiles/game01-Darwin.dir/src/scene.cpp.o.d -o CMakeFiles/game01-Darwin.dir/src/scene.cpp.o -c /Users/liwenchao/Downloads/game01/src/scene.cpp

CMakeFiles/game01-Darwin.dir/src/scene.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/game01-Darwin.dir/src/scene.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/liwenchao/Downloads/game01/src/scene.cpp > CMakeFiles/game01-Darwin.dir/src/scene.cpp.i

CMakeFiles/game01-Darwin.dir/src/scene.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/game01-Darwin.dir/src/scene.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/liwenchao/Downloads/game01/src/scene.cpp -o CMakeFiles/game01-Darwin.dir/src/scene.cpp.s

CMakeFiles/game01-Darwin.dir/src/scenetitle.cpp.o: CMakeFiles/game01-Darwin.dir/flags.make
CMakeFiles/game01-Darwin.dir/src/scenetitle.cpp.o: /Users/liwenchao/Downloads/game01/src/scenetitle.cpp
CMakeFiles/game01-Darwin.dir/src/scenetitle.cpp.o: CMakeFiles/game01-Darwin.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/liwenchao/Downloads/game01/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/game01-Darwin.dir/src/scenetitle.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/game01-Darwin.dir/src/scenetitle.cpp.o -MF CMakeFiles/game01-Darwin.dir/src/scenetitle.cpp.o.d -o CMakeFiles/game01-Darwin.dir/src/scenetitle.cpp.o -c /Users/liwenchao/Downloads/game01/src/scenetitle.cpp

CMakeFiles/game01-Darwin.dir/src/scenetitle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/game01-Darwin.dir/src/scenetitle.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/liwenchao/Downloads/game01/src/scenetitle.cpp > CMakeFiles/game01-Darwin.dir/src/scenetitle.cpp.i

CMakeFiles/game01-Darwin.dir/src/scenetitle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/game01-Darwin.dir/src/scenetitle.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/liwenchao/Downloads/game01/src/scenetitle.cpp -o CMakeFiles/game01-Darwin.dir/src/scenetitle.cpp.s

CMakeFiles/game01-Darwin.dir/src/scenemain.cpp.o: CMakeFiles/game01-Darwin.dir/flags.make
CMakeFiles/game01-Darwin.dir/src/scenemain.cpp.o: /Users/liwenchao/Downloads/game01/src/scenemain.cpp
CMakeFiles/game01-Darwin.dir/src/scenemain.cpp.o: CMakeFiles/game01-Darwin.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/liwenchao/Downloads/game01/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/game01-Darwin.dir/src/scenemain.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/game01-Darwin.dir/src/scenemain.cpp.o -MF CMakeFiles/game01-Darwin.dir/src/scenemain.cpp.o.d -o CMakeFiles/game01-Darwin.dir/src/scenemain.cpp.o -c /Users/liwenchao/Downloads/game01/src/scenemain.cpp

CMakeFiles/game01-Darwin.dir/src/scenemain.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/game01-Darwin.dir/src/scenemain.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/liwenchao/Downloads/game01/src/scenemain.cpp > CMakeFiles/game01-Darwin.dir/src/scenemain.cpp.i

CMakeFiles/game01-Darwin.dir/src/scenemain.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/game01-Darwin.dir/src/scenemain.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/liwenchao/Downloads/game01/src/scenemain.cpp -o CMakeFiles/game01-Darwin.dir/src/scenemain.cpp.s

CMakeFiles/game01-Darwin.dir/src/sceneend.cpp.o: CMakeFiles/game01-Darwin.dir/flags.make
CMakeFiles/game01-Darwin.dir/src/sceneend.cpp.o: /Users/liwenchao/Downloads/game01/src/sceneend.cpp
CMakeFiles/game01-Darwin.dir/src/sceneend.cpp.o: CMakeFiles/game01-Darwin.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/liwenchao/Downloads/game01/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/game01-Darwin.dir/src/sceneend.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/game01-Darwin.dir/src/sceneend.cpp.o -MF CMakeFiles/game01-Darwin.dir/src/sceneend.cpp.o.d -o CMakeFiles/game01-Darwin.dir/src/sceneend.cpp.o -c /Users/liwenchao/Downloads/game01/src/sceneend.cpp

CMakeFiles/game01-Darwin.dir/src/sceneend.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/game01-Darwin.dir/src/sceneend.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/liwenchao/Downloads/game01/src/sceneend.cpp > CMakeFiles/game01-Darwin.dir/src/sceneend.cpp.i

CMakeFiles/game01-Darwin.dir/src/sceneend.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/game01-Darwin.dir/src/sceneend.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/liwenchao/Downloads/game01/src/sceneend.cpp -o CMakeFiles/game01-Darwin.dir/src/sceneend.cpp.s

# Object files for target game01-Darwin
game01__Darwin_OBJECTS = \
"CMakeFiles/game01-Darwin.dir/src/main.cpp.o" \
"CMakeFiles/game01-Darwin.dir/src/Game.cpp.o" \
"CMakeFiles/game01-Darwin.dir/src/scene.cpp.o" \
"CMakeFiles/game01-Darwin.dir/src/scenetitle.cpp.o" \
"CMakeFiles/game01-Darwin.dir/src/scenemain.cpp.o" \
"CMakeFiles/game01-Darwin.dir/src/sceneend.cpp.o"

# External object files for target game01-Darwin
game01__Darwin_EXTERNAL_OBJECTS =

/Users/liwenchao/Downloads/game01/game01-Darwin: CMakeFiles/game01-Darwin.dir/src/main.cpp.o
/Users/liwenchao/Downloads/game01/game01-Darwin: CMakeFiles/game01-Darwin.dir/src/Game.cpp.o
/Users/liwenchao/Downloads/game01/game01-Darwin: CMakeFiles/game01-Darwin.dir/src/scene.cpp.o
/Users/liwenchao/Downloads/game01/game01-Darwin: CMakeFiles/game01-Darwin.dir/src/scenetitle.cpp.o
/Users/liwenchao/Downloads/game01/game01-Darwin: CMakeFiles/game01-Darwin.dir/src/scenemain.cpp.o
/Users/liwenchao/Downloads/game01/game01-Darwin: CMakeFiles/game01-Darwin.dir/src/sceneend.cpp.o
/Users/liwenchao/Downloads/game01/game01-Darwin: CMakeFiles/game01-Darwin.dir/build.make
/Users/liwenchao/Downloads/game01/game01-Darwin: /opt/homebrew/Cellar/sdl2/2.30.12/lib/libSDL2.dylib
/Users/liwenchao/Downloads/game01/game01-Darwin: /opt/homebrew/Cellar/sdl2_image/2.8.4/lib/libSDL2_image.dylib
/Users/liwenchao/Downloads/game01/game01-Darwin: /opt/homebrew/Cellar/sdl2_mixer/2.8.1/lib/libSDL2_mixer.dylib
/Users/liwenchao/Downloads/game01/game01-Darwin: /opt/homebrew/Cellar/sdl2_ttf/2.24.0/lib/libSDL2_ttf.dylib
/Users/liwenchao/Downloads/game01/game01-Darwin: CMakeFiles/game01-Darwin.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/liwenchao/Downloads/game01/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable /Users/liwenchao/Downloads/game01/game01-Darwin"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/game01-Darwin.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/game01-Darwin.dir/build: /Users/liwenchao/Downloads/game01/game01-Darwin
.PHONY : CMakeFiles/game01-Darwin.dir/build

CMakeFiles/game01-Darwin.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/game01-Darwin.dir/cmake_clean.cmake
.PHONY : CMakeFiles/game01-Darwin.dir/clean

CMakeFiles/game01-Darwin.dir/depend:
	cd /Users/liwenchao/Downloads/game01/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/liwenchao/Downloads/game01 /Users/liwenchao/Downloads/game01 /Users/liwenchao/Downloads/game01/build /Users/liwenchao/Downloads/game01/build /Users/liwenchao/Downloads/game01/build/CMakeFiles/game01-Darwin.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/game01-Darwin.dir/depend

