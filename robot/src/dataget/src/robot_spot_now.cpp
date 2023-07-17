#include <ros/ros.h>
#include <sensor_msgs/NavSatFix.h>

using namespace std;

sensor_msgs::NavSatFix catch_data;

void callback_fix(const sensor_msgs::NavSatFix::ConstPtr& msg){
	catch_data = *msg;
}

int main(int argc,char** argv){
	//ros node 
	ros::init(argc,argv,"point_store_to_check_spot");
	ros::NodeHandle n;
	

	ros::Subscriber sub = n.subscribe/*<sensor_msgs::NavSatFix>*/("/fix",1000,callback_fix);
	
	//we will have 4 spot, the robot have to clean the area without running out of the area
	
	double location_now[2] = {0};
	double origin[2] = {0};
	double x_axis[2] = {0};
	double y_axis[2] = {0};
	double xy_axis[2] = {0};
	double reference_line[2] = {0};
	float theta = 0;
	int error = 0;
	double origin_v[2] = {0};
        double x_axis_v[2] = {0};
        double y_axis_v[2] = {0};
        double xy_axis_v[2] = {0};

	//==============
	//must enter into the four angle spot.
	origin[0] = 0;
	origin[1] = 0;
	x_axis[0] = -1;
	x_axis[1] = 0;
	y_axis[0] = 0;
	y_axis[1] = 1;
	xy_axis[0] = -1;
	xy_axis[1] = 1;

	//==============


	ros::Rate rate(15);
	while(ros::ok()){
	
		ros::spinOnce();
		location_now[0] = catch_data.longitude;
		location_now[1] = catch_data.latitude;
	
		for(int i = 0;i<2;i++){	
			reference_line[i] = xy_axis[i] - y_axis[i];
			origin_v[i] = origin[i] - location_now[i];
			x_axis_v[i] = x_axis[i] - location_now[i];
			y_axis_v[i] = y_axis[i] - location_now[i];
			xy_axis_v[i] = xy_axis[i] - location_now[i];
	
		}
	
		//rotate array
		//first step we have to find spot.
		theta = acos(1*reference_line[0]/sqrt(pow(reference_line[0],2)+pow(reference_line[1],2)));
		cout << theta << " ";
		for(int i = 0;i<2;i++){
			if(i == 0){
				origin_v[i] = cos(theta)*origin_v[i]-sin(theta)*origin[i];
				x_axis_v[i] = cos(theta)*x_axis_v[i]-sin(theta)*x_axis[i];
				y_axis_v[i] = cos(theta)*y_axis_v[i]-sin(theta)*y_axis[i];
				xy_axis_v[i] = cos(theta)*xy_axis_v[i]-sin(theta)*xy_axis[i];			
			}else{
				origin_v[i] = cos(theta)*origin_v[i]+sin(theta)*origin[i];
				x_axis_v[i] = cos(theta)*x_axis_v[i]+sin(theta)*x_axis[i];
				y_axis_v[i] = cos(theta)*y_axis_v[i]+sin(theta)*y_axis[i];
				xy_axis_v[i] = cos(theta)*xy_axis_v[i]+sin(theta)*xy_axis[i];
			}			
		}
		//check that every vector are in the four quardrant
		cout << y_axis_v[0] <<" " << y_axis_v[1]<<" " ;	
		if(xy_axis_v[0] < 0 || xy_axis_v[1] < 0 || x_axis_v[0] < 0 || x_axis_v[1] > 0 || y_axis_v[0] > 0 || y_axis_v[1] < 0 || origin_v[0] > 0 || origin_v[1] > 0){
				
			//it means that the robot is in the area
			error = 1;
		}
		cout << error <<endl;	
		rate.sleep();
	}
	
		
}
