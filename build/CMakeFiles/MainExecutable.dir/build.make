# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.30.4/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.30.4/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/riccardofantechi/Desktop/Universita/Primo anno/Laboratorio di Programmazione"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/riccardofantechi/Desktop/Universita/Primo anno/Laboratorio di Programmazione/build"

# Include any dependencies generated for this target.
include CMakeFiles/MainExecutable.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/MainExecutable.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/MainExecutable.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MainExecutable.dir/flags.make

CMakeFiles/MainExecutable.dir/main.cpp.o: CMakeFiles/MainExecutable.dir/flags.make
CMakeFiles/MainExecutable.dir/main.cpp.o: /Users/riccardofantechi/Desktop/Universita/Primo\ anno/Laboratorio\ di\ Programmazione/main.cpp
CMakeFiles/MainExecutable.dir/main.cpp.o: CMakeFiles/MainExecutable.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/riccardofantechi/Desktop/Universita/Primo anno/Laboratorio di Programmazione/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MainExecutable.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MainExecutable.dir/main.cpp.o -MF CMakeFiles/MainExecutable.dir/main.cpp.o.d -o CMakeFiles/MainExecutable.dir/main.cpp.o -c "/Users/riccardofantechi/Desktop/Universita/Primo anno/Laboratorio di Programmazione/main.cpp"

CMakeFiles/MainExecutable.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/MainExecutable.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/riccardofantechi/Desktop/Universita/Primo anno/Laboratorio di Programmazione/main.cpp" > CMakeFiles/MainExecutable.dir/main.cpp.i

CMakeFiles/MainExecutable.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/MainExecutable.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/riccardofantechi/Desktop/Universita/Primo anno/Laboratorio di Programmazione/main.cpp" -o CMakeFiles/MainExecutable.dir/main.cpp.s

CMakeFiles/MainExecutable.dir/Transazione.cpp.o: CMakeFiles/MainExecutable.dir/flags.make
CMakeFiles/MainExecutable.dir/Transazione.cpp.o: /Users/riccardofantechi/Desktop/Universita/Primo\ anno/Laboratorio\ di\ Programmazione/Transazione.cpp
CMakeFiles/MainExecutable.dir/Transazione.cpp.o: CMakeFiles/MainExecutable.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/riccardofantechi/Desktop/Universita/Primo anno/Laboratorio di Programmazione/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/MainExecutable.dir/Transazione.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MainExecutable.dir/Transazione.cpp.o -MF CMakeFiles/MainExecutable.dir/Transazione.cpp.o.d -o CMakeFiles/MainExecutable.dir/Transazione.cpp.o -c "/Users/riccardofantechi/Desktop/Universita/Primo anno/Laboratorio di Programmazione/Transazione.cpp"

CMakeFiles/MainExecutable.dir/Transazione.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/MainExecutable.dir/Transazione.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/riccardofantechi/Desktop/Universita/Primo anno/Laboratorio di Programmazione/Transazione.cpp" > CMakeFiles/MainExecutable.dir/Transazione.cpp.i

CMakeFiles/MainExecutable.dir/Transazione.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/MainExecutable.dir/Transazione.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/riccardofantechi/Desktop/Universita/Primo anno/Laboratorio di Programmazione/Transazione.cpp" -o CMakeFiles/MainExecutable.dir/Transazione.cpp.s

CMakeFiles/MainExecutable.dir/ContoCorrente.cpp.o: CMakeFiles/MainExecutable.dir/flags.make
CMakeFiles/MainExecutable.dir/ContoCorrente.cpp.o: /Users/riccardofantechi/Desktop/Universita/Primo\ anno/Laboratorio\ di\ Programmazione/ContoCorrente.cpp
CMakeFiles/MainExecutable.dir/ContoCorrente.cpp.o: CMakeFiles/MainExecutable.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/riccardofantechi/Desktop/Universita/Primo anno/Laboratorio di Programmazione/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/MainExecutable.dir/ContoCorrente.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MainExecutable.dir/ContoCorrente.cpp.o -MF CMakeFiles/MainExecutable.dir/ContoCorrente.cpp.o.d -o CMakeFiles/MainExecutable.dir/ContoCorrente.cpp.o -c "/Users/riccardofantechi/Desktop/Universita/Primo anno/Laboratorio di Programmazione/ContoCorrente.cpp"

