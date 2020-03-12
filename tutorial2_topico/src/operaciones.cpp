#include "ros/ros.h"
#include "tutorial2_topico/Variables.h"
int main(int argc, char **argv)		// Node Main Function
{
ros::init(argc, argv, "operaciones"); // Inicializa nombre del nodo
ros::NodeHandle nh;		

//Declara y crea publicador "ros_tutorial_pub" usando "MsgTutorial"
//El nombre del topico es "ros_tutorial_msg"
ros::Publisher ros_tutorial_pub = nh.advertise<tutorial2_topico::Variables>("suma", 100);
ros::Rate loop_rate(10); // 10Hz
//Declara mensaje "msg" en mensaje "MsgTutorial"
tutorial2_topico::Variables dato;
					
float contador=0;
							
while (ros::ok()){
        dato.x = 5;
        dato.y = 6;
        dato.z = dato.x + dato.y + contador;

        ROS_INFO("Resultado = %f", dato.z );
        ros_tutorial_pub.publish(dato);		         // Publishes 'dato' message
	loop_rate.sleep();			         // Goes to sleep according to the loop rate defined above.
	++contador;
	}
return 0;
}

