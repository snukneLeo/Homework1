//PRIMO NODO
//INCLUDE LIBRARY
#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>
#include <termios.h>
using namespace std;
///////////////////////////////

//menu
const std::string menu = "+ Digita 'a' per stampare tutto il messaggio\n"
                    "+ Digita 'n' per mostrare il nome\n"
                    "+ Digita 'e' per mostrare l'età\n"
                    "+ Digita 'c' per mostrare il corso di laurea\n"
                    "+ Digita 'q' per uscire\n";

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

  ros::NodeHandle n;

	//imposto la ricezione con un rate di 1 secondo
  ros::Rate loop_rate(1);

	//publisher per invio selezione
  ros::Publisher infoModify = n.advertise<std_msgs::String>("selector", 1000);

  //carattere consentito
  int check = 1;

  while (ros::ok())
  {
		//creo il messaggio msg
    std_msgs::String msg;

    //carattere di scelta
    std::string c;
    //stampa menu
    std::cout << menu;
    //richiedo il carattere
    std::cin >> c;
    std::cout << "\n";

    //controllo se è errato
    if(c != "a" && c != "n" && c != "e" && c != "c" && c != "q")
    {
      check = 0;
      std::cout << "Carattere non corretto! Riprova" << '\n';
    }
    //esco se 'q'
    if(c == "q")
    {
      check = 0;
      ros::shutdown(); //chiudo il nodo
    }
    //se è tutto ok invio il messaggio
    if(check == 1)
    {
      std::cout << c;
      msg.data = c;
  		//pubblico il messaggio
      infoModify.publish(msg);
  		//aspetto un secondo
      loop_rate.sleep();
    }
  }
  return 0;
}
