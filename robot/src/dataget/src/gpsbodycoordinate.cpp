/*
 *it will get the vector when the robot has a change on direction 
 *the program will give me the the robot vector from GPS.
 *however, it is not accurate.
 *the GPS electronic receiver has a error between 2.5m in circle.
 */

#include <ros/ros.h>
#include <cmath>
#include <std_msgs/Float64.h>
#include <complex>
#include <sensor_msgs/NavSatFix.h>
#define pi 3.14156
using namespace std;
//save the old and new number
double x_before = 0;
double y_before = 0;
double x_last = 0;
double y_last = 0;
int k = 0;//k number is to change the switch for the info from GPS
std_msgs::Float64 x_d;
std_msgs::Float64 y_d;
sensor_msgs::NavSatFix get_x;
sensor_msgs::NavSatFix get_y; //data from GPS latitude

double xnum; //the variable is representation for get_x
double ynum; //the variable is representation for get_x

void callbackGPSx(const sensor_msgs::NavSatFix::ConstPtr& msg){
	get_x=*msg;
}
void callbackGPSy(const sensor_msgs::NavSatFix::ConstPtr& msg){
	get_y=*msg;
}

int main(int argc, char** argv){
	ros::init(argc,argv,"GPSdirection");
	ros::NodeHandle n;
	//get the longitude and latitude from GPS accepter
	ros::Subscriber sub_x = n.subscribe("/fix",1000,callbackGPSx);
	ros::Subscriber sub_y = n.subscribe("/fix",1000,callbackGPSy);

	ros::Publisher pub_x = n.advertise<std_msgs::Float64>("body_vector_vx",1000);
	ros::Publisher pub_y = n.advertise<std_msgs::Float64>("body_vector_vy",1000);
	

	ros::Rate loop_rate(15);
	while(ros::ok()){
		//change the switch for the info
		k = k%2;
		xnum=get_x.longitude;
		ynum=get_y.latitude;
		switch(k){
			case 0:
				x_before = xnum;
				y_before = ynum;
				k++;
				break;
			case 1:
				x_last = xnum;
				y_last = ynum;
				k++;
				break;
		}
		//make the vector for the robot whenever it go
		
		if (x_before != 0 && y_before != 0 && x_last != 0 && y_last != 0){
			x_d.data = x_last - x_before;
			y_d.data = y_last - y_before;
		}
		pub_x.publish(x_d);
		pub_y.publish(y_d);
		ros::spinOnce();
		loop_rate.sleep();
	}
}
		

