# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.29.3/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.29.3/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/nolenzhao/Desktop/Coding-Projects/sticky_notes_cli

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/nolenzhao/Desktop/Coding-Projects/sticky_notes_cli/build

# Include any dependencies generated for this target.
include CMakeFiles/sticky_notes_cli.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/sticky_notes_cli.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/sticky_notes_cli.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sticky_notes_cli.dir/flags.make

CMakeFiles/sticky_notes_cli.dir/src/commands/add_sticky.cpp.o: CMakeFiles/sticky_notes_cli.dir/flags.make
CMakeFiles/sticky_notes_cli.dir/src/commands/add_sticky.cpp.o: /Users/nolenzhao/Desktop/Coding-Projects/sticky_notes_cli/src/commands/add_sticky.cpp
CMakeFiles/sticky_notes_cli.dir/src/commands/add_sticky.cpp.o: CMakeFiles/sticky_notes_cli.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/nolenzhao/Desktop/Coding-Projects/sticky_notes_cli/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/sticky_notes_cli.dir/src/commands/add_sticky.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sticky_notes_cli.dir/src/commands/add_sticky.cpp.o -MF CMakeFiles/sticky_notes_cli.dir/src/commands/add_sticky.cpp.o.d -o CMakeFiles/sticky_notes_cli.dir/src/commands/add_sticky.cpp.o -c /Users/nolenzhao/Desktop/Coding-Projects/sticky_notes_cli/src/commands/add_sticky.cpp

CMakeFiles/sticky_notes_cli.dir/src/commands/add_sticky.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/sticky_notes_cli.dir/src/commands/add_sticky.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/nolenzhao/Desktop/Coding-Projects/sticky_notes_cli/src/commands/add_sticky.cpp > CMakeFiles/sticky_notes_cli.dir/src/commands/add_sticky.cpp.i

CMakeFiles/sticky_notes_cli.dir/src/commands/add_sticky.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/sticky_notes_cli.dir/src/commands/add_sticky.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/nolenzhao/Desktop/Coding-Projects/sticky_notes_cli/src/commands/add_sticky.cpp -o CMakeFiles/sticky_notes_cli.dir/src/commands/add_sticky.cpp.s

CMakeFiles/sticky_notes_cli.dir/src/commands/delete_sticky.cpp.o: CMakeFiles/sticky_notes_cli.dir/flags.make
CMakeFiles/sticky_notes_cli.dir/src/commands/delete_sticky.cpp.o: /Users/nolenzhao/Desktop/Coding-Projects/sticky_notes_cli/src/commands/delete_sticky.cpp
CMakeFiles/sticky_notes_cli.dir/src/commands/delete_sticky.cpp.o: CMakeFiles/sticky_notes_cli.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/nolenzhao/Desktop/Coding-Projects/sticky_notes_cli/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/sticky_notes_cli.dir/src/commands/delete_sticky.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sticky_notes_cli.dir/src/commands/delete_sticky.cpp.o -MF CMakeFiles/sticky_notes_cli.dir/src/commands/delete_sticky.cpp.o.d -o CMakeFiles/sticky_notes_cli.dir/src/commands/delete_sticky.cpp.o -c /Users/nolenzhao/Desktop/Coding-Projects/sticky_notes_cli/src/commands/delete_sticky.cpp

CMakeFiles/sticky_notes_cli.dir/src/commands/delete_sticky.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/sticky_notes_cli.dir/src/commands/delete_sticky.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/nolenzhao/Desktop/Coding-Projects/sticky_notes_cli/src/commands/delete_sticky.cpp > CMakeFiles/sticky_notes_cli.dir/src/commands/delete_sticky.cpp.i

CMakeFiles/sticky_notes_cli.dir/src/commands/delete_sticky.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/sticky_notes_cli.dir/src/commands/delete_sticky.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/nolenzhao/Desktop/Coding-Projects/sticky_notes_cli/src/commands/delete_sticky.cpp -o CMakeFiles/sticky_notes_cli.dir/src/commands/delete_sticky.cpp.s

