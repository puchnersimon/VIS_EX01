# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/simon/CLionProjects/VIS_EX01

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/simon/CLionProjects/VIS_EX01/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Client.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/Client.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Client.dir/flags.make

CMakeFiles/Client.dir/client_main.cpp.o: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/client_main.cpp.o: ../client_main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/simon/CLionProjects/VIS_EX01/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Client.dir/client_main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Client.dir/client_main.cpp.o -c /Users/simon/CLionProjects/VIS_EX01/client_main.cpp

CMakeFiles/Client.dir/client_main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client.dir/client_main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/simon/CLionProjects/VIS_EX01/client_main.cpp > CMakeFiles/Client.dir/client_main.cpp.i

CMakeFiles/Client.dir/client_main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client.dir/client_main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/simon/CLionProjects/VIS_EX01/client_main.cpp -o CMakeFiles/Client.dir/client_main.cpp.s

CMakeFiles/Client.dir/TCP_v4_client.cpp.o: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/TCP_v4_client.cpp.o: ../TCP_v4_client.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/simon/CLionProjects/VIS_EX01/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Client.dir/TCP_v4_client.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Client.dir/TCP_v4_client.cpp.o -c /Users/simon/CLionProjects/VIS_EX01/TCP_v4_client.cpp

CMakeFiles/Client.dir/TCP_v4_client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client.dir/TCP_v4_client.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/simon/CLionProjects/VIS_EX01/TCP_v4_client.cpp > CMakeFiles/Client.dir/TCP_v4_client.cpp.i

CMakeFiles/Client.dir/TCP_v4_client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client.dir/TCP_v4_client.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/simon/CLionProjects/VIS_EX01/TCP_v4_client.cpp -o CMakeFiles/Client.dir/TCP_v4_client.cpp.s

CMakeFiles/Client.dir/TCP_v6_client.cpp.o: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/TCP_v6_client.cpp.o: ../TCP_v6_client.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/simon/CLionProjects/VIS_EX01/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Client.dir/TCP_v6_client.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Client.dir/TCP_v6_client.cpp.o -c /Users/simon/CLionProjects/VIS_EX01/TCP_v6_client.cpp

CMakeFiles/Client.dir/TCP_v6_client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client.dir/TCP_v6_client.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/simon/CLionProjects/VIS_EX01/TCP_v6_client.cpp > CMakeFiles/Client.dir/TCP_v6_client.cpp.i

CMakeFiles/Client.dir/TCP_v6_client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client.dir/TCP_v6_client.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/simon/CLionProjects/VIS_EX01/TCP_v6_client.cpp -o CMakeFiles/Client.dir/TCP_v6_client.cpp.s

CMakeFiles/Client.dir/UDP_client.cpp.o: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/UDP_client.cpp.o: ../UDP_client.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/simon/CLionProjects/VIS_EX01/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Client.dir/UDP_client.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Client.dir/UDP_client.cpp.o -c /Users/simon/CLionProjects/VIS_EX01/UDP_client.cpp

CMakeFiles/Client.dir/UDP_client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client.dir/UDP_client.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/simon/CLionProjects/VIS_EX01/UDP_client.cpp > CMakeFiles/Client.dir/UDP_client.cpp.i

CMakeFiles/Client.dir/UDP_client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client.dir/UDP_client.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/simon/CLionProjects/VIS_EX01/UDP_client.cpp -o CMakeFiles/Client.dir/UDP_client.cpp.s

CMakeFiles/Client.dir/TCP_Envi_client.cpp.o: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/TCP_Envi_client.cpp.o: ../TCP_Envi_client.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/simon/CLionProjects/VIS_EX01/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Client.dir/TCP_Envi_client.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Client.dir/TCP_Envi_client.cpp.o -c /Users/simon/CLionProjects/VIS_EX01/TCP_Envi_client.cpp

CMakeFiles/Client.dir/TCP_Envi_client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client.dir/TCP_Envi_client.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/simon/CLionProjects/VIS_EX01/TCP_Envi_client.cpp > CMakeFiles/Client.dir/TCP_Envi_client.cpp.i

CMakeFiles/Client.dir/TCP_Envi_client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client.dir/TCP_Envi_client.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/simon/CLionProjects/VIS_EX01/TCP_Envi_client.cpp -o CMakeFiles/Client.dir/TCP_Envi_client.cpp.s

# Object files for target Client
Client_OBJECTS = \
"CMakeFiles/Client.dir/client_main.cpp.o" \
"CMakeFiles/Client.dir/TCP_v4_client.cpp.o" \
"CMakeFiles/Client.dir/TCP_v6_client.cpp.o" \
"CMakeFiles/Client.dir/UDP_client.cpp.o" \
"CMakeFiles/Client.dir/TCP_Envi_client.cpp.o"

# External object files for target Client
Client_EXTERNAL_OBJECTS =

Client: CMakeFiles/Client.dir/client_main.cpp.o
Client: CMakeFiles/Client.dir/TCP_v4_client.cpp.o
Client: CMakeFiles/Client.dir/TCP_v6_client.cpp.o
Client: CMakeFiles/Client.dir/UDP_client.cpp.o
Client: CMakeFiles/Client.dir/TCP_Envi_client.cpp.o
Client: CMakeFiles/Client.dir/build.make
Client: CMakeFiles/Client.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/simon/CLionProjects/VIS_EX01/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable Client"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Client.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Client.dir/build: Client
.PHONY : CMakeFiles/Client.dir/build

CMakeFiles/Client.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Client.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Client.dir/clean

CMakeFiles/Client.dir/depend:
	cd /Users/simon/CLionProjects/VIS_EX01/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/simon/CLionProjects/VIS_EX01 /Users/simon/CLionProjects/VIS_EX01 /Users/simon/CLionProjects/VIS_EX01/cmake-build-debug /Users/simon/CLionProjects/VIS_EX01/cmake-build-debug /Users/simon/CLionProjects/VIS_EX01/cmake-build-debug/CMakeFiles/Client.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Client.dir/depend

