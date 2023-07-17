// Auto-generated. Do not edit!

// (in-package dataget.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class imdata {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.frameid = null;
      this.classid = null;
      this.x = null;
      this.y = null;
      this.width = null;
      this.height = null;
    }
    else {
      if (initObj.hasOwnProperty('frameid')) {
        this.frameid = initObj.frameid
      }
      else {
        this.frameid = 0;
      }
      if (initObj.hasOwnProperty('classid')) {
        this.classid = initObj.classid
      }
      else {
        this.classid = 0;
      }
      if (initObj.hasOwnProperty('x')) {
        this.x = initObj.x
      }
      else {
        this.x = 0.0;
      }
      if (initObj.hasOwnProperty('y')) {
        this.y = initObj.y
      }
      else {
        this.y = 0.0;
      }
      if (initObj.hasOwnProperty('width')) {
        this.width = initObj.width
      }
      else {
        this.width = 0.0;
      }
      if (initObj.hasOwnProperty('height')) {
        this.height = initObj.height
      }
      else {
        this.height = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type imdata
    // Serialize message field [frameid]
    bufferOffset = _serializer.int32(obj.frameid, buffer, bufferOffset);
    // Serialize message field [classid]
    bufferOffset = _serializer.int32(obj.classid, buffer, bufferOffset);
    // Serialize message field [x]
    bufferOffset = _serializer.float32(obj.x, buffer, bufferOffset);
    // Serialize message field [y]
    bufferOffset = _serializer.float32(obj.y, buffer, bufferOffset);
    // Serialize message field [width]
    bufferOffset = _serializer.float32(obj.width, buffer, bufferOffset);
    // Serialize message field [height]
    bufferOffset = _serializer.float32(obj.height, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type imdata
    let len;
    let data = new imdata(null);
    // Deserialize message field [frameid]
    data.frameid = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [classid]
    data.classid = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [x]
    data.x = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [y]
    data.y = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [width]
    data.width = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [height]
    data.height = _deserializer.float32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 24;
  }

  static datatype() {
    // Returns string type for a message object
    return 'dataget/imdata';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '28c7cb1f506871314105166747b2c650';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int32 frameid
    int32 classid
    float32 x
    float32 y
    float32 width
    float32 height
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new imdata(null);
    if (msg.frameid !== undefined) {
      resolved.frameid = msg.frameid;
    }
    else {
      resolved.frameid = 0
    }

    if (msg.classid !== undefined) {
      resolved.classid = msg.classid;
    }
    else {
      resolved.classid = 0
    }

    if (msg.x !== undefined) {
      resolved.x = msg.x;
    }
    else {
      resolved.x = 0.0
    }

    if (msg.y !== undefined) {
      resolved.y = msg.y;
    }
    else {
      resolved.y = 0.0
    }

    if (msg.width !== undefined) {
      resolved.width = msg.width;
    }
    else {
      resolved.width = 0.0
    }

    if (msg.height !== undefined) {
      resolved.height = msg.height;
    }
    else {
      resolved.height = 0.0
    }

    return resolved;
    }
};

module.exports = imdata;
