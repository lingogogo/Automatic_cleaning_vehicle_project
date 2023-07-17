#include "ros/ros.h"
#include "sensor_msgs/NavSatFix.h"
#include <iostream>
using namespace std;


sensor_msgs::NavSatFix current_gps;

void gps_cb(const sensor_msgs::NavSatFix::ConstPtr& msg)
{
	current_gps = *msg;
	printf("%f %f %f\n",current_gps.latitude,current_gps.longitude,current_gps.altitude);
}

int main(int argc,char **argv)
{
	ros::init(argc,argv,"get_gpsdata");
	ros::NodeHandle n;
	cout<<"let's start to take the GPS data"<<endl;

	ros::Subscriber gps_sub = n.subscribe<sensor_msgs::NavSatFix>("fix",100,gps_cb);

	ros::Rate rate(20.0);

	while(ros::ok())
	{
		ros::spinOnce();


		rate.sleep();
	}

	return 0;
}

