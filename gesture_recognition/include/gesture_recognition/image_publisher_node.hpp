#ifndef IMAGE_PUBLISHER_NODE_HPP_
#define IMAGE_PUBLISHER_NODE_HPP_

#include <chrono>
#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "sensor_msgs/msg/image.hpp"
#include <opencv2/opencv.hpp>
#include <cv_bridge/cv_bridge.h>
//#include <image_trannsport/image_transport.hpp>

using namespace std::chrono_literals;

class ImagePublisherNode : public rclcpp::Node {
public:
    ImagePublisherNode();

private:
    void publishImage();

    rclcpp::TimerBase::SharedPtr timer;
	sensor_msgs::msg::Image::SharedPtr msg;
    rclcpp::Publisher<sensor_msgs::msg::Image>::SharedPtr image_publisher;
    size_t count_;
};

int main(int argc, char * argv[]);

#endif // IMAGE_PUBLISHER_NODE_HPP_