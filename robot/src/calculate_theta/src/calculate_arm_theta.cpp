#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "dataget/five_dof_kinematic.h"
#include "dataget/MyMatrix.h"
#include <ros/ros.h>
#include <std_msgs/Float64.h>
#include <std_msgs/Int32.h>
#include <std_msgs/Float64MultiArray.h>
std_msgs::Float64 catch_dis;
std_msgs::Int32 catch_command;
std_msgs::Float64 motor_theta;
float distance = 0;
int command = 0;
void callback_d(const std_msgs::Float64::ConstPtr& msg){
	catch_dis = *msg;
	distance = catch_dis.data;

}
void callback_command(const std_msgs::Int32::ConstPtr& msg1){
	catch_command = *msg1;
	command = catch_command.data;
}
int main(int argc, char** argv)
{
	ros::init(argc,argv,"arm_angle");
	ros::NodeHandle n;
	
	
	ros::Subscriber sub1 = n.subscribe<std_msgs::Float64>("distance",100,callback_d);
	ros::Subscriber sub2 = n.subscribe<std_msgs::Int32>("command_start",100,callback_command);
	ros::Publisher pub1 = n.advertise<std_msgs::Float64>("theta1",1000);
	ros::Publisher pub1_2 = n.advertise<std_msgs::Float64>("o_theta1",1000);

	ros::Publisher pub1_3 = n.advertise<std_msgs::Float64>("motor_theta1",1000);
	ros::Publisher pub2_3 = n.advertise<std_msgs::Float64>("motor_theta2",1000);
	ros::Publisher pub3_3 = n.advertise<std_msgs::Float64>("motor_theta3",1000);
	ros::Publisher pub4_3 = n.advertise<std_msgs::Float64>("motor_theta4",1000);
	ros::Publisher pub5_3 = n.advertise<std_msgs::Float64>("motor_theta5",1000);
	ros::Publisher pub6_3 = n.advertise<std_msgs::Float64>("motor_theta6",1000);

	ros::Publisher pub2 = n.advertise<std_msgs::Float64>("theta2",1000);
	ros::Publisher pub2_2 = n.advertise<std_msgs::Float64>("o_theta2",1000);
	ros::Publisher pub3 = n.advertise<std_msgs::Float64>("theta3",1000);
	ros::Publisher pub3_2 = n.advertise<std_msgs::Float64>("o_theta3",1000);
	ros::Publisher pub4 = n.advertise<std_msgs::Float64>("theta4",1000);
	ros::Publisher pub4_2 = n.advertise<std_msgs::Float64>("o_theta4",1000);
	ros::Publisher pub5 = n.advertise<std_msgs::Float64>("theta5",1000);
	ros::Publisher pub5_2 = n.advertise<std_msgs::Float64>("o_theta5",1000);
	ros::Publisher pub6 = n.advertise<std_msgs::Float64>("theta6",1000);
	ros::Publisher pub6_2 = n.advertise<std_msgs::Float64>("o_theta6",1000);
	//command 3 will be start to control the robotic arm.
	
	Matrix fk_T, r_t , Ry , Rz , Rx, T,ik_T ,o_T,ok_T;
	
	T = Create_Matrix(3,1);
	fk_T = Create_Matrix(3,3);
	r_t = Create_Matrix(4,4);
	//Rx * Ry *Rz
	//Getting from two coordinate , coordinate 0 and coordinate 6 when the target object is detected.
	Ry = Create_Matrix(3,3);
	Rx = Create_Matrix(3,3);
	Rz = Create_Matrix(3,3);
	float theta_x[] = {1,0,0,0,-1,0,0,0,-1};
	float theta_y[] = {-1,0,0,0,1,0,0,0,-1};
	float theta_z[] = {-1,0,0,0,-1,0,0,0,1};
	SetData_Matrix(Ry,theta_y);
	SetData_Matrix(Rz,theta_z);
	SetData_Matrix(Rx,theta_x);
	//Show_Matrix(Ry);
	fk_T = Mult_Matrix(Ry,Rz);
	//fk_T = Mult_Matrix(fk_T,Rz);
	
	//origin state
	o_T = Create_Matrix(4,4);
	float o_data[16] = {0,0,1,16, 0,-1,0,0,1,0,0,12,0,0,0,1};
	SetData_Matrix(o_T,o_data);
	Show_Matrix(o_T);

	//TEST
	command = 3;
	distance = 5;
	//
		
	float catch_data[16]={0};
	//1 1 1 
	//1 1 1 
	//1 1 1
	//the 9 number represent rotation matrix from coordinate 0 to coordinate 6
        catch_data[0] = PickInMat(fk_T,1,1);
	catch_data[1] = PickInMat(fk_T,1,2);
	catch_data[2] = PickInMat(fk_T,1,3);
	catch_data[4] = PickInMat(fk_T,2,1);
	catch_data[5] = PickInMat(fk_T,2,2);
	catch_data[6] = PickInMat(fk_T,2,3);
	catch_data[8] = PickInMat(fk_T,3,1);
	catch_data[9] = PickInMat(fk_T,3,2);
	catch_data[10] = PickInMat(fk_T,3,3);
	//1 1 1 0
	//1 1 1 0
	//1 1 1 0
	//0 0 0 0
	catch_data[7] = 0;//Y transmission
        catch_data[11] = -15;//Z transmission
	catch_data[12] = 0;
	catch_data[13] = 0;
	catch_data[14] = 0;
	catch_data[15] = 1;
	std_msgs::Float64 inverse_mot_o;
	std_msgs::Float64 inverse_mot;
	double tem_theta = 0;
	double tem1 = 0;
	double tem2 = 0;
	//std_msgs::Float64MultiArray output_angle;//need 6 data
	ros::Rate loop_rate(10);
	if(command == 3 && distance <= 8){
		while(ros::ok()){
			ros::spinOnce();
			//calculate fk_t
			//sensor distance plus robot offset
			//X transmission
			catch_data[3] = distance + 11;//because the base coordinate is not dependence on robot but also with the robot offset
			
			SetData_Matrix(r_t,catch_data);//combine to 4*4 matrix


			ik_T = Create_Matrix(1, 6);//setup matrix
			ok_T = Create_Matrix(1, 6);
			//DH_table setup and using
			Input_data DH_para;
			DH_para = (Input_data)malloc(sizeof(struct DH_Node));
			Init_DH(DH_para);

			
			ik_T = five_dof_ikine(DH_para, r_t);
			ok_T = five_dof_ikine(DH_para, o_T);
			Show_Matrix(ok_T);
			inverse_mot.data = PickInMat(ik_T,1,1);
			inverse_mot_o.data = PickInMat(ok_T,1,1);
			inverse_mot.data = inverse_mot.data/3.14*180;
			inverse_mot_o.data = inverse_mot_o.data/3.14*180;
			motor_theta.data = inverse_mot.data - inverse_mot_o.data;
			pub1_3.publish(motor_theta);
			pub1.publish(inverse_mot);
			pub1_2.publish(inverse_mot_o);
		
			
			inverse_mot_o.data = PickInMat(ok_T,1,2);
			inverse_mot_o.data = inverse_mot_o.data/3.14*180;
			inverse_mot.data = PickInMat(ik_T,1,2);
			inverse_mot.data = inverse_mot.data/3.14*180;
			pub2.publish(inverse_mot);
			pub2_2.publish(inverse_mot_o);
			motor_theta.data = inverse_mot.data - inverse_mot_o.data;
                        pub2_3.publish(motor_theta);
			
			inverse_mot_o.data = PickInMat(ok_T,1,3);
                        inverse_mot_o.data = inverse_mot_o.data/3.14*180;
			inverse_mot.data = PickInMat(ik_T,1,3);
			inverse_mot.data = inverse_mot.data/3.14*180;
			pub3.publish(inverse_mot);
			pub3_2.publish(inverse_mot_o);
			motor_theta.data = inverse_mot.data - inverse_mot_o.data;
                        pub3_3.publish(motor_theta);
			
			inverse_mot_o.data = PickInMat(ok_T,1,4);
                        inverse_mot_o.data = inverse_mot_o.data/3.14*180;
			inverse_mot.data = PickInMat(ik_T,1,4);
			inverse_mot.data = inverse_mot.data/3.14*180;
			pub4.publish(inverse_mot);
			pub4_2.publish(inverse_mot_o);
			motor_theta.data = inverse_mot.data - inverse_mot_o.data;
                        pub4_3.publish(motor_theta);

			inverse_mot_o.data = PickInMat(ok_T,1,5);
                        inverse_mot_o.data = inverse_mot_o.data/3.14*180;
			inverse_mot.data = PickInMat(ik_T,1,5);
			inverse_mot.data = inverse_mot.data/3.14*180;
			pub5.publish(inverse_mot);
			pub5_2.publish(inverse_mot_o);
			motor_theta.data = inverse_mot.data - inverse_mot_o.data;
                        pub5_3.publish(motor_theta);

			inverse_mot_o.data = PickInMat(ok_T,1,6);
                        inverse_mot_o.data = inverse_mot_o.data/3.14*180;
			inverse_mot.data = PickInMat(ik_T,1,6);
			inverse_mot.data = inverse_mot.data/3.14*180;
			pub6.publish(inverse_mot);
			pub6_2.publish(inverse_mot_o);
			motor_theta.data = inverse_mot.data - inverse_mot_o.data;
                        pub6_3.publish(motor_theta);

			loop_rate.sleep();
		}
	}
	return 0;
}