CMakeFiles/sticky_notes_cli.dir/src/commands/display_help.cpp.o: CMakeFiles/sticky_notes_cli.dir/flags.make
CMakeFiles/sticky_notes_cli.dir/src/commands/display_help.cpp.o: /Users/nolenzhao/Desktop/Coding-Projects/sticky_notes_cli/src/commands/display_help.cpp
CMakeFiles/sticky_notes_cli.dir/src/commands/display_help.cpp.o: CMakeFiles/sticky_notes_cli.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/nolenzhao/Desktop/Coding-Projects/sticky_notes_cli/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/sticky_notes_cli.dir/src/commands/display_help.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sticky_notes_cli.dir/src/commands/display_help.cpp.o -MF CMakeFiles/sticky_notes_cli.dir/src/commands/display_help.cpp.o.d -o CMakeFiles/sticky_notes_cli.dir/src/commands/display_help.cpp.o -c /Users/nolenzhao/Desktop/Coding-Projects/sticky_notes_cli/src/commands/display_help.cpp

CMakeFiles/sticky_notes_cli.dir/src/commands/display_help.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/sticky_notes_cli.dir/src/commands/display_help.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/nolenzhao/Desktop/Coding-Projects/sticky_notes_cli/src/commands/display_help.cpp > CMakeFiles/sticky_notes_cli.dir/src/commands/display_help.cpp.i

CMakeFiles/sticky_notes_cli.dir/src/commands/display_help.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/sticky_notes_cli.dir/src/commands/display_help.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/nolenzhao/Desktop/Coding-Projects/sticky_notes_cli/src/commands/display_help.cpp -o CMakeFiles/sticky_notes_cli.dir/src/commands/display_help.cpp.s

CMakeFiles/sticky_notes_cli.dir/src/commands/edit_sticky.cpp.o: CMakeFiles/sticky_notes_cli.dir/flags.make
CMakeFiles/sticky_notes_cli.dir/src/commands/edit_sticky.cpp.o: /Users/nolenzhao/Desktop/Coding-Projects/sticky_notes_cli/src/commands/edit_sticky.cpp
CMakeFiles/sticky_notes_cli.dir/src/commands/edit_sticky.cpp.o: CMakeFiles/sticky_notes_cli.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/nolenzhao/Desktop/Coding-Projects/sticky_notes_cli/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/sticky_notes_cli.dir/src/commands/edit_sticky.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sticky_notes_cli.dir/src/commands/edit_sticky.cpp.o -MF CMakeFiles/sticky_notes_cli.dir/src/commands/edit_sticky.cpp.o.d -o CMakeFiles/sticky_notes_cli.dir/src/commands/edit_sticky.cpp.o -c /Users/nolenzhao/Desktop/Coding-Projects/sticky_notes_cli/src/commands/edit_sticky.cpp

CMakeFiles/sticky_notes_cli.dir/src/commands/edit_sticky.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/sticky_notes_cli.dir/src/commands/edit_sticky.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/nolenzhao/Desktop/Coding-Projects/sticky_notes_cli/src/commands/edit_sticky.cpp > CMakeFiles/sticky_notes_cli.dir/src/commands/edit_sticky.cpp.i

CMakeFiles/sticky_notes_cli.dir/src/commands/edit_sticky.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/sticky_notes_cli.dir/src/commands/edit_sticky.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/nolenzhao/Desktop/Coding-Projects/sticky_notes_cli/src/commands/edit_sticky.cpp -o CMakeFiles/sticky_notes_cli.dir/src/commands/edit_sticky.cpp.s

