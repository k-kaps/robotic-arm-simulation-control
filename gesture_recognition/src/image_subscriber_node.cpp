#include "gesture_recognition/image_subscriber_node.hpp"

ImageSubscriberNode::ImageSubscriberNode() : Node("image_subscriber_node") {
	image_subscriber = this->create_subscription<sensor_msgs::msg::Image>("image_topic", 10, std::bind(&ImageSubscriberNode::imageProcessing, this, std::placeholders::_1));
	gesture_recognition_ = std::make_shared<GestureRecognition>();
}

void ImageSubscriberNode::imageProcessing(sensor_msgs::msg::Image::SharedPtr image_msg)const {
	if (image_msg->data.empty() == true){
		RCLCPP_ERROR(this->get_logger(), "ERROR : No data recieved, image data empty");
	}
	else{
		//Send image for processing
		std::string response = gesture_recognition_->findGesture(image_msg);
		RCLCPP_INFO(this->get_logger(), "%s was detected",response.c_str());
	}
	rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr image_subscriber;
}

int main(int argc, char * argv[]){

	rclcpp::init(argc, argv);
	rclcpp::spin(std::make_shared<ImageSubscriberNode>());
	rclcpp::shutdown();
	return 0;
}