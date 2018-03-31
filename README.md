# HOMEWORK_1<br>ROS communication based example

This file is part of homework and it is distributed under the terms of the
GNU Lesser General Public License (Lesser GPL)

Homework1 è un esercizio per casa in cui tre nodi comunicano tra loro attraverso il sistema operativo ROS<br>
<html>
  <head>
  </head>
  <body>
    <ul>
      <li>
      Il primo nodo richiede il nome, età, corso Informatica.
      </li>
      <li>
      Il secondo nodo richiede di inserire:
                                            'a' per visualizzare tutto il messaggio (nome,età,cdl) <br>
                                            'n' per visualizzare solo il nome <br>
                                            'e' per visualizzare solo l'età <br>
                                            'c' per visualizzare solo la cdl
      </li>
      <li>
      Il terzo nodo mostrerà ciò che nel secondo nodo è stato selezionato <br>
      </li>
    </ul>
    <h2> Come eseguire il programma ROS </h2>
    <hr>
    Il programma può essere eseguito nel modo in cui segue:
    <ul>
      <li>
      Aprire il terminale all'interno della cartella script.
      </li>
      <li>
      Scrivere nel terminale: ./script.sh si apriranno altre 3 bash (xterminal).
      In 3 terminali saranno: 1° nodo, 2°nodo e 3° nodo.
      </li>
    </ul>
    <h2> Ulteriore metodo per eseguire il programma </h2>
    <hr>
    <ul>
    <li>
    Aprire il terminale e digitare roscore
    </li>
    <li>
    Aprire il terminale e posizionarsi in catkin_ws e digitare il comando rosrun homework1 sendInfo
    </li>
    ![image nodo 1](images/sendInfo.png)
    <li>
    Aprire un ulteriore terminale e posizionarsi in catkin_ws e digitare il comando rosrun homework1 receiveChangeInfo
    </li>
    <li>
    Aprire un ulteriore terminale e posizionarsi in catkin_ws e digitare il comando rosrun homework1 printInfo
    </li>
    </ul>
  </body>
</html>

[Node Programming in ROS (c++)]<br>
A.Y. 2017/2018<br>

Please, report suggestions/comments/bugs to<br>
snukne96@gmail.com
