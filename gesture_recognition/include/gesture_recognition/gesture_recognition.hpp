#ifndef GESTURE_RECOGNIITON_HPP_
#define GESTURE_RECOGNIITON_HPP_

#include <cstdlib>
#include "sensor_msgs/msg/image.hpp"

class GestureRecognition{
public:
    GestureRecognition();
    std::string findGesture(sensor_msgs::msg::Image::SharedPtr image_msg);
private :
    std::string gesture;
};

#endif //GESTURE_RECOGNIITON_HPP_
