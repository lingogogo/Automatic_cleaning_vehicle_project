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
CMAKE_SOURCE_DIR = /home/gordonlin/robot/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/gordonlin/robot/build

# Include any dependencies generated for this target.
include rosserial/rosserial_server/CMakeFiles/rosserial_server_serial_node.dir/depend.make

# Include the progress variables for this target.
include rosserial/rosserial_server/CMakeFiles/rosserial_server_serial_node.dir/progress.make

# Include the compile flags for this target's objects.
include rosserial/rosserial_server/CMakeFiles/rosserial_server_serial_node.dir/flags.make

rosserial/rosserial_server/CMakeFiles/rosserial_server_serial_node.dir/src/serial_node.cpp.o: rosserial/rosserial_server/CMakeFiles/rosserial_server_serial_node.dir/flags.make
rosserial/rosserial_server/CMakeFiles/rosserial_server_serial_node.dir/src/serial_node.cpp.o: /home/gordonlin/robot/src/rosserial/rosserial_server/src/serial_node.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gordonlin/robot/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object rosserial/rosserial_server/CMakeFiles/rosserial_server_serial_node.dir/src/serial_node.cpp.o"
	cd /home/gordonlin/robot/build/rosserial/rosserial_server && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/rosserial_server_serial_node.dir/src/serial_node.cpp.o -c /home/gordonlin/robot/src/rosserial/rosserial_server/src/serial_node.cpp

rosserial/rosserial_server/CMakeFiles/rosserial_server_serial_node.dir/src/serial_node.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rosserial_server_serial_node.dir/src/serial_node.cpp.i"
	cd /home/gordonlin/robot/build/rosserial/rosserial_server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gordonlin/robot/src/rosserial/rosserial_server/src/serial_node.cpp > CMakeFiles/rosserial_server_serial_node.dir/src/serial_node.cpp.i

rosserial/rosserial_server/CMakeFiles/rosserial_server_serial_node.dir/src/serial_node.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rosserial_server_serial_node.dir/src/serial_node.cpp.s"
	cd /home/gordonlin/robot/build/rosserial/rosserial_server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gordonlin/robot/src/rosserial/rosserial_server/src/serial_node.cpp -o CMakeFiles/rosserial_server_serial_node.dir/src/serial_node.cpp.s

rosserial/rosserial_server/CMakeFiles/rosserial_server_serial_node.dir/src/serial_node.cpp.o.requires:

.PHONY : rosserial/rosserial_server/CMakeFiles/rosserial_server_serial_node.dir/src/serial_node.cpp.o.requires

rosserial/rosserial_server/CMakeFiles/rosserial_server_serial_node.dir/src/serial_node.cpp.o.provides: rosserial/rosserial_server/CMakeFiles/rosserial_server_serial_node.dir/src/serial_node.cpp.o.requires
	$(MAKE) -f rosserial/rosserial_server/CMakeFiles/rosserial_server_serial_node.dir/build.make rosserial/rosserial_server/CMakeFiles/rosserial_server_serial_node.dir/src/serial_node.cpp.o.provides.build
.PHONY : rosserial/rosserial_server/CMakeFiles/rosserial_server_serial_node.dir/src/serial_node.cpp.o.provides

rosserial/rosserial_server/CMakeFiles/rosserial_server_serial_node.dir/src/serial_node.cpp.o.provides.build: rosserial/rosserial_server/CMakeFiles/rosserial_server_serial_node.dir/src/serial_node.cpp.o


# Object files for target rosserial_server_serial_node
rosserial_server_serial_node_OBJECTS = \
"CMakeFiles/rosserial_server_serial_node.dir/src/serial_node.cpp.o"

# External object files for target rosserial_server_serial_node
rosserial_server_serial_node_EXTERNAL_OBJECTS =

