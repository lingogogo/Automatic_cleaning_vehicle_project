#include <ros/ros.h>
#include <cmath>
#include <std_msgs/ColorRGBA.h>
#include <std_msgs/Float64.h>
#include <std_msgs/Int32.h>
using namespace std;

std_msgs::ColorRGBA catch_data;

// set up the data

int command_to_motor = 0;
int stop_command = 0;

//refresh data
float tem_center = 0;
float x_centerline = 640;
std_msgs::Float64 x_pixel_distance;
float x_center = 0;
float y_center = 0;
float image_width = 0;
float image_height = 0;
float theta_old = 0;
float theta_new = 0;
float *ptr;
int command_start = 0;//take the command to deal with the problem step by step
float result_v = 0;//take the angle data to correct the robot arm
float o_theta = 0;//the bottole origin theta

// different object with different class_id
// 0 = plastic bottle
int class_id = 0;
void result(float a,float b);
std_msgs::Int32 command_take;
	

void callback_data(const std_msgs::ColorRGBA::ConstPtr& msg){
	
	catch_data = *msg;
	x_center = catch_data.r;
	y_center = catch_data.g;
	
}	
void callback_command(const std_msgs::Int32::ConstPtr& msg1){

       	command_take  = *msg1;
	command_start = command_take.data;

}


int main(int argc,char** argv){

	// The ros first footstep
	ros::init(argc,argv,"trash_coordinate_recognize");
	ros::NodeHandle n;
	
	//===========================
	ros::Subscriber sub = n.subscribe("data_from_yolov3_all",1000,callback_data);
	ros::Publisher pub1 = n.advertise<std_msgs::Float64>("command_to_motor",1000);
	ros::Publisher pub2 = n.advertise<std_msgs::Float64>("rotate_angle_for_motor",1000);
	ros::Publisher pub3 = n.advertise<std_msgs::Int32>("check_object_location",1000);
	ros::Subscriber sub2 = n.subscribe("command_start",1000,callback_command);
	//===========================
	float old_re = 0;
	//origin data
	float o_image_width = 0;
	float o_image_height = 0;
	float check_result = 0;
	std_msgs::Float64 check_r;
	std_msgs::Int32 command_motor_pub;
	int command_to_motor = 0;
	ros::Rate rate(15);
	
	while(ros::ok()){
			
		image_width = catch_data.b;
		image_height = catch_data.a;
		//command_start mean it have to start progress
		if(command_start == 2){
			if(x_center == 0 && y_center == 0){
				//check the object location
				//publish info to motor to move forward or backward to check the object location
				command_motor_pub.data = command_to_motor;
				pub3.publish(command_motor_pub);
			}
			ros::spinOnce();
			// basic trash size 
			switch(class_id){
				case 0:
					o_image_width = 100;
					o_image_height = 250;
					o_theta = 0.34888;
					break;
			}
		
			// calculate the trash angle, in order to controll the robotic arm catch the bottle correctly.
			result(image_width,image_height);
			old_re = result_v;
			// check refresh data conform to the origin data,
			// if not ,we have to control the robotic arm to rotate to correct situation.
			//ERROR HERE
			if(old_re > 0.1){
				//clockwise rotate a little bit
				//However, the motor direction may not be correct.  
				command_to_motor = 0;//clockwise rotate first ,check the bottle posture.
				command_motor_pub.data = command_to_motor;

				pub1.publish(command_motor_pub);
				//return a number from the control arm code
				result(image_width,image_height);
				check_result = result_v - old_re;
				if(check_result > old_re){
					//wrong direction
					//rotate counterclockwise
					command_to_motor = 2;
					command_motor_pub.data = command_to_motor;

					pub1.publish(command_motor_pub);
					//output the angle to motor code
					
				}else if(check_result < old_re){
					command_to_motor = 1;
					command_motor_pub.data = command_to_motor;

					pub1.publish(command_motor_pub);

					//output rotate the same direction
					//output the rotate direction
				}
				//if the command output , what i have to do is to sending angle to the motor
				check_r.data = check_result; 
				pub2.publish(check_r);
				
				
				//a = return_number
				//if(a == 1){ command_to_motor = 1}
				//
					
			}
					
			//but there are two situation
			//plastic bottle toward to left or right
			
			//result = theta_new - theta_old;
			//theta_old = theta_new;

			//right direction , the theta_new will be smaller than theta_old
			//i have to find the error, because there is no
			//if(result > 0.05){
			//couterclockwise
			//	command_to_motor = 2;
			//}
				
			
			
		
		
		rate.sleep();
		}
	}
}	


void result(float a,float b){
	theta_new = atan(image_height/image_width);
	result_v = theta_new - o_theta;
}
