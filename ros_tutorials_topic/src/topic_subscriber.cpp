#include <ros/ros.h>
#include <ros_tutorials_topic/msgTutorial.h>

// 메시지 콜백함수로써, ros_tutorial_sub Subscriber에 해당되는 메시지를 수신하였을 때 구동되는 함수
// 입력 메시지로는 ros_tutorial_topic 패키지의 msgTutorial 메시지 pointer 참조형을 인자로 받음
void msgCallback(const ros_tutorials_topic::msgTutorial::ConstPtr& msg){
    ROS_INFO("receive msg: %d", msg->data); // 수신된 메시지를 표시하는 함수
}

int main(int argc, char **argv){
    ros::init(argc, argv, "topic_subscriber"); // 노드명 초기화
    ros::NodeHandle nh; // ROS 시스템과 통신을 위한 노드 핸들 선언
    // 서브스크라이버 선언, ros_tutorials_topic 패키지의 msgTutorial 메시지 파일을 이용한
    // Subscriber 클래스의 ros_tutorial_sub 객체을 생성. 토픽명은 "ros_tutorial_msg" 이며,
    // 서브스크라이버의 큐(queue) 사이즈를 100개로 설정한다는 것이다
    ros::Subscriber ros_tutorial_sub = nh.subscribe("ros_tutorial_msg", 100, msgCallback);
    // 콜백함수 호출을 위한 함수로써, 메시지가 수신되기를 대기, 수신되었을 경우 콜백함수를 실행한다
    ros::spin();
    return 0;
}