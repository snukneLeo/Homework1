//INCLUDE LIBRARY
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "stdio.h"
#include <sstream>
#include "homework1/Message.h"

using namespace std;
///////////////////////////////


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
  ros::init(argc, argv, "sendInfo");

  /**
   * NodeHandle is the main access point to communications with the ROS system.
   * The first NodeHandle constructed will fully initialize this node, and the last
   * NodeHandle destructed will close down the node.
   */
  ros::NodeHandle n;

  //CREARE UN TOPIC CHE CONTIENE TUTTE LE CONVERSAZIONE SI CHIAMA CHATTER CHE È IL TOPIC E HA UN BUFFER DI 1000
  //uso la srtuttura dei messaggi
  ros::Publisher chatter_pub = n.advertise<homework1::Message>("studentInfo", 1000);
  //rate di un secondo
  ros::Rate loop_rate(1);

  //creo il messaggio con il message che ho creato
  homework1::Message infoStudent;

  //INVIO DEI MESSAGGI CON INSERIMENTO DELLE PARTI RICHIESTE
  std::string studente, eta, corsoLaurea;
  cout << "Insert your name: "; //nome
  std::getline (std::cin,studente); //inserimento anche di una stringa con spazi

  infoStudent.name = studente; //insertimento name dentro msg

  printf("\n");
  cout << "Insert your age: "; //età
  std::getline (std::cin,eta);

  infoStudent.eta = eta;//insertimento età dentro msg
  printf("\n");

  cout << "Insert your degree's name: "; //corso di laurea
  std::getline (std::cin,corsoLaurea);

  infoStudent.cdl = corsoLaurea;//insertimento corso di laurea dentro msg
  printf("\n");

  //esce quando riceve ctrl + c
  while (ros::ok())
  {
    //stampo a video le info
    ROS_INFO("Name: %s, Age: %s, Degree: %s", infoStudent.name.c_str(),infoStudent.eta.c_str(),infoStudent.cdl.c_str());
    //pubblico il MESSAGGIO
    chatter_pub.publish(infoStudent);
    //aspetto un secondo
    loop_rate.sleep();
  }
  return 0;
}
