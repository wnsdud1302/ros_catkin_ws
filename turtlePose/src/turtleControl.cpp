#include <ros/ros.h>
#include <geometry_msgs/Twist.h>

int robotAngularVel = 90;

int main(int argc, char **argv){
    ros::init(argc, argv, "turtleControl");
    ros::NodeHandle nh;
    ros::Publisher pos_pub = nh.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 1000);
    nh.setParam("robotAngularVel", robotAngularVel);
    ros::Rate loop_rate(10);

    while(ros::ok()){
        geometry_msgs::Twist msg;
        msg.linear.x = 5.0;
        msg.angular.z = robotAngularVel*(3.14/180);
        nh.getParam("robotAngularVel", robotAngularVel);
        pos_pub.publish(msg);
        loop_rate.sleep();
    }
}