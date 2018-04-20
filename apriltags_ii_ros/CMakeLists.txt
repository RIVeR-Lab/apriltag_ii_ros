cmake_minimum_required(VERSION 2.8.3)
project(apriltags_ii_ros)

# add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  apriltags_ii
  cmake_modules
  cv_bridge
  geometry_msgs
  image_transport
  message_generation
  nodelet
  roscpp
  sensor_msgs
  std_msgs
  tf
)

find_package(Eigen REQUIRED)
find_package(OpenCV REQUIRED)


add_message_files(
  FILES
  AprilTagDetection.msg
  AprilTagDetectionArray.msg
)

generate_messages(
  DEPENDENCIES
  std_msgs
  geometry_msgs
)

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES apriltag_detector
  CATKIN_DEPENDS apriltags_ii image_transport roscpp sensor_msgs geometry_msgs tf cv_bridge message_runtime nodelet std_msgs
  DEPENDS Eigen OpenCV
)


###########
## Build ##
###########

include_directories(include)
include_directories(
  ${Eigen_INCLUDE_DIRS}
  ${OpenCV_INCLUDE_DIRS}
  ${catkin_INCLUDE_DIRS}
)

add_library(apriltag_detector
  src/apriltag_detector.cpp
)
target_link_libraries(apriltag_detector
  ${Eigen_LIBRARIES}
  ${OpenCV_LIBRARIES}
  ${catkin_LIBRARIES}
)
add_dependencies(apriltag_detector apriltags_ii_ros_generate_messages_cpp)


add_library(apriltag_detector_nodelet src/apriltag_detector_nodelet.cpp)
target_link_libraries(apriltag_detector_nodelet
  ${catkin_LIBRARIES}
  apriltag_detector
)

add_executable(apriltag_detector_node src/apriltag_detector_node.cpp)
target_link_libraries(apriltag_detector_node
  ${catkin_LIBRARIES}
  apriltag_detector
)

#############
## Install ##
#############

## Mark executables and/or libraries for installation
install(TARGETS apriltag_detector apriltag_detector_nodelet apriltag_detector_node
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

## Mark cpp header files for installation
install(DIRECTORY include/apriltags_ii_ros
  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
)

## Mark other files for installation (e.g. launch and bag files, etc.)
install(FILES nodelet_plugins.xml
        DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})

