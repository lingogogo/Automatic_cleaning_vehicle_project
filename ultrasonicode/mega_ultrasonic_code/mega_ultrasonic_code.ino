/*
  Ping to Sonar ROS
  The circuit:
 - +V connection of the PING))) attached to +5V
 - GND connection of the PING))) attached to ground
 - SIG connection of the PING))) attached to digital pin 7

  created 3 Nov 2008
  by David A. Mellis
  modified 30 Aug 2011
  by Tom Igoe
  ported to ROS July 31,2018
  by Christopher Coballes 
  This example code is in the public domain.
  http://www.arduino.cc/en/Tutorial/Ping
*/

 #include <ros.h>
 #include <ros/time.h>
 #include <sensor_msgs/Range.h>
 
 ros::NodeHandle  nh;
 sensor_msgs::Range sonar_msg;
 ros::Publisher pub_sonar( "rangeSonar", &sonar_msg);
 float sensoReading = 0;
   
// this constant won't change. It's the pin number of the sensor's output:
const int trigPin = 7;
const int echoPin= 5;

char frameid[] ="/sonar_ranger";
void setup() {
  // initialize serial communication:
//  Serial.begin(9600);
    nh.initNode();
    nh.advertise(pub_sonar);
    pinMode(trigPin,OUTPUT);
    pinMode(echoPin,INPUT);
    sonar_msg.radiation_type = sensor_msgs::Range::ULTRASOUND;
    sonar_msg.header.frame_id =  frameid;
    sonar_msg.field_of_view = (10.0/180.0) * 3.14;
    sonar_msg.min_range = 0.0;
    sonar_msg.max_range = 60;
    
}
int duration;
unsigned long publisher_timer;
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
   //sensoReading = getDistance;
   sonar_msg.range = sensoReading;
   //Serial.println(sensoReading);
   sonar_msg.header.stamp = nh.now();
   pub_sonar.publish(&sonar_msg);
   publisher_timer = millis(); //publish once a second
   
   }
   
  nh.spinOnce();
    
}
