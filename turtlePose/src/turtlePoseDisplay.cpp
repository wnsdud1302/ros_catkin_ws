#include <ros/ros.h>
#include <turtlesim/Pose.h>
#include <visualization_msgs/Marker.h>
#define PI 3.14159

void poseCallBack(const turtlesim::PoseConstPtr& msg){
    printf("pose: x:%0.1f\ny:%0.1f\ntheta:%0.1f\nlinear_velocity:%0.1f\nngular_velocity:%0.1f\n---\n"
        , msg->x, msg->y, msg->theta*360/(2*PI), msg->linear_velocity, msg->angular_velocity); 
}



int main(int argc, char **argv){
    ros::init(argc, argv, "turtlePoseDisplay");
    ros::NodeHandle nh;
    ros::Publisher marker_pub = nh.advertise<visualization_msgs::Marker>("visualization_marker", 10);
    ros::Subscriber pose_sub = nh.subscribe("/turtle1/pose", 1, poseCallBack);

    ros::Rate loop_rate(10);

    while(ros::ok()){
        visualization_msgs::Marker robot;
        robot.header.frame_id = "robot";
        robot.header.stamp = ros::Time::now();
        robot.ns = "robot";
        robot.action = visualization_msgs::Marker::ADD;
        robot.pose.orientation.w = 1.0;

        robot.id = 0;

        robot.type = visualization_msgs::Marker::POINTS;

        robot.scale.x = 0.2;
        robot.scale.y = 0.2;
        geometry_msgs::Point p;
        turtlesim::PoseConstPtr pose;
        p.x = pose->x;
        p.y = pose->y;
        robot.points.push_back(p);

        marker_pub.publish(robot);

        loop_rate.sleep();
    }
    //ros::spin();

    return 0;
}