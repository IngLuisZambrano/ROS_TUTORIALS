#include "ros/ros.h"
#include "tutorial_servicio/SrvTutorial.h"

bool calculation(tutorial_servicio::SrvTutorial::Request &req, tutorial_servicio::SrvTutorial::Response &res){
	// The service name is 'ros_tutorial_srv' and it will call 'calculation' function
	// upon the service request.
	res.result = req.a + req.b;
	// Displays 'a' and 'b' values used in the service request and
	// the 'result' value corresponding to the service response
	ROS_INFO("request: x=%ld, y=%ld", (long int)req.a, (long int)req.b);
	ROS_INFO("sending back response: %ld", (long int)res.result);
	return true;
	}

int main(int argc, char **argv){
 ros::init(argc, argv, "service_server"); // Initializes Node Name
 ros::NodeHandle nh; // Node handle declaration

 ros::ServiceServer ros_tutorials_service_server = nh.advertiseService("ros_tutorial_srv",calculation);
 ROS_INFO("ready srv server!");
 ros::spin();					
 // Wait for the service request
 return 0;
}
/* cd catkin_ws/
a) catkin_make
 compila todo el workspace
b) catkin_make --pkg my_package
 compila sólo el paquete y todas las dependencias posibles
c) catkin_make --only-pkg-with-deps my_package
 compila sólo el paquete y las dependencias mínima
*/
