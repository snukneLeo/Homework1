#!/bin/bash

#AVVIO ROSCORE NODO MASTER
xterm -hold -e roscore &
#ASPETTO UN SECONDO PRIMA DI FAR PARTIRE GLI ALTRI NODI
#IN MODO DA NON AVERE ERRORI NELLA CONNESSIONE
#AL NODO MASTER PER I NODI FIGLI
sleep 1.0
#AVVIO PRIMO NODO
xterm -hold -e bash primo_nodo.sh &
#AVVIO SECONDO NODO
xterm -hold -e bash secondo_nodo.sh &
#AVVIO TERZO NODO
xterm -hold -e bash terzo_nodo.sh &
