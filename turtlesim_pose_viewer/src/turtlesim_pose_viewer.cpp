#include <ros/ros.h>
#include <turtlesim/Pose.h>


void poseCallBack(const turtlesim::PoseConstPtr& msg){
    ROS_INFO("pose: x:%0.1f, y:%0.1f, theta:%0.1f, linear_velocity:%0.1f,  ngular_velocity:%0.1f"
        , msg->x, msg->y, msg->theta, msg->linear_velocity, msg->angular_velocity); 
}

int main(int argc, char **argv){
    ros::init(argc, argv, "turtlesim_subscriber");
    ros::NodeHandle nh;
    ros::Subscriber pose_sub = nh.subscribe("/turtle1/pose", 1, poseCallBack);

    ros::Rate loop_rate(10);

    while(ros::ok()){
        ros::spinOnce();
        loop_rate.sleep();
    }
    //ros::spin();

    return 0;
}