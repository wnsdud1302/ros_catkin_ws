#include <ros/ros.h>
#include <turtlesim/Pose.h>


void poseCallBack(const turtlesim::Pose::ConstPtr& msg){
    ROS_INFO("pose: %0.1f, %0.1f, %0.1f ", msg->x, msg->y, msg->theta); 
}

int main(int argc, char **argv){
    ros::init(argc, argv, "turtlesim subscriber");
    ros::NodeHandle nh;
    ros::Subscriber pose_sub = nh.subscribe("tutle1/pose", 1, poseCallBack);

    ros::spin();

    return 0;
}