#include gesture_recognition_node_hpp

GestureRecognitionNode:GestureRecognitionNode() : Node("gesture_recognition_node") {
	auto gesture_subscriber = create_subscription<sensor_msgs::msg::Image>("image_topic", 10, gestureCallback);
	rclcpp::spin(this);
	rclcpp::shutdown()
};

GestureRecognitionNode:GestureCallback(std_msgs::msg::Image::SharedPtr image_msg){
	std::string gesture = "some gesture";
	RCLCPP_INFO(get_logger(), "Recognized Gesture : %s",gesture.c_str());
}

