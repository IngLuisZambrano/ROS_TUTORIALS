#!/usr/bin/env python
import rospy #importar rospy
from tutorial2_topico.msg import Variables        #importar mensaje personalizado

def callback(data): #funcion a la que se llama cuando recibo un mensaje en el topic al que nos subscribimos
    rospy.loginfo("He recibido: %f, %f y %f", data.x, data.y, data.z) #escribe en el log el mensaje recibido
    rospy.loginfo("Resultado: %f ", data.z)


def subscriptor(): #funcion principal del nodo
    rospy.init_node('sub1', anonymous=True) #inicializa nodo con nombre subscriptor

    #se subscribe al topic suma con mensajes tipo Variables llamando a la funcion callback cuando se reciba mensaje
    rospy.Subscriber("suma", Variables, callback)
    rospy.spin()

if __name__ == '__main__':
    subscriptor()
