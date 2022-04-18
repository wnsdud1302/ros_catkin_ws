#include <ros/ros.h>
#include <ros_tutorials_topic/msgTutorial.h>

int main(int argc, char **argv){
    ros::init(argc, argv, "topic_publisher"); // 노드명 초기화
    ros::NodeHandle nh; // ROS 시스템과 통신을 위한 노드 핸들 선언
    // 퍼블리셔 선언, 토익명 ＂ros_tutorial_msg＂으로 ros_tutorials_topic 패키지의 msgTutorial 형 메시지를 발급할
    //것이라 master node에 알림, advertise 함수의 반환값은 Publisher 객체를 반환함
    //토픽명은 ＂ros_tutorial_msg＂ 이며, 퍼블리셔의 큐(queue) 사이즈를 100개로 설정한다는 것이다
    ros::Publisher ros_tutorial_pub = nh.advertise<ros_tutorials_topic::msgTutorial>("ros_tutorial_msg", 100);
    ros::Rate loop_rate(1); // 루프 주기를 설정한다. "10" 이라는 것은 10Hz를 말하는 것으로 0.1초 간격으로 반복된다
    int count = 0; // 메시지에 사용될 변수 선언
    nh.getParam("send_count", count);
    while (ros::ok())
    {
        ros_tutorials_topic::msgTutorial msg; // msgTutorial 메시지 형식으로 msg 라는 메시지를 선언
        msg.stamp = ros::Time::now(); //현재 시간을 msg의 하위 stamp 메세지에 담는다.
        msg.data = count; // count 라는 변수를 이용하여 메시지 값을 정한다
        ROS_INFO("send msg = %d", count); // ROS_INFO 라는 ROS 함수를 이용하여 count 변수를 출력
        ros_tutorial_pub.publish(msg); // 메시지를 발행한다. 약 0.1초 간격으로 발행된다
        loop_rate.sleep(); // 위에서 정한 루프 주기에 따라 슬립에 들어간다
        ++count; // count 변수 1씩 증가
    }
    return 0;
}