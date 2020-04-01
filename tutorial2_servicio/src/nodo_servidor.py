#!/usr/bin/env python
import rospy
from tutorial2_servicio.srv import *

# Funcion a llamar cuando llegue peticion del cliente
def multiplica_2_num(req):
    print "Devolviendo [%s * %s = %s]"%(req.x, req.y, (req.x * req.y)) #SrvGeekRequest
    return variablesResponse(req.x * req.y)


rospy.init_node('nodo_servidor')

# Creamos el servicio llamado 'mul2num', con tipo de servicio 'SrvGeek', 
# llamaremos a la funcion 'multiplica_2_num' cuando llegue peticion
s = rospy.Service('multiplicacion', variables, multiplica_2_num) 

print "Servidor Listo..."
rospy.spin()
print "\nCerrando servidor"