CMakeFiles/sticky_notes_cli.dir/src/commands/get_sticky.cpp.o: CMakeFiles/sticky_notes_cli.dir/flags.make
CMakeFiles/sticky_notes_cli.dir/src/commands/get_sticky.cpp.o: /Users/nolenzhao/Desktop/Coding-Projects/sticky_notes_cli/src/commands/get_sticky.cpp
CMakeFiles/sticky_notes_cli.dir/src/commands/get_sticky.cpp.o: CMakeFiles/sticky_notes_cli.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/nolenzhao/Desktop/Coding-Projects/sticky_notes_cli/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/sticky_notes_cli.dir/src/commands/get_sticky.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sticky_notes_cli.dir/src/commands/get_sticky.cpp.o -MF CMakeFiles/sticky_notes_cli.dir/src/commands/get_sticky.cpp.o.d -o CMakeFiles/sticky_notes_cli.dir/src/commands/get_sticky.cpp.o -c /Users/nolenzhao/Desktop/Coding-Projects/sticky_notes_cli/src/commands/get_sticky.cpp

CMakeFiles/sticky_notes_cli.dir/src/commands/get_sticky.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/sticky_notes_cli.dir/src/commands/get_sticky.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/nolenzhao/Desktop/Coding-Projects/sticky_notes_cli/src/commands/get_sticky.cpp > CMakeFiles/sticky_notes_cli.dir/src/commands/get_sticky.cpp.i

CMakeFiles/sticky_notes_cli.dir/src/commands/get_sticky.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/sticky_notes_cli.dir/src/commands/get_sticky.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/nolenzhao/Desktop/Coding-Projects/sticky_notes_cli/src/commands/get_sticky.cpp -o CMakeFiles/sticky_notes_cli.dir/src/commands/get_sticky.cpp.s

CMakeFiles/sticky_notes_cli.dir/src/commands/list_stickies.cpp.o: CMakeFiles/sticky_notes_cli.dir/flags.make
CMakeFiles/sticky_notes_cli.dir/src/commands/list_stickies.cpp.o: /Users/nolenzhao/Desktop/Coding-Projects/sticky_notes_cli/src/commands/list_stickies.cpp
CMakeFiles/sticky_notes_cli.dir/src/commands/list_stickies.cpp.o: CMakeFiles/sticky_notes_cli.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/nolenzhao/Desktop/Coding-Projects/sticky_notes_cli/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/sticky_notes_cli.dir/src/commands/list_stickies.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sticky_notes_cli.dir/src/commands/list_stickies.cpp.o -MF CMakeFiles/sticky_notes_cli.dir/src/commands/list_stickies.cpp.o.d -o CMakeFiles/sticky_notes_cli.dir/src/commands/list_stickies.cpp.o -c /Users/nolenzhao/Desktop/Coding-Projects/sticky_notes_cli/src/commands/list_stickies.cpp

CMakeFiles/sticky_notes_cli.dir/src/commands/list_stickies.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/sticky_notes_cli.dir/src/commands/list_stickies.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/nolenzhao/Desktop/Coding-Projects/sticky_notes_cli/src/commands/list_stickies.cpp > CMakeFiles/sticky_notes_cli.dir/src/commands/list_stickies.cpp.i

CMakeFiles/sticky_notes_cli.dir/src/commands/list_stickies.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/sticky_notes_cli.dir/src/commands/list_stickies.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/nolenzhao/Desktop/Coding-Projects/sticky_notes_cli/src/commands/list_stickies.cpp -o CMakeFiles/sticky_notes_cli.dir/src/commands/list_stickies.cpp.s

CMakeFiles/sticky_notes_cli.dir/src/commands/ls_highlighted.cpp.o: CMakeFiles/sticky_notes_cli.dir/flags.make
CMakeFiles/sticky_notes_cli.dir/src/commands/ls_highlighted.cpp.o: /Users/nolenzhao/Desktop/Coding-Projects/sticky_notes_cli/src/commands/ls_highlighted.cpp
CMakeFiles/sticky_notes_cli.dir/src/commands/ls_highlighted.cpp.o: CMakeFiles/sticky_notes_cli.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/nolenzhao/Desktop/Coding-Projects/sticky_notes_cli/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/sticky_notes_cli.dir/src/commands/ls_highlighted.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sticky_notes_cli.dir/src/commands/ls_highlighted.cpp.o -MF CMakeFiles/sticky_notes_cli.dir/src/commands/ls_highlighted.cpp.o.d -o CMakeFiles/sticky_notes_cli.dir/src/commands/ls_highlighted.cpp.o -c /Users/nolenzhao/Desktop/Coding-Projects/sticky_notes_cli/src/commands/ls_highlighted.cpp

