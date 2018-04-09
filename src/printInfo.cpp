//INCLUDE LIBRAY
#include "ros/ros.h"
#include "std_msgs/String.h"
///////////////////////////////////

//metodo per riceve il messaggio inviato dal receiveChanegeInfo
void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
  //stampa le info del messaggio
  ROS_INFO("%s", msg->data.c_str());
}

//ricezione del messaggio di "uccisione"
void stopMex(const std_msgs::String::ConstPtr& msg)
{
    std::cout << "I'm killing...\n";
    std::string tmp = msg->data.c_str();
    if (tmp.compare("kill") == 0)
        ros::shutdown();
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
  ros::init(argc, argv, "prinInfo2");
  /**
   * NodeHandle is the main access point to communications with the ROS system.
   * The first NodeHandle constructed will fully initialize this node, and the last
   * NodeHandle destructed will close down the node.
   */
  ros::NodeHandle n;
  //Sottoscrivo al pubblicatore con nome modifyInfo
  ros::Subscriber sub = n.subscribe("modifyInfo", 1000, chatterCallback);

  ros::Subscriber subKill = n.subscribe("kill", 1000, stopMex);
  //ricezione continua senza bisgono di while
  ros::spin();
  return 0;
}
