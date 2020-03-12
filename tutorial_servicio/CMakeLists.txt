cmake_minimum_required(VERSION 2.8.3)
project(tutorial_servicio)

find_package(catkin REQUIRED COMPONENTS message_generation roscpp rospy std_msgs)

################################################
## Declare ROS messages, services and actions ##

## Declaracion del servicio: 'SrvTutorial.srv'
add_service_files(FILES SrvTutorial.srv)

## Configurar la dependencia del messaje
generate_messages(DEPENDENCIES std_msgs)

###################################
## catkin specific configuration ##

catkin_package(
  LIBRARIES tutorial_servicio
  CATKIN_DEPENDS roscpp rospy std_msgs
)

###########
## Build ##

## Configurar directorio a incluir
include_directories(${catkin_INCLUDE_DIRS})

## Construir opcion para el nodo "service_server"
add_executable(service_server src/service_server.cpp)
add_dependencies(service_server ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(service_server ${catkin_LIBRARIES})
## Construir opcion para el nodo "service_client"
add_executable(service_client src/service_client.cpp)
add_dependencies(service_client ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(service_client ${catkin_LIBRARIES})
