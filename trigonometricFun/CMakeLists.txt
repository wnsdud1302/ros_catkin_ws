cmake_minimum_required(VERSION 2.8.3)
project(trigonometricFun)
## 캐킨 빌드를 할 때 요구되는 구성요소 패키지이다.
## 의존성 패키지로 roscpp, std_msgs, message_generation이며 이 패키지들이 존재하지 않으면 빌드
##도중에 에러가 난다.
find_package(catkin REQUIRED COMPONENTS roscpp std_msgs message_generation)
## 서비스 선언: srvTutorial.srv
add_service_files(FILES srvTriFun.srv)
## 의존하는 메시지를 설정하는 옵션이다.
## std_msgs가 설치되어 있지 않다면 빌드 도중에 에러가 난다.
generate_messages(DEPENDENCIES std_msgs)
## 캐킨 패키지 옵션으로 라이브러리, 캐킨 빌드 의존성를 기술한다.
catkin_package(
LIBRARIES trigonometricFun
CATKIN_DEPENDS roscpp std_msgs
)
## 인클루드 디렉터리를 설정한다.
include_directories(include ${catkin_INCLUDE_DIRS})
# ros_tutorial_srv_server 노드에 대한 빌드 옵션이다.
add_executable(triFunServer src/triFunServer.cpp)
target_link_libraries(triFunServer ${catkin_LIBRARIES})
add_dependencies(triFunServer ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS}})
# ros_tutorial_srv_client 노드에 대한 빌드 옵션이다.
add_executable(triFunClient src/triFunClient.cpp)
target_link_libraries(triFunClient ${catkin_LIBRARIES})
add_dependencies(triFunClient ${${PROJECT_NAME}_EXPORTED_TARGETS}${catkin_EXPORTED_TARGETS})