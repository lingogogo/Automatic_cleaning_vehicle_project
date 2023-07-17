#include <Wire.h>
#include <HMC5883L.h>
#include <ADXL345.h>
#include <ros.h>
#include <std_msgs/Float64.h>
#include <ITG3200.h>
#include <ros/time.h>
#include <sensor_msgs/Range.h>
#include <Servo.h>

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
int command = 0;

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

void callback_command(const std_msgs::Int32& msg7)
{
  command = msg7.data;
}

sensor_msgs::Range sonar_msg;
std_msgs::Float64 sonar_distance;
ros::Publisher pub_sonar( "rangeSonar", &sonar_msg);
//take the data to check object distance
ros::Publisher pub_distance( "distance", &sonar_distance);

float sensoReading = 0;

// this constant won't change. It's the pin number of the sensor's output:
const int trigPin = 7;
const int echoPin= 5;

char frameid[] ="/sonar_ranger";
int duration;
unsigned long publisher_timer;
//=============================================
ITG3200 gyro = ITG3200();
HMC5883L compass;
ADXL345 accelerometer;

unsigned long time, looptime;
float  gx,gy,gz;
float  gx_rate, gy_rate, gz_rate;
float anglegx=0.0, anglegy=0.0, anglegz=0.0;
float heading1;
float heading2;
float goffsetX, goffsetY, goffsetZ;

//commutecation dot


//For the compass message
std_msgs::Float64 compass_yaw_data;
ros::Publisher pub_yaw1("/compass_yaw_Data",&compass_yaw_data);

//For the gyro message
std_msgs::Float64 gyro_yaw_data;
ros::Publisher  pub_yaw2("/gyro_yaw_Data",&gyro_yaw_data);

void setup(){
  ros::NodeHandle n;
  n.initNode();
  ros::Subscriber<std_msgs::Float64> sub_1("motor_theta1",&callback_theta1);
  ros::Subscriber<std_msgs::Float64> sub_2("motor_theta2",&callback_theta2);
  ros::Subscriber<std_msgs::Float64> sub_3("motor_theta3",&callback_theta3);
  ros::Subscriber<std_msgs::Float64> sub_4("motor_theta4",&callback_theta4);
  ros::Subscriber<std_msgs::Float64> sub_5("motor_theta5",&callback_theta5);
  ros::Subscriber<std_msgs::Float64> sub_6("motor_theta6",&callback_theta6);
  ros::Subscriber<std_msgs::Float64> sub_6("motor_theta6",&callback_theta6);
  ros::Subscriber<std_msgs::Int32> sub_7("command_motor",&callback_command);

  
  servo1.attach(2);
  servo2_1.attach(3);
  servo2_2.attach(4);
  servo3.attach(5);
  servo4.attach(6);
  servo5.attach(7);
  servo6.attach(8);
  claw.attach(9);
  
  
  // initialize serial communication:
  //  Serial.begin(9600);
  //===============================
  nh.advertise(pub_sonar);
  nh.advertise(pub_distance);

  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  sonar_msg.radiation_type = sensor_msgs::Range::ULTRASOUND;
  sonar_msg.header.frame_id =  frameid;
  sonar_msg.field_of_view = (10.0/180.0) * 3.14;
  sonar_msg.min_range = 0.0;
  sonar_msg.max_range = 10.0;
  //================================
  nh.advertise(pub_yaw1);
  nh.advertise(pub_yaw2);
  //===================
  //====================
  //gyro offset
  for (int i = 0; i <= 200; i++) {
    gyro.readGyro(&gx,&gy,&gz); 
    if (i == 0) {
      goffsetX = gx;
      goffsetY = gy;
      goffsetZ = gz;
    }
    if (i > 1) {
      goffsetX = (gx + goffsetX) / 2;
      goffsetY = (gy + goffsetY) / 2;
      goffsetZ = (gz + goffsetZ) / 2;
    }
  }
  //Serial.begin(9600);
  //lcd.init();                     
  //lcd.backlight(); 
  //lcd.clear();
  if (!accelerometer.begin()){delay(500);}         // 初始化 ADXL345
  accelerometer.setRange(ADXL345_RANGE_2G);
  while (!compass.begin()) { delay(500);}            // 初始化電子羅盤 HMC5883L
  compass.setRange(HMC5883L_RANGE_1_3GA);            //設定測量範圍
  compass.setMeasurementMode(HMC5883L_CONTINOUS);    // 設定測量模式
  compass.setDataRate(HMC5883L_DATARATE_15HZ);       // 設定資料傳輸速率
  compass.setSamples(HMC5883L_SAMPLES_8);           //設樣本平均數的組數
  compass.setOffset(20, 26);   //設定檢量線的數值
  //Serial.println(accelerometer.getRange());

  gyro.init(ITG3200_ADDR_AD0_LOW); 
  //Serial.print("zero Calibrating...");
  gyro.zeroCalibrate(2500, 2);
  //Serial.println("done.");
}
//無傾斜補償
float noTiltCompensate(Vector mag){
  float heading = atan2(mag.YAxis, mag.XAxis);
  return heading;
}
 
