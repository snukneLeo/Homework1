//INCLUDE LIBRAY
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "homework1/Message.h"
using namespace std;
///////////////////////////////////
std::string mex; //messaggio
std::string c = "a"; //carattere scelto

std::string name = ""; //nome
std::string age = ""; //età
std::string cdl = ""; //corso di laurea


//TOPIC SELECTOR
void carattereInserito(const std_msgs::String::ConstPtr& msg)
{
  //carico il comando arrivato dal nodo di scelta
  c = msg->data;
}


//TOPIC STUDENTINFO
void infoStudent(const homework1::Message msg)
{
  //carico le varibili nella struttura del messaggio
  name = msg.name.c_str();
  age = msg.eta.c_str();
  cdl = msg.cdl.c_str();
  //stringa finale
  std::string ss;

  if (c == "a") //messaggio completo
  {
    ss = name + "-" + age + "-" + cdl;
    ROS_INFO("%s", ss.c_str());
  }
  else if(c == "n") // ‘n’ mostrerà solo il nome
  {
    ss = name;
    ROS_INFO("---> NAME: %s", name.c_str());
  }
  else if(c == "e") // 'e' mostrerà solo l'età
  {
    ss = age;
    ROS_INFO("---> AGE: %s", age.c_str());
  }
  else if(c == "c") // ‘c’ mostrerà solo il corso di laurea
  {
    ss = cdl;
    ROS_INFO("---> CDL: %s", cdl.c_str());
  }
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
  ros::init(argc, argv, "prinInfo");
  /**
   * NodeHandle is the main access point to communications with the ROS system.
   * The first NodeHandle constructed will fully initialize this node, and the last
   * NodeHandle destructed will close down the node.
   */
  ros::NodeHandle n;

  ros::Subscriber studentInfo = n.subscribe("studentInfo",1000, infoStudent); //ricezione info studente
  ros::Subscriber sub = n.subscribe("selector", 1000, carattereInserito); //ricezione carattere

  //imposto la ricezione con un rate di 1 secondo
  ros::Rate loop_rate(1);

  //aspetto se il nodo "padre" non mi invia alcun messaggio
  std::cout << "I'm waiting father's node\n";
  //attesa dei messaggi dagli altri nodi
  ros::spin();
  //attendo un secondo
  loop_rate.sleep();


  return 0;
}
