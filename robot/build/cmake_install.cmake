# Install script for directory: /home/gordonlin/robot/src

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/gordonlin/robot/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  
      if (NOT EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}")
        file(MAKE_DIRECTORY "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}")
      endif()
      if (NOT EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/.catkin")
        file(WRITE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/.catkin" "")
      endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/gordonlin/robot/install/_setup_util.py")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/gordonlin/robot/install" TYPE PROGRAM FILES "/home/gordonlin/robot/build/catkin_generated/installspace/_setup_util.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/gordonlin/robot/install/env.sh")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/gordonlin/robot/install" TYPE PROGRAM FILES "/home/gordonlin/robot/build/catkin_generated/installspace/env.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/gordonlin/robot/install/setup.bash;/home/gordonlin/robot/install/local_setup.bash")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/gordonlin/robot/install" TYPE FILE FILES
    "/home/gordonlin/robot/build/catkin_generated/installspace/setup.bash"
    "/home/gordonlin/robot/build/catkin_generated/installspace/local_setup.bash"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/gordonlin/robot/install/setup.sh;/home/gordonlin/robot/install/local_setup.sh")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/gordonlin/robot/install" TYPE FILE FILES
    "/home/gordonlin/robot/build/catkin_generated/installspace/setup.sh"
    "/home/gordonlin/robot/build/catkin_generated/installspace/local_setup.sh"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/gordonlin/robot/install/setup.zsh;/home/gordonlin/robot/install/local_setup.zsh")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/gordonlin/robot/install" TYPE FILE FILES
    "/home/gordonlin/robot/build/catkin_generated/installspace/setup.zsh"
    "/home/gordonlin/robot/build/catkin_generated/installspace/local_setup.zsh"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/gordonlin/robot/install/.rosinstall")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/gordonlin/robot/install" TYPE FILE FILES "/home/gordonlin/robot/build/catkin_generated/installspace/.rosinstall")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/gordonlin/robot/build/gtest/cmake_install.cmake")
  include("/home/gordonlin/robot/build/geometry2/geometry2/cmake_install.cmake")
  include("/home/gordonlin/robot/build/imu_tools-melodic/imu_tools/cmake_install.cmake")
  include("/home/gordonlin/robot/build/rosserial/rosserial/cmake_install.cmake")
  include("/home/gordonlin/robot/build/rosserial/rosserial_arduino/cmake_install.cmake")
  include("/home/gordonlin/robot/build/rosserial/rosserial_chibios/cmake_install.cmake")
  include("/home/gordonlin/robot/build/rosserial/rosserial_mbed/cmake_install.cmake")
  include("/home/gordonlin/robot/build/rosserial/rosserial_msgs/cmake_install.cmake")
  include("/home/gordonlin/robot/build/rosserial/rosserial_python/cmake_install.cmake")
  include("/home/gordonlin/robot/build/rosserial/rosserial_tivac/cmake_install.cmake")
  include("/home/gordonlin/robot/build/rosserial/rosserial_vex_cortex/cmake_install.cmake")
  include("/home/gordonlin/robot/build/rosserial/rosserial_vex_v5/cmake_install.cmake")
  include("/home/gordonlin/robot/build/rosserial/rosserial_xbee/cmake_install.cmake")
  include("/home/gordonlin/robot/build/rosserial/rosserial_client/cmake_install.cmake")
  include("/home/gordonlin/robot/build/geometry2/tf2_msgs/cmake_install.cmake")
  include("/home/gordonlin/robot/build/geometry2/tf2/cmake_install.cmake")
  include("/home/gordonlin/robot/build/geometry2/tf2_bullet/cmake_install.cmake")
  include("/home/gordonlin/robot/build/geometry2/tf2_eigen/cmake_install.cmake")
  include("/home/gordonlin/robot/build/total_startup/cmake_install.cmake")
  include("/home/gordonlin/robot/build/mobile_manipulator_body/cmake_install.cmake")
  include("/home/gordonlin/robot/build/nmea_navsat_driver-master/cmake_install.cmake")
  include("/home/gordonlin/robot/build/geometry2/tf2_py/cmake_install.cmake")
  include("/home/gordonlin/robot/build/rosserial/rosserial_server/cmake_install.cmake")
  include("/home/gordonlin/robot/build/dataget/cmake_install.cmake")
  include("/home/gordonlin/robot/build/calculate_theta/cmake_install.cmake")
  include("/home/gordonlin/robot/build/geometry2/tf2_ros/cmake_install.cmake")
  include("/home/gordonlin/robot/build/imu_tools-melodic/imu_complementary_filter/cmake_install.cmake")
  include("/home/gordonlin/robot/build/rosserial/rosserial_embeddedlinux/cmake_install.cmake")
  include("/home/gordonlin/robot/build/rosserial/rosserial_test/cmake_install.cmake")
  include("/home/gordonlin/robot/build/rosserial/rosserial_windows/cmake_install.cmake")
  include("/home/gordonlin/robot/build/geometry2/tf2_geometry_msgs/cmake_install.cmake")
  include("/home/gordonlin/robot/build/imu_tools-melodic/imu_filter_madgwick/cmake_install.cmake")
  include("/home/gordonlin/robot/build/geometry2/tf2_kdl/cmake_install.cmake")
  include("/home/gordonlin/robot/build/geometry2/test_tf2/cmake_install.cmake")
  include("/home/gordonlin/robot/build/geometry2/tf2_sensor_msgs/cmake_install.cmake")
  include("/home/gordonlin/robot/build/geometry2/tf2_tools/cmake_install.cmake")
  include("/home/gordonlin/robot/build/imu_tools-melodic/rviz_imu_plugin/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/gordonlin/robot/build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
