#include "ros/ros.h"
#include "tutorial_servicio/SrvTutorial.h"
#include <cstdlib>			// Library for using the "atoll" function
int main(int argc, char **argv){
ros::init(argc, argv, "service_client");		
if (argc != 3){
    ROS_INFO("cmd : rosrun tutorial_servicio service_client arg0 arg1");
    ROS_INFO("arg0: double number, arg1: double number");
    return 1;
    }
ros::NodeHandle nh;
ros::ServiceClient ros_tutorials_service_client = nh.serviceClient<tutorial_servicio::SrvTutorial>("ros_tutorial_srv");
// Declares the 'srv' service that uses the 'SrvTutorial' service file
tutorial_servicio::SrvTutorial srv;
// Parameters entered when the node is executed as a service request value are stored at 'a' and 'b'
srv.request.a = atoll(argv[1]);
srv.request.b = atoll(argv[2]);
// Request the service. If the request is accepted, display the response value
if (ros_tutorials_service_client.call(srv)){
	ROS_INFO("send srv, srv.Request.a and b: %ld, %ld", (long int)srv.request.a, (long int)srv.request.b);
	ROS_INFO("receive srv, srv.Response.result: %ld", (long int)srv.response.result);
	}
else{
	ROS_ERROR("Failed to call service ros_tutorial_srv");
	return 1;
	}
return 0;
}
