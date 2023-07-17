#include <iostream>
#include <std_msgs/ColorRGBA.h>
#include <ros/ros.h>
#include <dataget/imdata.h>
#include <std_msgs/Int32.h>
#include <std_msgs/Float64.h>
using namespace std;

//========================
//datas
std_msgs::ColorRGBA data_catch;
float y_center = 0;
float x_center = 0;
float width = 0;
float height = 0;
float tem_center = 0;
float x_centerline = 640;
int command_start = 0;
int frame_id = 0;
float x_center_c = 0;
float y_center_c = 0;
float width_c = 0;
float height_c = 0;
std_msgs::Int32 command;
std_msgs::Float64 x_pixel_distance;
dataget::imdata take_data;
//========================



void callback_y_center(const std_msgs::ColorRGBA::ConstPtr& msg){
	data_catch = *msg;
	x_center = data_catch.r;
	y_center = data_catch.g;
	width = data_catch.b;
	height = data_catch.a;	
}
void callback_y_center_custom(const dataget::imdata::ConstPtr& msg1){
        take_data = *msg1;
	frame_id = take_data.frameid;
        x_center_c = take_data.x;
        y_center_c = take_data.y;
        width_c = take_data.width;
        height_c= take_data.height;
}


void callback_command_start(const std_msgs::Int32::ConstPtr& msg2){
	command = *msg2;
	command_start = command.data;
}




int main(int argc, char** argv){
	ros::init(argc,argv,"find_target");
	ros::NodeHandle n;
	
	ros::Subscriber sub1 = n.subscribe<std_msgs::ColorRGBA>("data_from_yolov3_all",100,callback_y_center);
	ros::Publisher pub1 = n.advertise<std_msgs::ColorRGBA>("send_the_next_target_INFO",100);
	ros::Publisher pub2 = n.advertise<std_msgs::Float64>("image_centerline_distance",100);
	ros::Subscriber sub2 = n.subscribe<std_msgs::Int32>("command_start",100,callback_command_start);
	ros::Publisher pub3 = n.advertise<std_msgs::Int32>("command_start",100);


	int tem_id = 0;
	ros::Rate rate(15);
	int count = 0;
	command_start = 1;
	while(ros::ok()){
		ros::spinOnce();

		//need a command_start input to this program to make it run.
		if(command_start == 1){
			
			
			if(y_center >= tem_center && tem_id == frame_id){
				pub1.publish(data_catch);
				count++;		
			}
			if(tem_id != frame_id && count != 0){
				count = 0;
				command.data = 3;//next process run
				//command_start = 0
				//control robot arm
				pub2.publish(command);
			}
			tem_id = frame_id;
			x_pixel_distance.data = x_centerline - x_center;
			tem_center = y_center;
			rate.sleep();
		}
	}
	
	
}
