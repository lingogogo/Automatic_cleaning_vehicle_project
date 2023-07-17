#include <ros/ros.h>
#include <sensor_msgs/NavSatFix.h>

using namespace std;

sensor_msgs::NavSatFix current_gps;

int main(int argc,char** argv ){
	//set up the ros enviroment
	ros::init(argc,argv,"fix");
	ros::NodeHandle n;

	ros::Publisher pub = n.advertise<sensor_msgs::NavSatFix>("fix",1000);
	
	current_gps.latitude = 1;
	current_gps.longitude = 0;
	
	ros::Rate rate(15);
	while(ros::ok()){
		pub.publish(current_gps);
		rate.sleep();
	}
}
