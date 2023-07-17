#include <iostream>
#include <fstream>
#include <iomanip>
#include <ros/ros.h>
#include <std_msgs/Float64.h>

using namespace std;
std_msgs::Float64 getx;
std_msgs::Float64 gety;

int i = 0;
double vecx[10]={0};
double vecy[10]={0};
double x_number;
double y_number;
int x = 0;
int y = 0;
double resultx = 0;
double resulty = 0;

void callbackx(const std_msgs::Float64::ConstPtr& msg){
	getx = *msg;
}

void callbacky(const std_msgs::Float64::ConstPtr& msg){
        gety = *msg;
}






int main(int argc, char** argv){
	ros::init(argc,argv,"fourspotfromgps");
	ros::NodeHandle n;
	ros::Subscriber sub_x = n.subscribe("/fix",1000,callbackx);
        ros::Subscriber sub_y = n.subscribe("/fix",1000,callbacky);

	ros::Rate loop_rate(15);
	while(ros::ok()){
		ros::spinOnce();
		vecy[y] = gety.data;
		vecx[x] = getx.data;
		if(x == 9 && y == 9){
			x = 0;
			y = 0;
		}
		for(int k = 0; k<10;k++){
			resultx = resultx + vecx[k];
			resulty = resulty + vecy[k];
		}
		//divide 10 to get average number.
		resultx = resultx/10;
		resulty = resulty/10;
		//find error to decide the number is myspot
		resultx = resultx - vecx[x];
		resulty = resulty - vecy[y];
		if(resultx<0.0000000001 && resulty<0.0000000001){

			ofstream myfile("location_spot",ios::app);
			myfile.open("location_spot");
			myfile << std::setprecision(20)  << resultx << " " << resulty << endl;
			myfile.close();
		}

	}
}

