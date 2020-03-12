cmake_minimum_required(VERSION 2.8.3)
project(tutorial2_servicio)

find_package(catkin REQUIRED COMPONENTS message_generation roscpp rospy std_msgs)

################################################
## Declare ROS messages, services and actions ##

## Declaracion del servicio: 'variables.srv'
add_service_files(FILES variables.srv)

## Configurar la dependencia del messaje
generate_messages(DEPENDENCIES std_msgs)

###################################
## catkin specific configuration ##

catkin_package(
 LIBRARIES tutorial2_servicio
 CATKIN_DEPENDS roscpp rospy std_msgs
)

###########
## Build ##

## Configurar directorio a incluir
include_directories(${catkin_INCLUDE_DIRS})

## Construir opcion para el nodo "nodo_servidor"
add_executable(nodo_servidor src/nodo_servidor.cpp)
add_dependencies(nodo_servidor ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(nodo_servidor ${catkin_LIBRARIES})
## Construir opcion para el nodo "nodo_cliente"
add_executable(nodo_cliente src/nodo_cliente.cpp)
add_dependencies(nodo_cliente ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(nodo_cliente ${catkin_LIBRARIES})
