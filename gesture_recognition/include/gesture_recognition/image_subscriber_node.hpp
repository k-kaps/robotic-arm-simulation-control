#ifndef IMAGE_SUBSCRIBER_NODE_HPP_
#define IMAGE_SUBSCRIBER_NODE_HPP_

#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/image.hpp"
#include "gesture_recognition/gesture_recognition.hpp"

class ImageSubscriberNode : public rclcpp::Node
{
public:
    ImageSubscriberNode();

private:
    void imageProcessing(const sensor_msgs::msg::Image::SharedPtr image_msg) const;
	rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr image_subscriber;
    std::shared_ptr<GestureRecognition> gesture_recognition_;
};

#endif  // IMAGE_SUBSCRIBER_NODE_HPP_