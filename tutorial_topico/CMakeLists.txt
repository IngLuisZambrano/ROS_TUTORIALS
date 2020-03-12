cmake_minimum_required(VERSION 2.8.3)
project(tutorial_topico)

find_package(catkin REQUIRED COMPONENTS message_generation roscpp rospy std_msgs)

################################################
## Declare ROS messages, services and actions ##
################################################

## Declaracion del mensage:MsgTutorial.msg
 add_message_files(FILES MsgTutorial.msg)

## Configurar la dependencia del memsaje
 generate_messages(DEPENDENCIES std_msgs)

###################################
## catkin configuracion especifica ##
###################################

catkin_package(
#  INCLUDE_DIRS include
   LIBRARIES tutorial_topico
   CATKIN_DEPENDS roscpp rospy std_msgs
#  DEPENDS system_lib
)

###########
## Build ##

include_directories(${catkin_INCLUDE_DIRS})

## Construir opcion para el nodo "topico_publicador"
## Declare a C++ ejecutable
add_executable(topico_publicador src/topico_publicador.cpp)
add_dependencies(topico_publicador ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(topico_publicador ${catkin_LIBRARIES})

## Construir opcion para el nodo "topico_subcriptor"
## Declare a C++ ejecutable
add_executable(topico_subcriptor src/topico_subcriptor.cpp)
add_dependencies(topico_subcriptor ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(topico_subcriptor ${catkin_LIBRARIES})
