#include "gesture_recognition/image_subscriber_node.hpp"

ImageSubscriberNode::ImageSubscriberNode() : Node("image_subscriber_node") {
	image_subscriber_ = this->create_subscription<sensor_msgs::msg::Image>("image_topic", 10, std::bind(&ImageSubscriberNode::imageProcessing, this, std::placeholders::_1));
	gesture_recognition_ = std::make_shared<GestureRecognition>();
	robot_controller_ = this->create_publisher<trajectory_msgs::msg::JointTrajectory>("/arm_controller/joint_trajectory", 10);
}

void ImageSubscriberNode::imageProcessing(sensor_msgs::msg::Image::SharedPtr image_msg)const {
	if (image_msg->data.empty() == true){
		RCLCPP_ERROR(this->get_logger(), "ERROR : No data recieved, image data empty");
	}
	else{
		std::string response = gesture_recognition_->findGesture(image_msg);
		RCLCPP_INFO(this->get_logger(), "%s was detected",response.c_str());
		bool success_msg = robotControl(response);
		if (success_msg == false){
			RCLCPP_ERROR(this->get_logger(), "ERROR : unable to pass information to robot");
		}
		else{
			RCLCPP_INFO(this->get_logger(), "SUCCESS : information successfully passed to the robot");
		}
	}
	rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr image_subscriber_;
}

bool ImageSubscriberNode::robotControl(std::string &response) const {
	if (response == "some gesture"){
		// Arrange Robot in Position A
		trajectory_msgs::msg::JointTrajectory controller_msg;
		
		controller_msg.header.stamp = this->now();
		controller_msg.header.frame_id = "base_link";
		
		controller_msg.joint_names = {"joint_1", "joint_2", "joint_3", "joint_4", "joint_5", "joint_6"};

		trajectory_msgs::msg::JointTrajectoryPoint controller_pt;
		controller_pt.positions =  {90.0, 90.0, 90.0, 90.0, 90.0, 90.0};

		controller_msg.points.push_back(controller_pt);

		robot_controller_->publish(controller_msg);
		return true;
	}
	else if (response == "valueB"){
		// Arrange Robot in Position B

		return true;
	}
	else if (response == "valueC"){
		// Arrange Robot in Position C

		return true;
	}
	else if (response == "valueD"){
		// Arrange Robot in Position D

		return true;
	}
	else{
		return false;
	}
}

int main(int argc, char * argv[]){

	rclcpp::init(argc, argv);
	rclcpp::spin(std::make_shared<ImageSubscriberNode>());
	rclcpp::shutdown();
	return 0;
}