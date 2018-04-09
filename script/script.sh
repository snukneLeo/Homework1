#!/bin/bash

#AVVIO ROSCORE NODO MASTER
roscore &
#ASPETTO UN SECONDO PRIMA DI FAR PARTIRE GLI ALTRI NODI
#IN MODO DA NON AVERE ERRORI NELLA CONNESSIONE
#AL NODO MASTER PER I NODI FIGLI
sleep 1
#AVVIO PRIMO NODO
#primo_nodo.sh
#xterm -hold -e bash primo_nodo.sh &
#AVVIO SECONDO NODO
gnome-terminal -x sh -c "rosrun homework1 receiveChangeInfo"
gnome-terminal -x sh -c "rosrun homework1 printInfo"
gnome-terminal -x sh -c "rosrun homework1 sendInfo"
#xterm -hold -e bash secondo_nodo.sh &
#AVVIO TERZO NODO
#xterm -hold -e bash terzo_nodo.sh &
