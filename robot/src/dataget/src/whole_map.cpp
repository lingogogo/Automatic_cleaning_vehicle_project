#include <ros/ros.h>
#include <cmath>
#include <sensor_msgs/NavSatFix.h>
#include <std_msgs/Float64.h>
//#include <dataget/Xymsg.h>
#include <iostream>
using namespace std;

int times_spot = 1;
//dataget::Xymsg msg;
sensor_msgs::NavSatFix current_gps;
//std_msgs::Float64 current_gps;
double check_leng = 0;
double prov_vector = 0;
double lat_spot_v = 0;
double longi_spot_v = 0;
int t = 0;
int k = 0;
int coun_times = 0;
int F_num = 0;
int checkk = 0;
void gps_cb(const sensor_msgs::NavSatFix::ConstPtr& msg)
{
        current_gps = *msg;
        //printf("%f %f %f\n",current_gps.latitude,current_gps.longitude,current_gps.altitude);
}

int judge_h_l(int a){
	int  b = a/4;
	int che = a - b*4; 
	switch (che)
	{
		case 1:
		case 2:
			return 1 ;
		case 3:
		case 4:
			return 2 ;
	}

}




int main(int argc, char** argv)
{
	ros::init(argc,argv,"whole_Map");
	ros::NodeHandle n;
	// the mopping area
	double W_coor1[2] = {0};
	double W_coor2[2] = {0};
	double W_coor3[2] = {0};
	double W_coor4[2] = {0};
	/*	
	for (int i=0;i<4;i++){
		cout<<"The origin"<<endl;
		cin>>W_coor1[0]>>W_coor1[1];
		cout<<"The y-axis"<<endl;
		cin>>W_coor2[0]>>W_coor2[1];
		cout<<"The x-axis"<<endl;
		cin>>W_coor3[0]>>W_coor3[1];
		cout<<"The xy-axis"<<endl;
  		cin>>W_coor4[0]>>W_coor4[1];
	}
	*/
	W_coor1[0] = 0;W_coor1[1] = 0;    		        
	W_coor2[0] = 0;W_coor2[1] = 1;
	W_coor3[0] = -1;W_coor3[1] = 0;
	W_coor4[0] = -1;W_coor4[1] = 1;
		
	//the length may not a only x or y coordinate, so i need to check its theta 
	//double x_leng=sqrt(pow(W_coor3[0]-W_coor1[0],2)+pow(W_coor3[1]-W_coor1[1],2));
	//double y_leng=sqrt(pow(W_coor4[0]-W_coor2[0],2)+pow(W_coor4[1]-W_coor2[1],2));
	//theta check
	
	/*double theta1 = acos((W_coor3[0] - W_coor1[0])/x_leng);
	double theta2 = acos((W_coor2[0] - W_coor1[0])/y_leng);
	x_leng = x_leng*cos(theta1);
	y_leng = y_leng*cos(theta2);
	cout << x_leng << " " << y_leng << endl ;
	*/

	double x_interval = (W_coor3[0] - W_coor1[0])/9;
	double y_interval = (W_coor3[1] - W_coor1[1])/9;	
	double lowspot[2][10] = {0};
	double highspot[2][10] = {0};
	//the specific spot for our moving vector
	for (int i=0;i<10;i++){
		
		highspot[0][i]=W_coor2[0]+x_interval*(i);
		lowspot[0][i]=W_coor1[0]+x_interval*(i);
		highspot[1][i]=W_coor2[1]+y_interval*(i);
		lowspot[1][i]=W_coor1[1]+y_interval*(i);
		cout << "x interval = " << x_interval << " y interval = " << y_interval << endl ;
		cout << i <<endl <<" lowspot  "<<setprecision(20)<<lowspot[0][i]<<" "<<setprecision(20)<<lowspot[1][i]<<endl;
		cout<<"highspot "<<highspot[0][i]<<" " << highspot[1][i]<<endl;


	}
	

	

	
	//The robot local spot
	ros::Subscriber gps_sub = n.subscribe<sensor_msgs::NavSatFix>("fix",100,gps_cb);
//	ros::Publisher GPS_vector = n.advertise<dataget::Xymsg>("GPS_vector_topic",1000);
	ros::Publisher GPS_vector_x = n.advertise<std_msgs::Float64>("GPS_vector_X",1000);
	ros::Publisher GPS_vector_y = n.advertise<std_msgs::Float64>("GPS_vector_Y",1000);
	ros::Publisher vector_spot_longi = n.advertise<std_msgs::Float64>("spot_vector_x",1000);
	ros::Publisher vector_spot_lat = n.advertise<std_msgs::Float64>("spot_vector_y",1000);
	
        std_msgs::Float64 msg1;
        std_msgs::Float64 msg2;
	std_msgs::Float64 take_vector_x;
	std_msgs::Float64 take_vector_y;

	//sensor_msgs::NavSatFix msg1;
	//sensor_msgs::NavSatFix msg2;

	

	ros::Rate rate(15);
	
	while(ros::ok())
        {
                ros::spinOnce();
		coun_times = times_spot/4;
		F_num = times_spot - coun_times*4;
	
		switch(F_num){
                	case 1:
                        	lat_spot_v = highspot[1][k] - lowspot[1][t];
                       		longi_spot_v = highspot[0][k] - lowspot[0][t];
				break;
                	case 2:
                        	lat_spot_v = highspot[1][k] - highspot[1][t];
                        	longi_spot_v = highspot[0][k] - highspot[0][t];
				break;
                	case 3:
                        	lat_spot_v = lowspot[1][k] - highspot[1][t];
                        	longi_spot_v = lowspot[0][k] - highspot[0][t];
				break;
                	case 4:
                        	lat_spot_v = lowspot[1][k] - lowspot[1][t];
                        	longi_spot_v = lowspot[0][k] - lowspot[0][t];
				break;
        	}
		//cout<<"t "<<t<<endl;
		//cout<<"k "<<k<<endl;
	        cout <<"F_num " << F_num<<endl;
		cout <<"count_times " << coun_times<<endl;
		cout <<"spot_vector_x "<< longi_spot_v << endl;
		cout <<"spot_vector_y "<< lat_spot_v << endl;
		//cout <<highspot[0][k]<<" " << lowspot[0][t]<<endl;
		take_vector_x.data = longi_spot_v;
        	take_vector_y.data = lat_spot_v;

        	vector_spot_longi.publish(take_vector_x);
        	vector_spot_lat.publish(take_vector_y);


		
		//sensor_msgs::NavSatFix lat;
		//sensor_msgs::NavSatFix longi;
		//notice:std_msgs allocater<void> sensor_msgs::NavSatFix::latitude_type

		//navsatfix member can be use double in c++, but the sensor_msgs::navsatfix cannot 
		//be double 
		double lat = current_gps.latitude;
		double longi = current_gps.longitude;
		//==========
		/*lat = 3;
		longi =1;*/
		//==========

		//The direction to the spot from robot.			
		int che_i = judge_h_l(times_spot);
		switch(che_i)
		{
			case 1:
				{
				double hlat_m = highspot[1][k]-lat;
                		double hlongi_m = highspot[0][k]-longi;
				//check
				cout <<"y = " <<highspot[1][k] << "  "<<"x = " << highspot[0][k]<< endl;
				//======================
				//msg.y = hlat_m;
				//msg.x = hlongi_m;
				msg1.data = hlongi_m;
				msg2.data = hlat_m;
				
				//GPS_vector.publish(msg);
				GPS_vector_x.publish(msg1);
				GPS_vector_y.publish(msg2);
				check_leng = sqrt(pow(abs(hlat_m),2)+pow(abs(hlongi_m),2));
				cout << "robot now location_x = " << hlongi_m << endl;
				cout << "robot now location_y = " << hlat_m << endl;
				cout << "check length = " << check_leng << endl;
				if (check_leng < 0.0000001)
					{	
						times_spot++;
						checkk = F_num%2;
						if(checkk == 1){
							k++;
						}else{
							t++;
						}
					}
				}
				break;
			case 2:
				{
				double llongi_m = lowspot[0][k]-longi;
                		double llat_m = lowspot[1][k]-lat;
				//msg.y = llat_m;
				//msg.x = llongi_m;	
				//GPS_vector.publish(msg);
				GPS_vector_x.publish(msg1);
                                GPS_vector_y.publish(msg2);
				check_leng = sqrt(pow(abs(llat_m),2)+pow(abs(llongi_m),2));
				cout << "robot now location_x = " << llongi_m << endl;
                                cout << "robot now location_y = " << llat_m << endl;

				cout << "check length = " << check_leng << endl;

				if (check_leng < 0.0000001)
                			{
						times_spot++;
                                                checkk = F_num%2;
                                                if(checkk == 1){
                                                        k++;
                                                }else{
                                                        t++;
                                                }

                			}
				}
				break;
		}

                rate.sleep();
        }
}

		
	





