#ifndef GESTURE_RECOGNITION_HPP
#define GESTURE_RECOGNITION_HPP

#include <cstdlib>
#include "sensor_msgs/msg/image.hpp"

std::string gestureRecognition(sensor_msgs::msg::Image::SharedPtr image_msg);

#endif //GESTURE_RECOGNITION_HPP
