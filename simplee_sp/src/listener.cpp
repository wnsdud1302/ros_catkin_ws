#include <ros/ros.h>
#include <simple_sp/simple_msg.h>

void chatterCallback(const simple_sp::simple_msgConstPtr &ptr){
    ROS_INFO("i heard from %s : [%s]", ptr->id.c_str(), ptr->data.c_str());
}

int main(int argc, char **argv){
    ros::init(argc, argv, "listener");
    ros::NodeHandle nh;

    ros::Subscriber sub = nh.subscribe("chatter", 1000, chatterCallback);
    ros::spin();
    return 0;
}