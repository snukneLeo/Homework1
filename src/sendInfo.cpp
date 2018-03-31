//INCLUDE LIBRARY
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "stdio.h"
#include <sstream>
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

  /**
   * The advertise() function is how you tell ROS that you want to
   * publish on a given topic name. This invokes a call to the ROS
   * master node, which keeps a registry of who is publishing and who
   * is subscribing. After this advertise() call is made, the master
   * node will notify anyone who is trying to subscribe to this topic name,
   * and they will in turn negotiate a peer-to-peer connection with this
   * node.  advertise() returns a Publisher object which allows you to
   * publish messages on that topic through a call to publish().  Once
   * all copies of the returned Publisher object are destroyed, the topic
   * will be automatically unadvertised.
   *
   * The second parameter to advertise() is the size of the message queue
   * used for publishing messages.  If messages are published more quickly
   * than we can send them, the number here specifies how many messages to
   * buffer up before throwing some away.
   */
  //CREARE UN TOPIC CHE CONTIENE TUTTE LE CONVERSAZIONE      SI CHIAMA CHATTER CHE È IL TOPIC E HA UN BUFFER DI 1000
  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("studentInfo", 1000);
//HZ CON CUI INVIARE I NOSTRI MESSAGGI
  ros::Rate loop_rate(1);

  /**
   * A count of how many messages we have sent. This is used to create
   * a unique string for each message.
   */
//INVIO DEI MESSAGGI CON INSERIMENTO DELLE PARTI RICHIESTE
std::string studente, eta, corsoLaurea;
cout << "Insert your name: "; //nome
std::getline (std::cin,studente); //inserimento anche di una stringa con spazi
printf("\n");
cout << "Insert your age: "; //eta
std::getline (std::cin,eta);
printf("\n");

cout << "Insert your degree's name: "; //corso di laure
std::getline (std::cin,corsoLaurea);
printf("\n");

//esce quando riceve ctrl + c
while (ros::ok())
{
  //crea il messaggio
  std_msgs::String msg;
  //crea lo stream ss
  std::stringstream ss;
  //inserisco le info nello stream ss
  ss << studente << "," << eta << "," << corsoLaurea;
  //inserisco in msg le info
  msg.data = ss.str();
  //stampo a video le info
  ROS_INFO("%s", msg.data.c_str());
  //pubblico il MESSAGGIO
  chatter_pub.publish(msg);
  ros::spinOnce();
  //aspetto un secondo
  loop_rate.sleep();
}
  return 0;
}