CMakeFiles/sticky_notes_cli.dir/src/commands/ls_highlighted.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/sticky_notes_cli.dir/src/commands/ls_highlighted.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/nolenzhao/Desktop/Coding-Projects/sticky_notes_cli/src/commands/ls_highlighted.cpp > CMakeFiles/sticky_notes_cli.dir/src/commands/ls_highlighted.cpp.i

CMakeFiles/sticky_notes_cli.dir/src/commands/ls_highlighted.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/sticky_notes_cli.dir/src/commands/ls_highlighted.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/nolenzhao/Desktop/Coding-Projects/sticky_notes_cli/src/commands/ls_highlighted.cpp -o CMakeFiles/sticky_notes_cli.dir/src/commands/ls_highlighted.cpp.s

CMakeFiles/sticky_notes_cli.dir/src/helpers/callbacks.cpp.o: CMakeFiles/sticky_notes_cli.dir/flags.make
CMakeFiles/sticky_notes_cli.dir/src/helpers/callbacks.cpp.o: /Users/nolenzhao/Desktop/Coding-Projects/sticky_notes_cli/src/helpers/callbacks.cpp
CMakeFiles/sticky_notes_cli.dir/src/helpers/callbacks.cpp.o: CMakeFiles/sticky_notes_cli.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/nolenzhao/Desktop/Coding-Projects/sticky_notes_cli/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/sticky_notes_cli.dir/src/helpers/callbacks.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sticky_notes_cli.dir/src/helpers/callbacks.cpp.o -MF CMakeFiles/sticky_notes_cli.dir/src/helpers/callbacks.cpp.o.d -o CMakeFiles/sticky_notes_cli.dir/src/helpers/callbacks.cpp.o -c /Users/nolenzhao/Desktop/Coding-Projects/sticky_notes_cli/src/helpers/callbacks.cpp

CMakeFiles/sticky_notes_cli.dir/src/helpers/callbacks.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/sticky_notes_cli.dir/src/helpers/callbacks.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/nolenzhao/Desktop/Coding-Projects/sticky_notes_cli/src/helpers/callbacks.cpp > CMakeFiles/sticky_notes_cli.dir/src/helpers/callbacks.cpp.i

CMakeFiles/sticky_notes_cli.dir/src/helpers/callbacks.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/sticky_notes_cli.dir/src/helpers/callbacks.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/nolenzhao/Desktop/Coding-Projects/sticky_notes_cli/src/helpers/callbacks.cpp -o CMakeFiles/sticky_notes_cli.dir/src/helpers/callbacks.cpp.s

CMakeFiles/sticky_notes_cli.dir/src/helpers/constants.cpp.o: CMakeFiles/sticky_notes_cli.dir/flags.make
CMakeFiles/sticky_notes_cli.dir/src/helpers/constants.cpp.o: /Users/nolenzhao/Desktop/Coding-Projects/sticky_notes_cli/src/helpers/constants.cpp
CMakeFiles/sticky_notes_cli.dir/src/helpers/constants.cpp.o: CMakeFiles/sticky_notes_cli.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/nolenzhao/Desktop/Coding-Projects/sticky_notes_cli/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/sticky_notes_cli.dir/src/helpers/constants.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sticky_notes_cli.dir/src/helpers/constants.cpp.o -MF CMakeFiles/sticky_notes_cli.dir/src/helpers/constants.cpp.o.d -o CMakeFiles/sticky_notes_cli.dir/src/helpers/constants.cpp.o -c /Users/nolenzhao/Desktop/Coding-Projects/sticky_notes_cli/src/helpers/constants.cpp

