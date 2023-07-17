//I want to get the robot body coordinate by IMU and GPS, so it will publish the robot coordinate 
//body_vector_X and body_vector_Y
//Float64(double)

#include <ros/ros.h>
#include <cmath>
#include <std_msgs/Float64.h>
#include <complex>
#include <std_msgs/Int32.h>
#define pi 3.14156
using namespace std;

std_msgs::Float64 re_imudata;
std_msgs::Float64 re_bodyVx;
std_msgs::Float64 re_bodyVy;
std_msgs::Float64 pub_bodyVx_num;
std_msgs::Float64 pub_bodyVy_num;
double bodyVx_i = 0;
double bodyVy_i = 0;
int yaw_i = 0;
double bodyVx_last = 0;
double bodyVy_last = 0;
int yaw_last = 0;
double yaw_minus = 0;


void callbackimu(const std_msgs::Float64::ConstPtr& msg)
{
	re_imudata = *msg;
}

void callbackbodyVx(const std_msgs::Float64::ConstPtr& msg)
{
	re_bodyVx = *msg;
}

void callbackbodyVy(const std_msgs::Float64::ConstPtr& msg)
{
	re_bodyVy = *msg;
}

int main(int argc, char** argv)
{
	//Declare the subscribe and publisher
	ros::init(argc,argv,"combine_imuandbodyvector");
	ros::NodeHandle n;
	ros::Subscriber sub_imu = n.subscribe("/compass_yaw_Data",1000,callbackimu);
        ros::Subscriber sub_bodyVx = n.subscribe("spot_vector_x",1000,callbackbodyVx);
        ros::Subscriber sub_bodyVy = n.subscribe("spot_vector_y",1000,callbackbodyVy);
	ros::Publisher pub_bodyVx = n.advertise<std_msgs::Float64>("body_vector_X",1000);
	ros::Publisher pub_bodyVy = n.advertise<std_msgs::Float64>("body_vector_Y",1000);

	

	for(int i = 1 ; i<10;i++)
	{
		ros::spinOnce();
		bodyVx_i = re_bodyVx.data;
		bodyVy_i = re_bodyVy.data;
		yaw_i = re_imudata.data;

	}
	//testcode operation
	/*
	bodyVx_i = 2;
	bodyVy_i = 1;
	*/	
	complex<double> body_vector(bodyVx_i,bodyVy_i);
	//looprate beginning
	ros::Rate loop_rate(15);
	while(ros::ok())
	{
		
		//get the new data
		while(bodyVx_i == 0 && bodyVy_i ==0)
		{	
			ros::spinOnce();
			bodyVx_i= re_bodyVx.data;
			bodyVy_i = re_bodyVy.data;
			yaw_last = re_imudata.data;
		}
			complex<double> body_vector(bodyVx_i,bodyVy_i);
		cout << bodyVx_i <<" "<<bodyVy_i<<endl;

		//change to rad
		//**problem for this
		//i will get gage data when the IMU approach to 0 degree and 360
	
		yaw_minus = (yaw_last - yaw_i)*pi/180;
		double yaw_m_cos = cos(yaw_minus);
		double yaw_m_sin = sin(yaw_minus);
		//exponential for angle change
		complex<double> yaw(yaw_m_cos,yaw_m_sin);

		//the body vector will change for the IMU data
		//However, the IMU accuracy have to improve.
		body_vector = body_vector*yaw;
		double realpart = real(body_vector);
		double imaginepart = imag(body_vector);
		pub_bodyVx_num.data = realpart;
		pub_bodyVy_num.data = imaginepart;

		pub_bodyVx.publish(pub_bodyVx_num);
		pub_bodyVy.publish(pub_bodyVy_num);
		ros::spinOnce();
		loop_rate.sleep();
	}



}

