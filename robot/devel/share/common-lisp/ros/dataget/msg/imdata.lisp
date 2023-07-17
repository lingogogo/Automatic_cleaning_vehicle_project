; Auto-generated. Do not edit!


(cl:in-package dataget-msg)


;//! \htmlinclude imdata.msg.html

(cl:defclass <imdata> (roslisp-msg-protocol:ros-message)
  ((frameid
    :reader frameid
    :initarg :frameid
    :type cl:integer
    :initform 0)
   (classid
    :reader classid
    :initarg :classid
    :type cl:integer
    :initform 0)
   (x
    :reader x
    :initarg :x
    :type cl:float
    :initform 0.0)
   (y
    :reader y
    :initarg :y
    :type cl:float
    :initform 0.0)
   (width
    :reader width
    :initarg :width
    :type cl:float
    :initform 0.0)
   (height
    :reader height
    :initarg :height
    :type cl:float
    :initform 0.0))
)

(cl:defclass imdata (<imdata>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <imdata>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'imdata)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name dataget-msg:<imdata> is deprecated: use dataget-msg:imdata instead.")))

(cl:ensure-generic-function 'frameid-val :lambda-list '(m))
(cl:defmethod frameid-val ((m <imdata>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dataget-msg:frameid-val is deprecated.  Use dataget-msg:frameid instead.")
  (frameid m))

(cl:ensure-generic-function 'classid-val :lambda-list '(m))
(cl:defmethod classid-val ((m <imdata>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dataget-msg:classid-val is deprecated.  Use dataget-msg:classid instead.")
  (classid m))

(cl:ensure-generic-function 'x-val :lambda-list '(m))
(cl:defmethod x-val ((m <imdata>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dataget-msg:x-val is deprecated.  Use dataget-msg:x instead.")
  (x m))

(cl:ensure-generic-function 'y-val :lambda-list '(m))
(cl:defmethod y-val ((m <imdata>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dataget-msg:y-val is deprecated.  Use dataget-msg:y instead.")
  (y m))

(cl:ensure-generic-function 'width-val :lambda-list '(m))
(cl:defmethod width-val ((m <imdata>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dataget-msg:width-val is deprecated.  Use dataget-msg:width instead.")
  (width m))

(cl:ensure-generic-function 'height-val :lambda-list '(m))
(cl:defmethod height-val ((m <imdata>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dataget-msg:height-val is deprecated.  Use dataget-msg:height instead.")
  (height m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <imdata>) ostream)
  "Serializes a message object of type '<imdata>"
  (cl:let* ((signed (cl:slot-value msg 'frameid)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'classid)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'x))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'y))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'width))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'height))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <imdata>) istream)
  "Deserializes a message object of type '<imdata>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'frameid) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'classid) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'x) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'y) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'width) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'height) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<imdata>)))
  "Returns string type for a message object of type '<imdata>"
  "dataget/imdata")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'imdata)))
  "Returns string type for a message object of type 'imdata"
  "dataget/imdata")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<imdata>)))
  "Returns md5sum for a message object of type '<imdata>"
  "28c7cb1f506871314105166747b2c650")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'imdata)))
  "Returns md5sum for a message object of type 'imdata"
  "28c7cb1f506871314105166747b2c650")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<imdata>)))
  "Returns full string definition for message of type '<imdata>"
  (cl:format cl:nil "int32 frameid~%int32 classid~%float32 x~%float32 y~%float32 width~%float32 height~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'imdata)))
  "Returns full string definition for message of type 'imdata"
  (cl:format cl:nil "int32 frameid~%int32 classid~%float32 x~%float32 y~%float32 width~%float32 height~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <imdata>))
  (cl:+ 0
     4
     4
     4
     4
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <imdata>))
  "Converts a ROS message object to a list"
  (cl:list 'imdata
    (cl:cons ':frameid (frameid msg))
    (cl:cons ':classid (classid msg))
    (cl:cons ':x (x msg))
    (cl:cons ':y (y msg))
    (cl:cons ':width (width msg))
    (cl:cons ':height (height msg))
))
