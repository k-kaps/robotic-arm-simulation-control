#ifndef GESTURE_RECOGNIITON_HPP_
#define GESTURE_RECOGNIITON_HPP_

#include <cstdlib>
#include "sensor_msgs/msg/image.hpp"

class GestureRecognition{
public:
    GestureRecognition();
    std::string gesture;
    std::string findGesture(sensor_msgs::msg::Image::SharedPtr image_msg);
};

#endif //GESTURE_RECOGNIITON_HPP_
