#!/usr/bin/env python 
import rospy                                  #importar rospy
from tutorial2_topico.msg import Variables    #importar mensaje personalizado

#funcion principal
def principal():
    pub = rospy.Publisher('suma', Variables, queue_size=10) #crea el publicador en el topic suma y tipo de mensaje MsgGeek
    rospy.init_node('operaciones', anonymous=True)          #inicia el nodo publicador
    rate = rospy.Rate(2)                                  # 0.5 Hz
    i = 0.0                                                 #inicializar variable i, contador
    mensaje = Variables() #declaro la variable mensaje como tipo MsgGeek
    rospy.loginfo("Estoy publicando en el topic suma: ") #escribo en log
    
    while not rospy.is_shutdown():           #mientras ROS siga funcionando
	mensaje.x = 5
	mensaje.y = 6
        mensaje.z = mensaje.x + mensaje.y + i               
        pub.publish(mensaje)                          #publica el mensaje en el topic
        rospy.loginfo("Resultado = %f", mensaje.z)    #escribe en log el mensaje 
        rate.sleep()
	i = i + 1                                                  #incrementa en 0.1 la variable
    
    rospy.loginfo("Finalizando nodo...")                           #Si se para el nodo, escribe en el log
if __name__ == '__main__':
    try:
        principal()
    except rospy.ROSInterruptException:
	pass
