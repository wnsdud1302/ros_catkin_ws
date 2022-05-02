#include <ros/ros.h>
#include <trigonometricFun/srvTriFun.h>
#include <cmath>
#define PI 3.14195

bool calculation(trigonometricFun::srvTriFun::Request &req, trigonometricFun::srvTriFun::Response &res){

    switch(req.fun){
        case 1:
        res.result = sin(req.degree*PI/180); break;
        case 2:
        res.result = cos(req.degree*PI/180); break;
        case 3:
        res.result = tan(req.degree*PI/180); break;
        default:
        res.result = sin(req.degree*PI/180); break;
    }

    ROS_INFO("request fun=%d, degree=%0.1f", (int)req.fun, (float)req.degree);
    ROS_INFO("response: %0.1f", (float)res.result);
    return true;
}

int main(int argc, char **argv){
    ros::init(argc, argv, "trigonometric_server");
    ros::NodeHandle nh;

    ros::ServiceServer trigonometric_server = nh.advertiseService("srvtrifun", calculation);
    ROS_INFO("ready srv server!");
    ros::spin();
    return 0;
}