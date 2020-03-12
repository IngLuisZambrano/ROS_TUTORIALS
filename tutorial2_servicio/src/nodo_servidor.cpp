#include "ros/ros.h"
#include "tutorial2_servicio/variables.h"

bool multiplicacion(tutorial2_servicio::variables::Request &req, tutorial2_servicio::variables::Response &res){
	// The service name is 'ros_tutorial_srv' and it will call 'calculation' function
	// upon the service request.
        res.z = req.x * req.y;
	// Displays 'a' and 'b' values used in the service request and
	// the 'result' value corresponding to the service response
        ROS_INFO("Valores: x=%d, y=%d", (int)req.x, (int)req.y);
        ROS_INFO("Multiplicacion: %d", (int)res.z);
        return true;
        }
int main(int argc, char **argv) {
 ros::init(argc, argv, "nodo_servidor"); // Initializes Node Name
 ros::NodeHandle nh; // Node handle declaration

 ros::ServiceServer ros_tutorials_service_server = nh.advertiseService("multiplicacion",multiplicacion);
 ROS_INFO("servidor listo!");
 ros::spin();					
 // Wait for the service request
 return 0;
}
