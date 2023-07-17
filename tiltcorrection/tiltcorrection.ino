#include <Wire.h>
#include <HMC5883L.h>
#include <ADXL345.h>

#include <ros.h>

#include <std_msgs/Float64.h>
#include <ITG3200.h>

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
ros::NodeHandle nh;

//For the compass message
std_msgs::Float64 compass_yaw_data;
ros::Publisher pub_yaw1("/compass_yaw_Data",&compass_yaw_data);

//For the gyro message
std_msgs::Float64 gyro_yaw_data;
ros::Publisher  pub_yaw2("/gyro_yaw_Data",&gyro_yaw_data);

void setup(){
  nh.initNode();
  
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

  time = millis();
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
  // Set declination angle on your location and fix heading
  // You can find your declination on: http://magnetic-declination.com/
  // (+) Positive or (-) for negative
  // 台北地區的磁偏角是 4'4 WEST (negative)
  // Formula: (deg + (min / 60.0)) / (180 / M_PI);
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
  nh.spinOnce();
  delay(10);
}
