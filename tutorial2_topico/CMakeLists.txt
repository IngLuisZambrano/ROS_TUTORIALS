cmake_minimum_required(VERSION 2.8.3)
project(tutorial2_topico)

find_package(catkin REQUIRED COMPONENTS message_generation roscpp rospy std_msgs)

################################################
## Declare ROS messages, services and actions ##

## Declaracion del mensage:MsgTutorial.msg
 add_message_files(FILES Variables.msg)

## Configurar la dependencia del memsaje
 generate_messages(DEPENDENCIES std_msgs)

###################################
## catkin specific configuration ##

catkin_package(
#  INCLUDE_DIRS include
   LIBRARIES tutorial2_topico
   CATKIN_DEPENDS roscpp rospy std_msgs
#  DEPENDS system_lib
)

###########
## Build ##

include_directories(${catkin_INCLUDE_DIRS})

## Construir opcion para el nodo "operaciones"
## Declare a C++ ejecutable
add_executable(operaciones src/operaciones.cpp)
add_dependencies(operaciones ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(operaciones ${catkin_LIBRARIES})

## Construir opcion para el nodo "sub1"
## Declare a C++ ejecutable
add_executable(sub1 src/sub1.cpp)
add_dependencies(sub1 ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(sub1 ${catkin_LIBRARIES})
