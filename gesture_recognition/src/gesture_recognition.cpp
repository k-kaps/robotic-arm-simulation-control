#include "gesture_recognition/gesture_recognition.hpp"

GestureRecognition::GestureRecognition(){
    gesture = "";
}

std::string GestureRecognition::findGesture(sensor_msgs::msg::Image::SharedPtr image_msg){
    // TODO : find the gesture from the image
    gesture = "some gesture";
    return gesture;
}