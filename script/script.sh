#!/bin/bash

#AVVIO ROSCORE NODO MASTER
xterm -hold -e roscore &
sleep .5
#AVVIO PRIMO NODO
xterm -hold -e bash primo_nodo.sh &
#AVVIO SECONDO NODO
xterm -hold -e bash secondo_nodo.sh &
#AVVIO TERZO NODO
xterm -hold -e bash terzo_nodo.sh &
