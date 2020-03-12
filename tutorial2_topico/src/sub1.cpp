#include "ros/ros.h"
#include "tutorial2_topico/Variables.h"

void msgCallback(const tutorial2_topico::Variables::ConstPtr& v){
 ROS_INFO("resultado = %f", v->z);       // Shows the 'z' message
}

int main(int argc, char **argv){
ros::init(argc, argv, "sub1");
ros::NodeHandle nh;
ros::Subscriber ros_tutorial_sub = nh.subscribe("suma", 100, msgCallback);
// A function for calling a callback function, waiting for a message to be
// received, and executing a callback function when it is received
ros::spin();
return 0;
}
