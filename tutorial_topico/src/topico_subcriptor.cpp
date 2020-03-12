#include "ros/ros.h"
#include "tutorial_topico/MsgTutorial.h"

void msgCallback(const tutorial_topico::MsgTutorial::ConstPtr& msg){
 ROS_INFO("recieve msg = %d", msg->stamp.sec);  // Shows the 'stamp.sec' message
 ROS_INFO("recieve msg = %d", msg->stamp.nsec); // Shows the 'stamp.nsec' message
 ROS_INFO("recieve msg = %d", msg->data);       // Shows the 'data' message
}

int main(int argc, char **argv){
ros::init(argc, argv, "topico_subscriptor");
ros::NodeHandle nh;
ros::Subscriber ros_tutorial_sub = nh.subscribe("ros_tutorial_msg", 100, msgCallback);
// A function for calling a callback function, waiting for a message to be
// received, and executing a callback function when it is received
ros::spin();
return 0;
}
