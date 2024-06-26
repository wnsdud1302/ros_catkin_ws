#include <ros/ros.h>
#include <simple_sp/simple_msg.h>
#include <sstream>

int main(int argc, char **argv){
    ros::init(argc, argv, "talker");
    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<simple_sp::simple_msg>("chatter", 1000);
    ros::Rate loop_rate(10);
    int count = 0;

    while(ros::ok()){
        simple_sp::simple_msg msg;

        std::stringstream ss;
        ss << "hello world" << count; count++;
        msg.data = ss.str();

        std::string id;
        nh.param("/chatter_id", id, std::string("no id registered"));
        msg.id = id;

        ROS_INFO("[%s], %s", msg.id.c_str(), msg.data.c_str());

        pub.publish(msg);
        loop_rate.sleep();
    }
    return 0;
}