#include <ros/ros.h>
#include <sensor_msgs/NavSatFix.h>
#include <cmath>

using namespace std;

sensor_msgs::NavSatFix catch_data;

void callback_fix(const sensor_msgs::NavSatFix::ConstPtr& msg){
	catch_data = *msg;
}

int main(int argc,char** argv){
	//ros node 
	ros::init(argc,argv,"point_store_to_check_spot");
	ros::NodeHandle n;
	
	ros::Subscriber sub = n.subscribe("/fix",1000,callback_fix);

	//Elements are from /fix
	double point_array_x[1000][1000] = {0};// x_axis'x to origin'x
 	double point_array_y[1000][1000] = {0};// y_axis'y to origin'y
	
	//Elements are 1 or 0 
	//if the robot doesn't run with the point_array , it will be still 0
	//path_array[x][y]
	double path_array[1000][1000] = {0};


	//workspot area
	double origin[2] = {0};
	double x_axis[2] = {0};
	double y_axis[2] = {0};
	double xy_axis[2] = {0};
	double fix_x = 0;
	double fix_y = 0;
	double result = 0;
	//length between two spots.	
	double length_x_ori_x = 0;// x_axis'x to origin'x
	double length_y_ori_y = 0;// y_axis'y to origin'y
	double length_y_ori_x = 0;// y_axis'x to origin'x
	double length_x_ori_y = 0;// x_axis'y to origin'y
	
	
	//==============
	//set up the data

	//==============

	//however, the length calculate must conform to the square area.
	
	length_x_ori_x = (x_axis[0] - origin[0])/999; // because there are 1000 points with two head spot.
	length_y_ori_y = (y_axis[1] - origin[1])/999;
	length_y_ori_x = (y_axis[0] - origin[0])/999; 
	length_x_ori_y = (x_axis[1] - origin[1])/999; 		 	
	for(int j = 0;j<1000;j++){
		for(int i = 0; i<1000 ;i++){
			
			if(xy_axis[1] > y_axis[1]){
				j = -j;
			}
			point_array_x[j][i] = origin[0] + i*length_x_ori_x + j*length_y_ori_x;// the origin point plus the distance from x_axis to origin and the last one is the distance from y_axis'x to x_axis'x 
			point_array_y[j][i] = origin[1] + i*length_y_ori_y - j*length_x_ori_y;		
		}	
	}

	//start while loop
	ros::Rate rate(15);
	while(ros::ok()){

		
		ros::spinOnce();
		fix_x = catch_data.longitude;
		fix_y = catch_data.latitude;
		
		
		//check any number is close to the robot_fix_now
		for(int j = 0;j < 1000;j++){
			for(int i = 0 ;i < 1000;i++){
				fix_x = fix_x - point_array_x[j][i];
				fix_x = fix_x - point_array_x[j][i];
				result = sqrt(pow(fix_x,2) + pow(fix_y,2));
				if(result < 0.00001){
					path_array[j][i] = 1;
				}
			}
		}
		rate.sleep();
	}
	
	
}