CMakeFiles/sticky_notes_cli.dir/src/helpers/constants.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/sticky_notes_cli.dir/src/helpers/constants.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/nolenzhao/Desktop/Coding-Projects/sticky_notes_cli/src/helpers/constants.cpp > CMakeFiles/sticky_notes_cli.dir/src/helpers/constants.cpp.i

CMakeFiles/sticky_notes_cli.dir/src/helpers/constants.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/sticky_notes_cli.dir/src/helpers/constants.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/nolenzhao/Desktop/Coding-Projects/sticky_notes_cli/src/helpers/constants.cpp -o CMakeFiles/sticky_notes_cli.dir/src/helpers/constants.cpp.s

CMakeFiles/sticky_notes_cli.dir/src/helpers/utils.cpp.o: CMakeFiles/sticky_notes_cli.dir/flags.make
CMakeFiles/sticky_notes_cli.dir/src/helpers/utils.cpp.o: /Users/nolenzhao/Desktop/Coding-Projects/sticky_notes_cli/src/helpers/utils.cpp
CMakeFiles/sticky_notes_cli.dir/src/helpers/utils.cpp.o: CMakeFiles/sticky_notes_cli.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/nolenzhao/Desktop/Coding-Projects/sticky_notes_cli/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/sticky_notes_cli.dir/src/helpers/utils.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sticky_notes_cli.dir/src/helpers/utils.cpp.o -MF CMakeFiles/sticky_notes_cli.dir/src/helpers/utils.cpp.o.d -o CMakeFiles/sticky_notes_cli.dir/src/helpers/utils.cpp.o -c /Users/nolenzhao/Desktop/Coding-Projects/sticky_notes_cli/src/helpers/utils.cpp

CMakeFiles/sticky_notes_cli.dir/src/helpers/utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/sticky_notes_cli.dir/src/helpers/utils.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/nolenzhao/Desktop/Coding-Projects/sticky_notes_cli/src/helpers/utils.cpp > CMakeFiles/sticky_notes_cli.dir/src/helpers/utils.cpp.i

CMakeFiles/sticky_notes_cli.dir/src/helpers/utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/sticky_notes_cli.dir/src/helpers/utils.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/nolenzhao/Desktop/Coding-Projects/sticky_notes_cli/src/helpers/utils.cpp -o CMakeFiles/sticky_notes_cli.dir/src/helpers/utils.cpp.s

CMakeFiles/sticky_notes_cli.dir/src/main.cpp.o: CMakeFiles/sticky_notes_cli.dir/flags.make
CMakeFiles/sticky_notes_cli.dir/src/main.cpp.o: /Users/nolenzhao/Desktop/Coding-Projects/sticky_notes_cli/src/main.cpp
CMakeFiles/sticky_notes_cli.dir/src/main.cpp.o: CMakeFiles/sticky_notes_cli.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/nolenzhao/Desktop/Coding-Projects/sticky_notes_cli/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/sticky_notes_cli.dir/src/main.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sticky_notes_cli.dir/src/main.cpp.o -MF CMakeFiles/sticky_notes_cli.dir/src/main.cpp.o.d -o CMakeFiles/sticky_notes_cli.dir/src/main.cpp.o -c /Users/nolenzhao/Desktop/Coding-Projects/sticky_notes_cli/src/main.cpp

CMakeFiles/sticky_notes_cli.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/sticky_notes_cli.dir/src/main.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/nolenzhao/Desktop/Coding-Projects/sticky_notes_cli/src/main.cpp > CMakeFiles/sticky_notes_cli.dir/src/main.cpp.i

CMakeFiles/sticky_notes_cli.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/sticky_notes_cli.dir/src/main.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/nolenzhao/Desktop/Coding-Projects/sticky_notes_cli/src/main.cpp -o CMakeFiles/sticky_notes_cli.dir/src/main.cpp.s