/home/gordonlin/robot/devel/lib/rosserial_server/serial_node: rosserial/rosserial_server/CMakeFiles/rosserial_server_serial_node.dir/src/serial_node.cpp.o
/home/gordonlin/robot/devel/lib/rosserial_server/serial_node: rosserial/rosserial_server/CMakeFiles/rosserial_server_serial_node.dir/build.make
/home/gordonlin/robot/devel/lib/rosserial_server/serial_node: /opt/ros/melodic/lib/libtopic_tools.so
/home/gordonlin/robot/devel/lib/rosserial_server/serial_node: /opt/ros/melodic/lib/libroscpp.so
/home/gordonlin/robot/devel/lib/rosserial_server/serial_node: /usr/lib/aarch64-linux-gnu/libboost_filesystem.so
/home/gordonlin/robot/devel/lib/rosserial_server/serial_node: /opt/ros/melodic/lib/librosconsole.so
/home/gordonlin/robot/devel/lib/rosserial_server/serial_node: /opt/ros/melodic/lib/librosconsole_log4cxx.so
/home/gordonlin/robot/devel/lib/rosserial_server/serial_node: /opt/ros/melodic/lib/librosconsole_backend_interface.so
/home/gordonlin/robot/devel/lib/rosserial_server/serial_node: /usr/lib/aarch64-linux-gnu/liblog4cxx.so
/home/gordonlin/robot/devel/lib/rosserial_server/serial_node: /usr/lib/aarch64-linux-gnu/libboost_regex.so
/home/gordonlin/robot/devel/lib/rosserial_server/serial_node: /opt/ros/melodic/lib/libroscpp_serialization.so
/home/gordonlin/robot/devel/lib/rosserial_server/serial_node: /opt/ros/melodic/lib/libxmlrpcpp.so
/home/gordonlin/robot/devel/lib/rosserial_server/serial_node: /opt/ros/melodic/lib/librostime.so
/home/gordonlin/robot/devel/lib/rosserial_server/serial_node: /opt/ros/melodic/lib/libcpp_common.so
/home/gordonlin/robot/devel/lib/rosserial_server/serial_node: /usr/lib/aarch64-linux-gnu/libboost_system.so
/home/gordonlin/robot/devel/lib/rosserial_server/serial_node: /usr/lib/aarch64-linux-gnu/libboost_thread.so
/home/gordonlin/robot/devel/lib/rosserial_server/serial_node: /usr/lib/aarch64-linux-gnu/libboost_chrono.so
/home/gordonlin/robot/devel/lib/rosserial_server/serial_node: /usr/lib/aarch64-linux-gnu/libboost_date_time.so
/home/gordonlin/robot/devel/lib/rosserial_server/serial_node: /usr/lib/aarch64-linux-gnu/libboost_atomic.so
/home/gordonlin/robot/devel/lib/rosserial_server/serial_node: /usr/lib/aarch64-linux-gnu/libpthread.so
/home/gordonlin/robot/devel/lib/rosserial_server/serial_node: /usr/lib/aarch64-linux-gnu/libconsole_bridge.so.0.4
/home/gordonlin/robot/devel/lib/rosserial_server/serial_node: /home/gordonlin/robot/devel/lib/librosserial_server_lookup.so
/home/gordonlin/robot/devel/lib/rosserial_server/serial_node: /usr/lib/aarch64-linux-gnu/libpython2.7.so
/home/gordonlin/robot/devel/lib/rosserial_server/serial_node: rosserial/rosserial_server/CMakeFiles/rosserial_server_serial_node.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/gordonlin/robot/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable /home/gordonlin/robot/devel/lib/rosserial_server/serial_node"
	cd /home/gordonlin/robot/build/rosserial/rosserial_server && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/rosserial_server_serial_node.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
rosserial/rosserial_server/CMakeFiles/rosserial_server_serial_node.dir/build: /home/gordonlin/robot/devel/lib/rosserial_server/serial_node

.PHONY : rosserial/rosserial_server/CMakeFiles/rosserial_server_serial_node.dir/build

rosserial/rosserial_server/CMakeFiles/rosserial_server_serial_node.dir/requires: rosserial/rosserial_server/CMakeFiles/rosserial_server_serial_node.dir/src/serial_node.cpp.o.requires

.PHONY : rosserial/rosserial_server/CMakeFiles/rosserial_server_serial_node.dir/requires

rosserial/rosserial_server/CMakeFiles/rosserial_server_serial_node.dir/clean:
	cd /home/gordonlin/robot/build/rosserial/rosserial_server && $(CMAKE_COMMAND) -P CMakeFiles/rosserial_server_serial_node.dir/cmake_clean.cmake
.PHONY : rosserial/rosserial_server/CMakeFiles/rosserial_server_serial_node.dir/clean

rosserial/rosserial_server/CMakeFiles/rosserial_server_serial_node.dir/depend:
	cd /home/gordonlin/robot/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/gordonlin/robot/src /home/gordonlin/robot/src/rosserial/rosserial_server /home/gordonlin/robot/build /home/gordonlin/robot/build/rosserial/rosserial_server /home/gordonlin/robot/build/rosserial/rosserial_server/CMakeFiles/rosserial_server_serial_node.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : rosserial/rosserial_server/CMakeFiles/rosserial_server_serial_node.dir/depend

