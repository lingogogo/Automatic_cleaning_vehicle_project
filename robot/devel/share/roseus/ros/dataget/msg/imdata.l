;; Auto-generated. Do not edit!


(when (boundp 'dataget::imdata)
  (if (not (find-package "DATAGET"))
    (make-package "DATAGET"))
  (shadow 'imdata (find-package "DATAGET")))
(unless (find-package "DATAGET::IMDATA")
  (make-package "DATAGET::IMDATA"))

(in-package "ROS")
;;//! \htmlinclude imdata.msg.html


(defclass dataget::imdata
  :super ros::object
  :slots (_frameid _classid _x _y _width _height ))

(defmethod dataget::imdata
  (:init
   (&key
    ((:frameid __frameid) 0)
    ((:classid __classid) 0)
    ((:x __x) 0.0)
    ((:y __y) 0.0)
    ((:width __width) 0.0)
    ((:height __height) 0.0)
    )
   (send-super :init)
   (setq _frameid (round __frameid))
   (setq _classid (round __classid))
   (setq _x (float __x))
   (setq _y (float __y))
   (setq _width (float __width))
   (setq _height (float __height))
   self)
  (:frameid
   (&optional __frameid)
   (if __frameid (setq _frameid __frameid)) _frameid)
  (:classid
   (&optional __classid)
   (if __classid (setq _classid __classid)) _classid)
  (:x
   (&optional __x)
   (if __x (setq _x __x)) _x)
  (:y
   (&optional __y)
   (if __y (setq _y __y)) _y)
  (:width
   (&optional __width)
   (if __width (setq _width __width)) _width)
  (:height
   (&optional __height)
   (if __height (setq _height __height)) _height)
  (:serialization-length
   ()
   (+
    ;; int32 _frameid
    4
    ;; int32 _classid
    4
    ;; float32 _x
    4
    ;; float32 _y
    4
    ;; float32 _width
    4
    ;; float32 _height
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _frameid
       (write-long _frameid s)
     ;; int32 _classid
       (write-long _classid s)
     ;; float32 _x
       (sys::poke _x (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _y
       (sys::poke _y (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _width
       (sys::poke _width (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _height
       (sys::poke _height (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _frameid
     (setq _frameid (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _classid
     (setq _classid (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; float32 _x
     (setq _x (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _y
     (setq _y (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _width
     (setq _width (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _height
     (setq _height (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get dataget::imdata :md5sum-) "28c7cb1f506871314105166747b2c650")
(setf (get dataget::imdata :datatype-) "dataget/imdata")
(setf (get dataget::imdata :definition-)
      "int32 frameid
int32 classid
float32 x
float32 y
float32 width
float32 height

")



(provide :dataget/imdata "28c7cb1f506871314105166747b2c650")


