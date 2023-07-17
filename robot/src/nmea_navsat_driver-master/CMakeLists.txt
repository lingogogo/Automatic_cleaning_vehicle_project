cmake_minimum_required(VERSION 3.0.2)
project(nmea_navsat_driver)

find_package(catkin REQUIRED)

catkin_python_setup()
catkin_package()
find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  sensor_msgs
  std_msgs
)
install(PROGRAMS
   scripts/nmea_serial_driver
   scripts/nmea_socket_driver
   scripts/nmea_topic_driver
   scripts/nmea_topic_serial_reader
   DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

install(DIRECTORY launch/
   DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}/launch
   FILES_MATCHING PATTERN "*.launch"
)
include_directories(
${catkin_INCLUDE_DIRS}
)
install(FILES LICENSE.txt
   DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)

if (CATKIN_ENABLE_TESTING)
  find_package(roslint)
  roslint_python()
  roslint_add_test()
endif()

#add_executable(get_gpsdata2 src/get_datafromGPS)
#target_link_libraries(get_gpsdata2 ${catkin_LIBRARIES})
