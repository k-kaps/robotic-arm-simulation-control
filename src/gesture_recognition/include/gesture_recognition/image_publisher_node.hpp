#ifndef IMAGE_PUBLISHER_NODE_HPP
#define IMAGE_PUBLISHER_NODE_HPP

#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/image.hpp"
#include <opencv2/opencv.hpp>

class ImagePublisherNode : public rclcpp::Node {

public : 
	ImagePublisherNode();

private : 
	void publishImage();
}

#endif //IMAGE_PUBLISHER_NODE_HPP