CMakeFiles/sticky_notes_cli.dir/src/monitoring/signals.cpp.o: CMakeFiles/sticky_notes_cli.dir/flags.make
CMakeFiles/sticky_notes_cli.dir/src/monitoring/signals.cpp.o: /Users/nolenzhao/Desktop/Coding-Projects/sticky_notes_cli/src/monitoring/signals.cpp
CMakeFiles/sticky_notes_cli.dir/src/monitoring/signals.cpp.o: CMakeFiles/sticky_notes_cli.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/nolenzhao/Desktop/Coding-Projects/sticky_notes_cli/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/sticky_notes_cli.dir/src/monitoring/signals.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sticky_notes_cli.dir/src/monitoring/signals.cpp.o -MF CMakeFiles/sticky_notes_cli.dir/src/monitoring/signals.cpp.o.d -o CMakeFiles/sticky_notes_cli.dir/src/monitoring/signals.cpp.o -c /Users/nolenzhao/Desktop/Coding-Projects/sticky_notes_cli/src/monitoring/signals.cpp

CMakeFiles/sticky_notes_cli.dir/src/monitoring/signals.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/sticky_notes_cli.dir/src/monitoring/signals.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/nolenzhao/Desktop/Coding-Projects/sticky_notes_cli/src/monitoring/signals.cpp > CMakeFiles/sticky_notes_cli.dir/src/monitoring/signals.cpp.i

CMakeFiles/sticky_notes_cli.dir/src/monitoring/signals.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/sticky_notes_cli.dir/src/monitoring/signals.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/nolenzhao/Desktop/Coding-Projects/sticky_notes_cli/src/monitoring/signals.cpp -o CMakeFiles/sticky_notes_cli.dir/src/monitoring/signals.cpp.s

CMakeFiles/sticky_notes_cli.dir/src/monitoring/watcher.cpp.o: CMakeFiles/sticky_notes_cli.dir/flags.make
CMakeFiles/sticky_notes_cli.dir/src/monitoring/watcher.cpp.o: /Users/nolenzhao/Desktop/Coding-Projects/sticky_notes_cli/src/monitoring/watcher.cpp
CMakeFiles/sticky_notes_cli.dir/src/monitoring/watcher.cpp.o: CMakeFiles/sticky_notes_cli.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/nolenzhao/Desktop/Coding-Projects/sticky_notes_cli/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/sticky_notes_cli.dir/src/monitoring/watcher.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sticky_notes_cli.dir/src/monitoring/watcher.cpp.o -MF CMakeFiles/sticky_notes_cli.dir/src/monitoring/watcher.cpp.o.d -o CMakeFiles/sticky_notes_cli.dir/src/monitoring/watcher.cpp.o -c /Users/nolenzhao/Desktop/Coding-Projects/sticky_notes_cli/src/monitoring/watcher.cpp

CMakeFiles/sticky_notes_cli.dir/src/monitoring/watcher.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/sticky_notes_cli.dir/src/monitoring/watcher.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/nolenzhao/Desktop/Coding-Projects/sticky_notes_cli/src/monitoring/watcher.cpp > CMakeFiles/sticky_notes_cli.dir/src/monitoring/watcher.cpp.i

CMakeFiles/sticky_notes_cli.dir/src/monitoring/watcher.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/sticky_notes_cli.dir/src/monitoring/watcher.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/nolenzhao/Desktop/Coding-Projects/sticky_notes_cli/src/monitoring/watcher.cpp -o CMakeFiles/sticky_notes_cli.dir/src/monitoring/watcher.cpp.s

