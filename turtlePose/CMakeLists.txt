cmake_minimum_required(VERSION 3.0.2)
project(turtlePose)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
    roscpp
    turtlesim
    geometry_msgs
    visualization_msgs
    )

include_directories(
${catkin_INCLUDE_DIRS}
)

add_executable(turtlePoseDisplay src/turtlePoseDisplay.cpp)
add_dependencies(turtlePoseDisplay ${${PROJECT_NAME}_EXPORTED_TARGETS}
    ${catkin_EXPORTED_TARGETS}
)
target_link_libraries(turtlePoseDisplay
    ${catkin_LIBRARIES}
)

add_executable(turtleControl src/turtleControl.cpp)
add_dependencies(turtleControl ${${PROJECT_NAME}_EXPORTED_TARGETS}
    ${catkin_EXPORTED_TARGETS}
)
target_link_libraries(turtleControl
    ${catkin_LIBRARIES}
)
