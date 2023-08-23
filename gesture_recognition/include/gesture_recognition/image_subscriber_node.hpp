#ifndef IMAGE_SUBSCRIBER_NODE_HPP_
#define IMAGE_SUBSCRIBER_NODE_HPP_

#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/image.hpp"
#include "trajectory_msgs/msg/joint_trajectory.hpp"
#include "gesture_recognition/gesture_recognition.hpp"

class ImageSubscriberNode : public rclcpp::Node
{
public:
    ImageSubscriberNode();

private:
    void imageProcessing(const sensor_msgs::msg::Image::SharedPtr image_msg) const;
    bool robotControl(std::string &response) const;
	rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr image_subscriber_;
    rclcpp::Publisher<trajectory_msgs::msg::JointTrajectory>::SharedPtr robot_controller_;
    std::shared_ptr<GestureRecognition> gesture_recognition_;
};

#endif  // IMAGE_SUBSCRIBER_NODE_HPP_