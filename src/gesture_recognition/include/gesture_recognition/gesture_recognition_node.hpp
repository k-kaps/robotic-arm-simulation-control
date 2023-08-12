#ifndef GESTURE_RECOGNITION_NODE_HPP
#define GESTURE_RECOGNIITON_NODE_HPP

#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/image.hpp"

class GestureRecognitionNode : rclcpp::Node {

public : 
	GestureRecognitionNode();

private : 
	void gestureCallback(const sensor_msgs::msg::Image::SharedPtr image_msg);
};

#endif //GESTURE_RECOGNITION_NODE_HPP
