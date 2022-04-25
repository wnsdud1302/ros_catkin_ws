#include <ros/ros.h> // ROS 기본 헤더 파일
#include <ros_tutorials_service/srvTutorial.h> // srvTutorial 서비스 파일 헤더
#include <cstdlib>

int main(int argc, char **argv){
    // 노드명 초기화
    ros::init(argc, argv, "service_client");
    // 입력값 오류 처리
    if (argc != 3)
    {
    ROS_INFO("cmd : rosrun ros_tutorial_service service_client arg0 arg1");
    ROS_INFO("arg0: double number, arg1: double number");
    return 1;
    }
    // ROS 시스템과 통신을 위한 노드 핸들 선언
    ros::NodeHandle nh;
    // 서비스 클라이언트 선언, ros_tutorials 패키지의 srvTutorial 서비스 파일을 이용한
    // 서비스 클라이언트 ros_tutorial_service_client를 작성한다.
    // 서비스명은 "ros_tutorial_srv"이다
    ros::ServiceClient ros_tutorials_service_client = nh.serviceClient<ros_tutorials_service::srvTutorial>("ros_tutorial_srv");
    // srv라는 이름으로 srvTutorial 서비스 파일을 이용하는 서비스 파일을 선언한다.
    ros_tutorials_service::srvTutorial srv;
    // 서비스 요청 값으로 노드가 실행될 때 입력으로 사용된 매개변수를 각각의 a, b에 저장한다.
    srv.request.a = atoll(argv[1]);
    srv.request.b = atoll(argv[2]);
    // 서비스를 요청하고, 요청이 받아들여졌을 경우, 응답 값을 표시한다.
    if (ros_tutorials_service_client.call(srv))
    {
    ROS_INFO("send srv, srv.Request.a and b: %ld, %ld", (long int)srv.request.a, (long int)srv.request.b);
    ROS_INFO("receive srv, srv.Response.result: %ld", (long int)srv.response.result);
    }
    else
    {
    ROS_ERROR("Failed to call service ros_tutorials_srv");
    return 1;
    }
    return 0;
}