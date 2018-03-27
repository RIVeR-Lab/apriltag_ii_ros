cmake_minimum_required(VERSION 2.8.3)
project(apriltags_ii)

add_compile_options(-std=gnu99)

find_package(catkin REQUIRED COMPONENTS roscpp cmake_modules
)

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES apriltags_ii
  CATKIN_DEPENDS
)

include_directories(include include/apriltags_ii include/apriltags_ii/common)
include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_library(apriltags_ii
  src/apriltag.c src/apriltag_quad_thresh.c src/tag16h5.c src/tag25h7.c
  src/tag25h9.c src/tag36artoolkit.c src/tag36h10.c src/tag36h11.c 

  src/common/g2d.c src/common/getopt.c src/common/homography.c src/common/image_f32.c
  src/common/image_u8.c src/common/image_u8x3.c src/common/image_u8x4.c src/common/matd.c
  src/common/pam.c src/common/pjpeg.c src/common/pjpeg-idct.c src/common/pnm.c
  src/common/string_util.c src/common/svd22.c src/common/time_util.c src/common/unionfind.c
  src/common/workerpool.c src/common/zarray.c src/common/zhash.c src/common/zmaxheap.c
)
target_link_libraries(apriltags_ii
  ${catkin_LIBRARIES}
)

#############
## Install ##
#############

## Mark executables and/or libraries for installation
install(TARGETS apriltags_ii
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

## Mark cpp header files for installation
install(DIRECTORY include/
  DESTINATION ${CATKIN_GLOBAL_INCLUDE_DESTINATION}
  FILES_MATCHING PATTERN "*.h"
)