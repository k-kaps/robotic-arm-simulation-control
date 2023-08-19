#include "gesture_recognition/image_publisher_node.hpp"

using namespace std::chrono_literals;

/* This example creates a subclass of Node and uses std::bind() to register a
* member function as a callback from the timer. */
ImagePublisherNode::ImagePublisherNode() : Node("image__publisher_node"), count_(0){
	image_publisher_ = this->create_publisher<sensor_msgs::msg::Image>("image_topic", 10);
	timer_ = this->create_wall_timer(100ms, std::bind(&ImagePublisherNode::publishImage, this));
}

void ImagePublisherNode::publishImage(){
	cv::VideoCapture cap(0, cv::CAP_V4L2);

	cv::Mat frame;
	cap >> frame;

	if (!frame.empty()){
		// Converting the Mat to a image message
		msg_ = cv_bridge::CvImage(std_msgs::msg::Header(), "bgr8", frame).toImageMsg();
		image_publisher->publish(*msg_.get());

		RCLCPP_INFO(this->get_logger(), "Published Image %ld", count_);
		count_++;
	}
	
	rclcpp::TimerBase::SharedPtr timer_;
	sensor_msgs::msg::Image::SharedPtr msg_;
    rclcpp::Publisher<sensor_msgs::msg::Image>::SharedPtr image_publisher_;
	size_t count_;
}

int main(int argc, char * argv[]){
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<ImagePublisherNode>());
  rclcpp::shutdown();
  return 0;s
}
