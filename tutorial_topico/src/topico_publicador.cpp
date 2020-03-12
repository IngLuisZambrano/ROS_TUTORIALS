#include "ros/ros.h"
#include "tutorial_topico/MsgTutorial.h"
int main(int argc, char **argv)		// Node Main Function
{
ros::init(argc, argv, "topico_publicador"); // Inicializa nombre del nodo
ros::NodeHandle nh;		

//Declara y crea publicador "ros_tutorial_pub" usando "MsgTutorial"
//El nombre del topico es "ros_tutorial_msg"
ros::Publisher ros_tutorial_pub = nh.advertise<tutorial_topico::MsgTutorial>("ros_tutorial_msg", 100);
ros::Rate loop_rate(10); // 10Hz
//Declara mensaje "msg" en mensaje "MsgTutorial"
tutorial_topico::MsgTutorial msg;
							
int count = 0;					
while (ros::ok()){
	msg.stamp = ros::Time::now(); // Save current time in the stamp of 'msg'
	msg.data = count;
	// Save the the 'count' value in the data of 'msg'
	ROS_INFO("send msg = %d", msg.stamp.sec);        // Print the 'stamp.sec' message
	ROS_INFO("send msg = %d", msg.stamp.nsec);       // Print the 'stamp.nsec' message
	ROS_INFO("send msg = %d", msg.data);	    	 // Print the 'data' message
	ros_tutorial_pub.publish(msg);		         // Publishes 'msg' message
	loop_rate.sleep();			         // Goes to sleep according to the loop rate defined above.
	++count;					 // Increase count variable by one
	}
return 0;
}
