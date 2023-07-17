#include <ros.h>
#include <std_msgs/Float64.h>
#include <Servo.h>

Servo servo1;
Servo servo2_1;
Servo servo2_2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;
Servo claw;

float motor1 = 0,motor2 = 0,motor3 = 0,motor4 = 0,motor5 = 0,motor6 = 0;
float motor_claw = 0;
void callback_theta1(const std_msgs::Float64& msg1)
{
  motor1 = msg1.data;
  motor1 = motor1/PI*180;
}
void callback_theta2(const std_msgs::Float64& msg2)
{
  motor2= msg2.data;

  motor2= motor2/PI*180;

}

void callback_theta3(const std_msgs::Float64& msg3)
{
  motor3 = msg3.data;
  motor3 = motor3/PI*180;

}
void callback_theta4(const std_msgs::Float64& msg4)
{
  motor4 = msg4.data;
  motor4 = motor4/PI*180;
}

void callback_theta5(const std_msgs::Float64& msg5)
{
  motor5 = msg5.data;
  motor5 = motor5/PI*180;
}

void callback_theta6(const std_msgs::Float64& msg6)
{
  motor6 = msg6.data;
  motor6 = motor6/PI*180;
}



void setup() {
  ros::NodeHandle n;
  n.initNode();
  ros::Subscriber<std_msgs::Float64> sub_1("motor_theta1",&callback_theta1);
  ros::Subscriber<std_msgs::Float64> sub_2("motor_theta2",&callback_theta2);
  ros::Subscriber<std_msgs::Float64> sub_3("motor_theta3",&callback_theta3);
  ros::Subscriber<std_msgs::Float64> sub_4("motor_theta4",&callback_theta4);
  ros::Subscriber<std_msgs::Float64> sub_5("motor_theta5",&callback_theta5);
  ros::Subscriber<std_msgs::Float64> sub_6("motor_theta6",&callback_theta6);
  
  servo1.attach(2);
  servo2_1.attach(3);
  servo2_2.attach(4);
  servo3.attach(5);
  servo4.attach(6);
  servo5.attach(7);
  servo6.attach(8);
  claw.attach(9);
}

void loop() {
  servo1.write(motor1);
  servo2_1.write(motor2);
  servo2_2.write(motor2);
  servo3.write(motor3);
  servo4.write(motor4);
  servo5.write(motor5);
  servo6.write(motor6);
  
  delay(10000);
  claw.write(30);//test the value

}