# Object files for target sticky_notes_cli
sticky_notes_cli_OBJECTS = \
"CMakeFiles/sticky_notes_cli.dir/src/commands/add_sticky.cpp.o" \
"CMakeFiles/sticky_notes_cli.dir/src/commands/delete_sticky.cpp.o" \
"CMakeFiles/sticky_notes_cli.dir/src/commands/display_help.cpp.o" \
"CMakeFiles/sticky_notes_cli.dir/src/commands/edit_sticky.cpp.o" \
"CMakeFiles/sticky_notes_cli.dir/src/commands/get_sticky.cpp.o" \
"CMakeFiles/sticky_notes_cli.dir/src/commands/list_stickies.cpp.o" \
"CMakeFiles/sticky_notes_cli.dir/src/commands/ls_highlighted.cpp.o" \
"CMakeFiles/sticky_notes_cli.dir/src/helpers/callbacks.cpp.o" \
"CMakeFiles/sticky_notes_cli.dir/src/helpers/constants.cpp.o" \
"CMakeFiles/sticky_notes_cli.dir/src/helpers/utils.cpp.o" \
"CMakeFiles/sticky_notes_cli.dir/src/main.cpp.o" \
"CMakeFiles/sticky_notes_cli.dir/src/monitoring/signals.cpp.o" \
"CMakeFiles/sticky_notes_cli.dir/src/monitoring/watcher.cpp.o"

# External object files for target sticky_notes_cli
sticky_notes_cli_EXTERNAL_OBJECTS =

sticky_notes_cli: CMakeFiles/sticky_notes_cli.dir/src/commands/add_sticky.cpp.o
sticky_notes_cli: CMakeFiles/sticky_notes_cli.dir/src/commands/delete_sticky.cpp.o
sticky_notes_cli: CMakeFiles/sticky_notes_cli.dir/src/commands/display_help.cpp.o
sticky_notes_cli: CMakeFiles/sticky_notes_cli.dir/src/commands/edit_sticky.cpp.o
sticky_notes_cli: CMakeFiles/sticky_notes_cli.dir/src/commands/get_sticky.cpp.o
sticky_notes_cli: CMakeFiles/sticky_notes_cli.dir/src/commands/list_stickies.cpp.o
sticky_notes_cli: CMakeFiles/sticky_notes_cli.dir/src/commands/ls_highlighted.cpp.o
sticky_notes_cli: CMakeFiles/sticky_notes_cli.dir/src/helpers/callbacks.cpp.o
sticky_notes_cli: CMakeFiles/sticky_notes_cli.dir/src/helpers/constants.cpp.o
sticky_notes_cli: CMakeFiles/sticky_notes_cli.dir/src/helpers/utils.cpp.o
sticky_notes_cli: CMakeFiles/sticky_notes_cli.dir/src/main.cpp.o
sticky_notes_cli: CMakeFiles/sticky_notes_cli.dir/src/monitoring/signals.cpp.o
sticky_notes_cli: CMakeFiles/sticky_notes_cli.dir/src/monitoring/watcher.cpp.o
sticky_notes_cli: CMakeFiles/sticky_notes_cli.dir/build.make
sticky_notes_cli: /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.5.sdk/usr/lib/libsqlite3.tbd
sticky_notes_cli: CMakeFiles/sticky_notes_cli.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/nolenzhao/Desktop/Coding-Projects/sticky_notes_cli/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Linking CXX executable sticky_notes_cli"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sticky_notes_cli.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sticky_notes_cli.dir/build: sticky_notes_cli
.PHONY : CMakeFiles/sticky_notes_cli.dir/build

CMakeFiles/sticky_notes_cli.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sticky_notes_cli.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sticky_notes_cli.dir/clean

CMakeFiles/sticky_notes_cli.dir/depend:
	cd /Users/nolenzhao/Desktop/Coding-Projects/sticky_notes_cli/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/nolenzhao/Desktop/Coding-Projects/sticky_notes_cli /Users/nolenzhao/Desktop/Coding-Projects/sticky_notes_cli /Users/nolenzhao/Desktop/Coding-Projects/sticky_notes_cli/build /Users/nolenzhao/Desktop/Coding-Projects/sticky_notes_cli/build /Users/nolenzhao/Desktop/Coding-Projects/sticky_notes_cli/build/CMakeFiles/sticky_notes_cli.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/sticky_notes_cli.dir/depend

