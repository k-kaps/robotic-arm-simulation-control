#include "image_publisher_node_hpp"

ImagePublisherNode::ImagePublisherNode() : Node("image_publisher_node") {
	const int DELAY = 1000;
	auto image_publisher = create_publisher<sensor_msgs::msg::Image>("image_topic", 10);
};

void ImagePublisherNode::pubishImage() {
	
	cv::VideoCapture cap(0) ;
	
	if (!cap.isOpened()){
		const std::string red_color = "\033[1;31m";
		const std::string reset_color = "\033[0m";
		std::string message = red_color + "Failed to open camera" + reset_color;
		
		RCLCPP_ERROR(node->get_logger(), message)
		
		rclcpp::shutdown();
		
		return EXIT_FAILURE;
	}
	
	while(rclcpp:ok()){
		cv::Mat frame;
		cap >> frame;
		
		if (!frame.empty()){
			sensor_msgs::msg::Image::SharedPtr image_msg = cv_bridge::CvImage(std_msgs::msg::Header(), "bgr8", frame).toImageMsg();
			
			image_publisher->publish(image_msg);
		}
		
		std::this_thread::sleep_for(std::chrono::milliseconds(DELAY));
	}
	
	cap.release();
	rclcpp::shutdown();
	
	return EXIT_SUCCESS;
}
