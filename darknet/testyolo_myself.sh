./darknet detector demo cfg/myselfdata.data cfg/yolov1/yolov3-tiny_one_class.cfg yolov3-tiny_last.weights 'nvarguscamerasrc ! video/x-raw(memory:NVMM), width=(int)1280, height=(int)720,format=(string)NV12, framerate=(fraction)10/1 ! nvvidconv flip-method=2 ! video/x-raw, format=(string)BGRx ! videoconvert ! video/x-raw, format=(string)BGR ! appsink' -out result.json  -ext_output 



