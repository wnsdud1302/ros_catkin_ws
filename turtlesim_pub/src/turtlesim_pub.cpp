#include <ros/ros.h>
#include <geometry_msgs/Twist.h>

int main(int argc, char **argv){
    ros::init(argc, argv, "turtlesim_pub");
    ros::NodeHandle nh;
    ros::Publisher pos_pub = nh.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 1000);

    ros::Rate loop_rate(5);

    while(ros::ok()){
        geometry_msgs::Twist msg;
        msg.linear.x = 5.0;
        msg.angular.z = 180*(3.14/180);
        ROS_INFO("linear : %0.1lf, angular : %0.1lf", msg.linear.x, msg.angular.z);
        pos_pub.publish(msg);
        //ros::spinOnce();
        loop_rate.sleep();
    }
}