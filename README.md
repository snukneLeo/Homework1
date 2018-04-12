# HOMEWORK_1<br>ROS communication based example

Homework1 è un esercizio per casa in cui tre nodi comunicano tra loro attraverso il sistema operativo ROS<br>
<html>
  <head>
  </head>
  <body>
    <ul>
      <li>
      Il primo nodo richiede il nome, età, corso di laurea. Una volta inserito tutto ciò le invierà terzo nodo.
      </li>
      <li>
      Il secondo nodo richiede di inserire: <br>
                                            'a' per visualizzare tutto il messaggio (nome,età,cdl) <br>
                                            'n' per visualizzare solo il nome <br>
                                            'e' per visualizzare solo l'età <br>
                                            'c' per visualizzare solo la cdl <br>
                                            'q' per uscire dal programma <br>
      Il carattere sarà inviato al terzo nodo. Se il carattere inserito non è tra quelli a scelta verrà segnalato un errore.
      </li>
      <li>
      Il terzo nodo mostrerà di default tutto il messaggio e nel caso l'utente inserisca una scelta verrà mostrato solo la parte del messaggio richiesta. <br>
      </li>
    </ul>
    <h2> Come eseguire il programma ROS </h2>
    Il programma può essere eseguito nel seguente modo:
    <ul>
      <li>
      Aprire il terminale all'interno della cartella script.
      </li>
      <li>
      Scrivere nel terminale:
      <pre> $ ./script.sh </pre> <br>
      Si apriranno altre 3 bash. <br>
      In questi 3 terminali ci saranno: 1° nodo, 2°nodo e 3° nodo. <br>
      </li>
    </ul>
    <h2> Ulteriore metodo per eseguire il programma </h2>
    <blockquote>
    <ul>
      <li>
        Aprire il terminale e digitare il comando: <br>
        <pre>$ roscore </pre> <br>
      </li>
      <li>
        Aprire il terminale e digitare il comando: <br>
        <pre>$ rosrun homework1 sendInfo </pre> <br>
      </li>
      <li>
        Aprire un ulteriore terminale e digitare il comando: <br>
        <pre>$ rosrun homework1 receiveChangeInfo </pre> <br>
      </li>
      <li>
        Aprire un ulteriore terminale e digitare il comando: <br>
        <pre>$ rosrun homework1 printInfo </pre> <br>
      </li>
    </ul>
    </blockquote>
    <h3> Illustrazione sull'esecuzione del programma <b>senza</b> script </h3>
  </body>
</html>

<!-- CAMBIARE SOLO IMMAGINE DEL SENDINFO -->
<b>Nodo master:</b> <br>
![node master](images/roscore.png) <br>
<b>Nodo 1:</b> <br>
![node 1](images/sendInfo.png) <br>
<b>Nodo 2:</b> <br>
![node 2](images/receiveInfo.png) <br>
<b>Nodo 3:</b> <br>
![node 3](images/printInfo.png) <br>

<html>
  <head> </head>
  <body>
    <h3> Illustrazione esecuzione programma <b>con</b> script </h3>
  </body>
</html>

 <!-- DA MODIFICARE LE IMMAGINI -->
<b>Lancio script: </b> <br>
![script start](images/script.png) <br>

<!-- CAMBIARE IMMAGINE NODI -->
La struttura dell'esercizio può essere sintetizzata nell'immagine seguente:<br>
<b>Nodes Graph:</b> <br>
![node Graph](images/rosgraphOnlyNode.png) <br>
<b>Nodes Graph with all components: </b>
![Node Graph with all components](images/rosgraph.png) <br>

<html>
  <head> </head>
  <body>
    <h3> Illustrazione esecuzione programma con <b>roslaunch</b> </h3>
    <blockquote>
    <p>
    Aprire il terminale e posizionarsi sulla cartella catkin_ws. <br>
    Digitare:
    <pre>$ roslaunch homework1 info.launch </pre>
    Ciò che apparirà saranno i tre terminali con cui si interagisce con il programma
    </p>
    </blockquote>
  </body>
</html>


<b>Esecuzione programma con roslaunch: </b> <br>
![script esecuzione](images/infoLaunch.png.png) <br>

<b>Esecuzione programma con roslaunch, modalità classica oppure script: </b><br>
![Esecuzione programma](images/esecuzione.png)


Please, report suggestions/comments/bugs to<br>
snukne96@gmail.com