// 傾斜補償
float tiltCompensate(Vector mag, Vector normAccel){
  float roll;
  float pitch;
  roll = asin(normAccel.YAxis);
  pitch = asin(-normAccel.XAxis);
  if (roll > 0.78 || roll < -0.78 || pitch > 0.78 || pitch < -0.78){return -1000; }
  float cosRoll = cos(roll);
  float sinRoll = sin(roll);  
  float cosPitch = cos(pitch);
  float sinPitch = sin(pitch);
  float Xh = mag.XAxis * cosPitch + mag.ZAxis * sinPitch;
  float Yh = mag.XAxis * sinRoll * sinPitch + mag.YAxis * cosRoll - mag.ZAxis * sinRoll * cosPitch;
  float heading = atan2(Yh, Xh);
  return heading;
}
//角度校正
float correctAngle(float heading){
  if (heading < 0) { heading += 2 * PI; }
  if (heading > 2 * PI) { heading -= 2 * PI; }
  return heading;
}


void loop() {
  sensoReading = 0 ;
    
  // establish variables for duration of the ping, and the distance result
  // in inches and centimeters:


  if ((millis() - publisher_timer)> 50 ) 
   {
     digitalWrite(trigPin,LOW);
     delayMicroseconds(2);
     digitalWrite(trigPin,HIGH);
     delayMicroseconds(10);
    
     duration = pulseIn(echoPin, HIGH);
     sensoReading = duration *0.342/2000*100;
     sonar_distance.data = sensoReading;
     //sensoReading = getDistance;
     sonar_msg.range = sensoReading;
     //Serial.println(sensoReading);
     sonar_msg.header.stamp = nh.now();
     pub_sonar.publish(&sonar_msg);
     pub_distance.publish(&sonar_distance);
     publisher_timer = millis(); //publish once a second
 
   }
  // if the robot stop, the robot will begin to control robotic arm
  if(command == 6){
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


   
  /*time = millis();
  gyro.readGyro(&gx,&gy,&gz); 
  looptime = millis() - time;
  gx_rate = (gx-goffsetX) / 14.375;
  gy_rate = (gy-goffsetY) / 14.375;
  gz_rate = (gz-goffsetZ) / 14.375;
  delay(100);
  //filter out the noizy
  if(gz_rate < 0.03 && gz_rate >0){
    gz_rate = 0;
  }
  if(gz_rate >= -0.03 && gz_rate < 0){
    gz_rate = 0;
  }
  anglegx = anglegx + (gx_rate * looptime);
  anglegy = anglegy + (gx_rate * looptime);
  anglegz = anglegz + (gz_rate * looptime);
  
  // 讀取向量  
  Vector mag = compass.readNormalize();
  Vector acc = accelerometer.readScaled();

  // Calculate headings
  heading1 = noTiltCompensate(mag);
  heading2 = tiltCompensate(mag, acc);
  if (heading2 == -1000){
    heading2 = heading1;
  }
 
  float declinationAngle = (-4 -(11/ 60.0)) / (180 / M_PI);
  heading1 += declinationAngle;
  heading2 += declinationAngle;
  // Correct for heading < 0deg and heading > 360deg
  heading1 = correctAngle(heading1);
  
      
  heading2 = correctAngle(heading2);
  // Convert to degrees
  heading1 = heading1 * 180/M_PI; 
  heading2 = heading2 * 180/M_PI; 
  //Serial.print(anglegz);
  //Serial.println(heading1);
  //Serial.print(":");
  //Serial.println(heading2);
  compass_yaw_data.data = heading1;
  gyro_yaw_data.data = anglegz;
  
  pub_yaw1.publish(&compass_yaw_data);
  pub_yaw2.publish(&gyro_yaw_data);
  //start the 
  nh.spinOnce();
  delay(10);*/
}
