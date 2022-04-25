cmake_minimum_required(VERSION 3.0.2)
project(boundingbox_visualizer)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED
    roscpp
    jsk_recognition_msgs
    boundingbox_visualizer_msgs
    )


catkin_package(
  CATKIN_DEPENDS 
  jsk_recognition_msgs
  boundingbox_visualizer_msgs
)

include_directories(
include ${catkin_INCLUDE_DIRS}
)

add_executable(boundingbox_visualizer src/boundingbox_visualizer.cpp)
add_dependencies(boundingbox_visualizer ${${PROJECT_NAME}_EXPORTED_TARGETS}
    ${catkin_EXPORTED_TARGETS}
)
target_link_libraries(boundingbox_visualizer
    ${catkin_LIBRARIES}
)

add_executable(box_pose_pub src/box_pose_pub.cpp)
add_dependencies(box_pose_pub ${${PROJECT_NAME}_EXPORTED_TARGETS}
    ${catkin_EXPORTED_TARGETS}
)
target_link_libraries(box_pose_pub
    ${catkin_LIBRARIES}
)
