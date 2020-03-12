#include "ros/ros.h"
#include "tutorial2_servicio/variables.h"
#include <cstdlib>			// Library for using the "atoll" function
int main(int argc, char **argv){
ros::init(argc, argv, "nodo_cliente");
if (argc != 3){
    ROS_INFO("cmd : rosrun tutorial_servicio service_client x y");
    ROS_INFO("x: integer number, y: integer number");
    return 1;
    }
ros::NodeHandle nh;
ros::ServiceClient ros_tutorials_service_client = nh.serviceClient<tutorial2_servicio::variables>("multiplicacion");
// Declares the 'srv' service that uses the 'SrvTutorial' service file
tutorial2_servicio::variables srv;
// Parameters entered when the node is executed as a service request value are stored at 'a' and 'b'
srv.request.x = atoll(argv[1]);
srv.request.y = atoll(argv[2]);
// Request the service. If the request is accepted, display the response value
if (ros_tutorials_service_client.call(srv)){
	ROS_INFO("send srv, requerimiento: %d, %d", (int)srv.request.x, (int)srv.request.y);
	ROS_INFO("receive srv, Resultado: %d", (int)srv.response.z);
	}
else{
	ROS_ERROR("Failed to call service ros_tutorial_srv");
	return 1;
	}
return 0;
}
