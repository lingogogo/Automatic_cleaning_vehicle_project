#!/usr/bin/python2.7
import rospy
import roslib
import json
from std_msgs.msg import ColorRGBA
#note dataget is the directory in the robotworkspace ,additionally, it has to append .msg 
from dataget.msg import imdata



##################
#global variable
frame_id = 0
class_id = 0
x = 0
y = 0
width = 0
height = 0
###################

pub1 = rospy.Publisher('data_from_yolov3' , imdata , queue_size = 10)
pub2 = rospy.Publisher('data_from_yolov3_all' , ColorRGBA , queue_size = 10)

def talker():
	
	rospy.init_node('get_data_yolo',anonymous = True)
	
    	
	rate = rospy.Rate(10)
	while not rospy.is_shutdown():
		with open('/home/gordonlin/darknet/result.json', 'r+') as f:
			#json.loads(s.replace())
			distros_dict_test = json.load(f)
			print("open success")
		get_data(distros_dict_test)
		#del_data(distros_dict_test)
		rate.sleep()
		#end
		

def get_data(distros_dict):
    json_to_variable = []
    global frame_id, class_id,x,y,width,height
    # For every frame.
    for distro in distros_dict:
        filename = distro['filename']
        if len(distro['objects']) != 0:
            # For every detection.
            for obj in range(len(distro['objects'])):
                # Get values.
                frame_id = distro['frame_id']
                class_id = distro['objects'][obj]["class_id"]
                x = distro['objects'][obj]["relative_coordinates"]["center_x"]
                y = distro['objects'][obj]["relative_coordinates"]["center_y"]
                width = distro['objects'][obj]["relative_coordinates"]["width"]
                height = distro['objects'][obj]["relative_coordinates"]["height"]
                confidence = distro['objects'][obj]["confidence"]
		# width640
		x = x*1280
		# height480
		y = y*720
		# detect_image real height and width
		width =  width * 1280
		height = height * 720
		# deal with the data
                # And print them.
		#######################
		# publish data
		pub1.publish(frame_id,class_id,x,y,width,height)
		pub2.publish(x,y,width,height)
		#######################
		
                print(frame_id, class_id, x, y, width, height, confidence)

def del_data(del_dict):


    # For every frame.
    for distro in del_dict:
        filename = distro['filename']
        if len(distro['objects']) != 0:
            # For every detection.
            for obj in range(len(distro['objects'])):
                # Get values.
		distro.pop('frame_id',None)
		distro.pop('objects',None)
	
               

                #json_to_variable.append([frame_id, class_id, x, y, width, height, confidence])

 # If you need to use json_to_variable here, move "json_to_variable = []" inside "for distro in distros_dict:"
 # Add your code here.
 # Or return json_to_variable to use it outside this function.


if __name__ == '__main__' :
	try:
		talker()
	except rospy.ROSInterruptException:
		pass
#over