CMakeFiles/MainExecutable.dir/ContoCorrente.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/MainExecutable.dir/ContoCorrente.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/riccardofantechi/Desktop/Universita/Primo anno/Laboratorio di Programmazione/ContoCorrente.cpp" > CMakeFiles/MainExecutable.dir/ContoCorrente.cpp.i

CMakeFiles/MainExecutable.dir/ContoCorrente.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/MainExecutable.dir/ContoCorrente.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/riccardofantechi/Desktop/Universita/Primo anno/Laboratorio di Programmazione/ContoCorrente.cpp" -o CMakeFiles/MainExecutable.dir/ContoCorrente.cpp.s

CMakeFiles/MainExecutable.dir/FileManager.cpp.o: CMakeFiles/MainExecutable.dir/flags.make
CMakeFiles/MainExecutable.dir/FileManager.cpp.o: /Users/riccardofantechi/Desktop/Universita/Primo\ anno/Laboratorio\ di\ Programmazione/FileManager.cpp
CMakeFiles/MainExecutable.dir/FileManager.cpp.o: CMakeFiles/MainExecutable.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/riccardofantechi/Desktop/Universita/Primo anno/Laboratorio di Programmazione/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/MainExecutable.dir/FileManager.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MainExecutable.dir/FileManager.cpp.o -MF CMakeFiles/MainExecutable.dir/FileManager.cpp.o.d -o CMakeFiles/MainExecutable.dir/FileManager.cpp.o -c "/Users/riccardofantechi/Desktop/Universita/Primo anno/Laboratorio di Programmazione/FileManager.cpp"

CMakeFiles/MainExecutable.dir/FileManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/MainExecutable.dir/FileManager.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/riccardofantechi/Desktop/Universita/Primo anno/Laboratorio di Programmazione/FileManager.cpp" > CMakeFiles/MainExecutable.dir/FileManager.cpp.i

CMakeFiles/MainExecutable.dir/FileManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/MainExecutable.dir/FileManager.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/riccardofantechi/Desktop/Universita/Primo anno/Laboratorio di Programmazione/FileManager.cpp" -o CMakeFiles/MainExecutable.dir/FileManager.cpp.s

# Object files for target MainExecutable
MainExecutable_OBJECTS = \
"CMakeFiles/MainExecutable.dir/main.cpp.o" \
"CMakeFiles/MainExecutable.dir/Transazione.cpp.o" \
"CMakeFiles/MainExecutable.dir/ContoCorrente.cpp.o" \
"CMakeFiles/MainExecutable.dir/FileManager.cpp.o"

# External object files for target MainExecutable
MainExecutable_EXTERNAL_OBJECTS =

MainExecutable: CMakeFiles/MainExecutable.dir/main.cpp.o
MainExecutable: CMakeFiles/MainExecutable.dir/Transazione.cpp.o
MainExecutable: CMakeFiles/MainExecutable.dir/ContoCorrente.cpp.o
MainExecutable: CMakeFiles/MainExecutable.dir/FileManager.cpp.o
MainExecutable: CMakeFiles/MainExecutable.dir/build.make
MainExecutable: CMakeFiles/MainExecutable.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="/Users/riccardofantechi/Desktop/Universita/Primo anno/Laboratorio di Programmazione/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable MainExecutable"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MainExecutable.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MainExecutable.dir/build: MainExecutable
.PHONY : CMakeFiles/MainExecutable.dir/build

CMakeFiles/MainExecutable.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MainExecutable.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MainExecutable.dir/clean

CMakeFiles/MainExecutable.dir/depend:
	cd "/Users/riccardofantechi/Desktop/Universita/Primo anno/Laboratorio di Programmazione/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/riccardofantechi/Desktop/Universita/Primo anno/Laboratorio di Programmazione" "/Users/riccardofantechi/Desktop/Universita/Primo anno/Laboratorio di Programmazione" "/Users/riccardofantechi/Desktop/Universita/Primo anno/Laboratorio di Programmazione/build" "/Users/riccardofantechi/Desktop/Universita/Primo anno/Laboratorio di Programmazione/build" "/Users/riccardofantechi/Desktop/Universita/Primo anno/Laboratorio di Programmazione/build/CMakeFiles/MainExecutable.dir/DependInfo.cmake" "--color=$(COLOR)"
.PHONY : CMakeFiles/MainExecutable.dir/depend

