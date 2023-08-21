#include "gesture_recognition/gesture_recognition.hpp"

GestureRecognition::GestureRecognition(){
    // Initializing the gesture variable
    gesture = "";
}

std::string GestureRecognition::findGesture(sensor_msgs::msg::Image::SharedPtr image_msg){
    cv::Mat img;
    try{
        img = cv_bridge::toCvCopy(image_msg, sensor_msgs::image_encodings::BGR8)->image;
    }
    catch (cv_bridge::Exception& exception){
        RCLCPP_ERROR(rclcpp::get_logger("gesture_recognition"), "cv_bridge exception : %s", exception.what());
    }
    // TODO : add gesture recognition logic
    gesture = "some gesture";
    return gesture;
}
