#include "gesture_recognition/image_subscriber_node.hpp"

ImageSubscriberNode::ImageSubscriberNode() : Node("image_subscriber_node") {
	image_subscriber = this->create_subscription<sensor_msgs::msg::Image>("image_topic", 10, std::bind(&ImageSubscriberNode::imageProcessing, this, std::placeholders::_1));
}

void ImageSubscriberNode::imageProcessing(sensor_msgs::msg::Image::SharedPtr image_msg)const {
	if (image_msg->data.empty() == true){
		RCLCPP_ERROR(this->get_logger(), "ERROR : No data recieved, image data empty");
	}
	else{
		RCLCPP_INFO(this->get_logger(), "SUCCESS : Image recieved, sent for processing");
	}
	rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr image_subscriber;
}

int main(int argc, char * argv[]){

	rclcpp::init(argc, argv);
	rclcpp::spin(std::make_shared<ImageSubscriberNode>());
	rclcpp::shutdown();
	return 0;
}