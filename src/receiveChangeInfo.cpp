//INCLUDE LIBRARY
#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>
#include <termios.h>
using namespace std;
///////////////////////////////
//GLOBAL VARIABLE
int receive = 0; //aspetto finchè il primo nodo non invia un messaggio
char c = 'a'; // carattere di scelta globale
std::string messaggio; //messaggio inviato dal nodo senfInfo
char temp = ' '; //richiesta inserimento nodo temporaneo
int cont = 0; //carattere che quando inserito vale 5 secondi
int posizioni[2]; //array per posizione di virgola dentro al messaggio
char carattere[3]; //numero di caratteri prima di ogni virgola dentro al messaggio

//INSERIMENTO CARATTERE SENZA PREMERE INVIO
//CARATTERE INSERITO VALE PER 5 SECONDI E POI VIENE RICHIESTO
char getch()
{
	  static struct termios oldt, newt;
		/*
		questa funzione prende in input dei parametri associati alla struttura termios
		riferita ad un file
		*/
	  tcgetattr( STDIN_FILENO, &oldt);      // salvo le impostazioni vecchie
	  newt = oldt;
	  newt.c_lflag &= ~(ICANON);  // disattivo il buffer
		 /*
 		questa funzione setta i parametri associati con un terminale (in questo caso
 		quello con cui stiamo lavorando) si riferisce ad un determinato file
 		descrittore da una struttura (definita sopra) terminos
 		*/
	  tcsetattr( STDIN_FILENO, TCSANOW, &newt);  // apply new settings

		//conto in modo da simulare 5 secondi
		cont++;
		//controllo che se non è uguale a prima il carattere selezionato oppure che
		//siano passati 5 secondi
		if (temp != c or cont >= 5)
		{
			printf("Inserisci il carattere: ");
			c = getchar();  // lettura carattere non bloccante
			printf("\n");
			cont = 0; //resetto i "5 secondi"
		}
		temp = c;

		//TCSANOW applica i cambiamneti immediatamente
	  tcsetattr( STDIN_FILENO, TCSANOW, &oldt);  // ripristino i valori di default
  return c;
}

//RICEVO I MESSAGGI DAL NODO "PADRE" E SE MI ARRIVANO ALLORA NON ASPETTO PIU E
//INIZIO L'ESECUZONE VERA E PROPRIA
void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
  receive = 1;
	//SALVO CIÒ CHE MI ARRIVA DAL NODO "PADRE" IN MESSAGGIO
  messaggio = msg->data.c_str();
}

//DIVIDO LA STRINGA IN PEZZI PER DIVEDERE LE VARIE INFORMAZIONI
std::string splittando(const std::string mex, char c)
{
	//indici per salvare le info negli array
	int i = 0, k = 0,l = 0;
	//uscita dal ciclo while
	bool empty = false;
	//indica la lunghezza totoale del messaggio
	int fine = mex.length();
	//conto i caratteri dopo ogni virgola
	int contoCar = 0;
	//ciclo che raccoglie informazioni per poi dividere la stringa
	while(i < mex.length() and empty == false)
	{
		//se lìil carattere non è virgola conto quanti caratteri ha
		if(mex[i] != ',')
		{
			contoCar++;
		}
		else // mex[i] == ','
		{
			//non inserisco più valori di posizione in posizioni dato che ha 2 celle solo
			if(l < 2)
			{
				posizioni[l] = i;
				l++;
			}
			//inserisco i caratteri prima di una virgola (mi serve per dividere)
			carattere[k] = contoCar;
			contoCar = 0; //resetto ogni volta il contatore
			k++;
			//se ho rimepito tutte le celle di carattere allora esco dal ciclo
			if (k >=2)
			{
				//condizione per uscita dal ciclo
				empty = true;
			}
		}
		i++;
	}

	//creo i pezzi delle info che mi verranno richieste
	std::string name = mex.substr(0, carattere[0]);
	std::string eta = mex.substr(posizioni[0] + 1, carattere[1]);
	std::string cdl = mex.substr(posizioni[1] + 1, fine - posizioni[1]);

	//restiuisco i valori in base alla scelta dell'utente
	if (c == 'n')
		return name;
	else if(c == 'e')
		return eta;
	return cdl;
}


int main(int argc, char **argv)
{

  /**
   * The ros::init() function needs to see argc and argv so that it can perform
   * any ROS arguments and name remapping that were provided at the command line.
   * For programmatic remappings you can use a different version of init() which takes
   * remappings directly, but for most command-line programs, passing argc and argv is
   * the easiest way to do it.  The third argument to init() is the name of the node.
   *
   * You must call one of the versions of ros::init() before using any other
   * part of the ROS system.
   */
  ros::init(argc, argv, "receiveChanegeInfo");

  /**
  •‘a’ verrà stampato tutto il messaggio
  •‘n’ mostrerà solo il nome
  •‘e’ mostrerà solo l’età
  •‘c’ mostrerà solo il corso di laurea
  */
  ros::NodeHandle n;

	//mi sottoscrivo al nosdo studentInfo
  ros::Subscriber sub = n.subscribe("studentInfo", 1000, chatterCallback);

	//imposto la ricezione con un rate di 1 secondo
  ros::Rate loop_rate(1);

	//aspetto se il nodo "padre" non mi invia alcun messaggio
  while(receive == 0)
  {
    ros::spinOnce();
    loop_rate.sleep();
	}

	//ho ricevuto almeno un messaggio
  if (receive == 1)
  {
		//creo il publisher per pubblicare i valori che il nodo "figlio" dovrà stampare
    ros::Publisher infoModify = n.advertise<std_msgs::String>("modifyInfo", 1000);
		//esco in caso di ctrl + c
    while (ros::ok())
    {
			//creo il messaggio msg
      std_msgs::String msg;
			//creo lo stream ss
      std::stringstream ss;
			//richiedo il carattere senza interrompere il flusso di esecuzione
      c = getch();
      if (c == 'a' or c == 'A') //TUTTO IL MESSAGGIO
      {
        ss << messaggio;
      }
			else if(c == 'n' or c == 'N') // ‘n’ mostrerà solo il nome
			{
				std::string name = splittando(messaggio,c);
				ss << name;
			}
			else if(c == 'e' or c == 'E') // 'e' mostrerà solo l'età
			{
				std::string eta = splittando(messaggio,c);
				ss << eta;
			}
			else if(c == 'c' or c == 'C') // ‘c’ mostrerà solo il corso di laurea
			{
				std::string cdl = splittando(messaggio,c);
				ss << cdl;
			}
			//qualsiasi altro carattere diverso da quelli precedenti mi fa uscire daò programma
			else if(ros::ok())
			{
				return 0;
			}

			//creo il messaggio contenente le info volute
      msg.data = ss.str();
			//pubblico il messaggio
      infoModify.publish(msg);
			//ricevo ogni volta un messaggio
      ros::spinOnce();
			//aspetto un secondo
      loop_rate.sleep();
    }
  }
  return 0;
}
