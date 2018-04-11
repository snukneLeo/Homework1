#!/bin/bash

#AVVIO ROSCORE NODO MASTER
roscore &
#ASPETTO UN SECONDO PRIMA DI FAR PARTIRE GLI ALTRI NODI
sleep 1
#AVVIO PRIMO NODO
gnome-terminal -x sh -c "rosrun homework1 receiveChangeInfo"
#AVVIO SECONDO NODO
gnome-terminal -x sh -c "rosrun homework1 printInfo"
#AVVIO TERZO NODO
gnome-terminal -x sh -c "rosrun homework1 sendInfo"
