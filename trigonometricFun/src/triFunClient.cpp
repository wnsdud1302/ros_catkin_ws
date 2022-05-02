#include <ros/ros.h>
#include <trigonometricFun/srvTriFun.h>
#include <cstdlib>

int main(int argc, char **argv){
    // 노드명 초기화
    ros::init(argc, argv, "service_client");
    // 입력값 오류 처리
    if (argc != 3)
    {
    ROS_INFO("cmd : rosrun trigonometricFun triFunClient arg0 arg1");
    ROS_INFO("arg0: int number, arg1: float number");
    return 1;
    }
    // ROS 시스템과 통신을 위한 노드 핸들 선언
    ros::NodeHandle nh;
    // 서비스 클라이언트 선언, ros_tutorials 패키지의 srvTutorial 서비스 파일을 이용한
    // 서비스 클라이언트 ros_tutorial_service_client를 작성한다.
    // 서비스명은 "ros_tutorial_srv"이다
    ros::ServiceClient trifunclient = nh.serviceClient<trigonometricFun::srvTriFun>("srvtrifun");
    // srv라는 이름으로 srvTutorial 서비스 파일을 이용하는 서비스 파일을 선언한다.
    trigonometricFun::srvTriFun srv;
    // 서비스 요청 값으로 노드가 실행될 때 입력으로 사용된 매개변수를 각각의 a, b에 저장한다.
    srv.request.fun = atoi(argv[1]);
    srv.request.degree = atof(argv[2]);
    if (trifunclient.call(srv))
    {
    ROS_INFO("send srv, srv.Request.fun and degree: %d, %0.1f", (int)srv.request.fun, (float)srv.request.degree);
    ROS_INFO("receive srv, srv.Response.result: %0.1f", (float)srv.response.result);
    }
    else
    {
    ROS_ERROR("Failed to call service ros_tutorials_srv");
    return 1;
    }
    return 0;
}