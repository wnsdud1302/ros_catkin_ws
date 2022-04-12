cmake_minimum_required(VERSION 2.8.3)
## project( ) 매크로를 이용하여 패키지 명을 지정
project(turtlesim_subscriber)
## 캐킨 빌드를 할 때 요구되는 구성요소 패키지 탐색
## catki에 과련된 기본 패키지는 ‘REQUIRDED’ 옵션만 추가하면 됨
## find_package(catkin REQUIRED)
## 의존성 패키지 roscpp, std_msgs, message_generation을 추가한다면 ‘COMPONENTS’ 옵션으로 추가하면 됨
find_package(catkin REQUIRED COMPONENTS roscpp)
## 이들 패키지가 catkin 하위 패키지는 아니지만 directory나 library 환경변수들을 공유할 수 있어 이후 빌드 시에 편리
## catkin 빌드 시스템이 find_package( ) 매크로를 통해 이들 패키지를 찾게 되면 이들 패키지 정보를 포함하는
## 환경변들을 생성. Cmakelist.txt 스크립트 파일에서 접할 수 있는 이와 관련된 환경변수는 크게 4가지임. 
## (1) catkin_FOUND
## (2) catkin_INCLUDE_DIRS or <NAME>_INCLUDES
## (3) catkin_LIBRARIES or catkin_LIBS
## (4) catkin_DEFINITIONS
## catkin이 targe를 빌드할 시 의존성 있는 헤더파일, 패키지나 라이브러리를 imported할 환경변수와 관련이 있음
## 메시지 생성: msgTutorial
## 패키지를 생성한 후 ~/catkin_ws/src/ros_tutorials/msg , srv, or action 폴더에 msg, srv, or action 확장자를 포함한
## 메세지 파일을 만들어 줘야 함, 예를 들면 msgTutorial.msg
## add_message_files( ) 매크로는 위에서 생성한 파일을 참조하여 컴파일러의 환경에 맞는 헤더 파일을 생성함
## 생성된 헤더파일은 ~/catkin_ws/dev/include/ros_tutorials/msgTutorial.h 파일을 생성함
## 헤더 파일을 검토해보면 msgTutorial 구조체가 정의된 것을 확인할 수 있음
##add_message_files(FILES msgTutorial.msg)
## generate_messages는 msgTutorial 구조체와 ROS에서 제공하는 표준 std_msegs 메세지 형을 참고(의존)하여
## 새로운 ‘msgTutorial’ 형(type)를 만들어 냄, 새로운 메세지를 만들 때 의존하는 메세지형을 ‘DEPENDENCIES’ 옵션
## 이후에 나열하면 됨
##generate_messages(DEPENDENCIES std_msgs)
## catkin_package()는 캐킨에서 제공되는 Cmake 매크로이다. 본 매크로는 build target이 다른 패키지에 exported 될 때
## 제공되는 정보를 정의한다. 이 함수는 build target을 선언(declaring)하기(add_library(), add_executable()) 전에 호출되
## 어야 한다. 이 함수는 아래와 같이 다섯가지 옵션 augment가 있다. 
## INCLUDE_DIRS – 패키지의 exported 헤더 파일(*.h)이 놓일 path
## LIBRARIES –exporte될 라이브러리
## CATKIN_DEPENDS- 본 패키지의 의존 패키지
## DEPENDS – 본 패키지의 Non-catkin 의존 패키지
## 캐킨 패키지 옵션으로 라이브러리, 캐킨 빌드 의존성, 시스템 의존 패키지를 기술한다.
catkin_package(
#INCLUDE_DIRS include
LIBRARIES turtlesim_subscriber
CATKIN_DEPENDS roscpp 
)
## target을 지정하기 전에 target 을 build할 때 Cmake에서 요구하는 모든 헤더파일의 인클루드 패스를
## 설정한다. 빌드되는 소스코드가 include하는 모든 헤더파일의 path를 지정
## include_directories(include ${catkin_INCLUDE_DIRS})처럼 include 옵션은 패키지 안에 헤더파일을
## 포함하는 include 디렉터리를 갖는 경우만 사용
include_directories(${catkin_INCLUDE_DIRS})
## 여기서 부터 targe을 빌드함
## ros_tutorial_msg_publisher 노드에 대한 빌드 옵션이다.
## 실행 파일, 타겟 링크 라이브러리, 추가 의존성 등을 설정한다.
add_executable(pose_sub src/turtlesim_subscriber.cpp)
## 실행 파일이 link하는 라이브러리들을 지정함
target_link_libraries(pose_sub ${catkin_LIBRARIES})
## 빌드 target의 메시지, 서비스, 또는 dynamic_recongiure 파라미터를 필요하는 다른 패키지의 target 
## 에 의존성을 갖는 다면 target catkin_EXPORTED_TARGETS에 대한 명확한 의존성을 기술할 필요
## 가 있다. (If you have ##a target which (even transitively) depends on some other target that needs 
##messages/services/actions to be built, ##you need to add an explicit dependency on target 
##catkin_EXPORTED_TARGETS)
## add_dependencies(topic_publisher ${catkin_EXPORTED_TARGETS})
## 메세지나 서비스를 빌드하는 패키지와 이들을 사용하는 실행파일이 있을 때 자동으로 생성된 메세지 target에 대한 명확
## 한 의존성을 기술할 필요가 있다. (If you have a package which builds messages and/or services as well as 
##executables that use these, you need to create an explicit dependency on the automatically-generated message 
##target )
## add_dependencies(topic_publisher ${${PROJECT_NAME}_EXPORTED_TARGETS})
## 위 두 조건을 만족하면 두 의존성을 함께 기술할 수 있다. 
add_dependencies(pose_sub ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
## ros_tutorial_msg_subscriber 노드에 대한 빌드 옵션이다.

