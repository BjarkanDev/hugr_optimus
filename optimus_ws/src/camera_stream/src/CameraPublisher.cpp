#include "CameraPublisher.h"
#include "Camera_Stream_Utils.h"
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

CameraPublisher::CameraPublisher(){
	// Camera Specs
	width = CAMERA_WIDTH;
	height = CAMERA_HEIGHT;
	fps = DESIRED_FPS;
	
	// ROS2 Publishers
	raw_publisher = this->create_publisher<std_msgs::msg::String>("camera/raw", 10);
	compressed_publisher = this->create_publisher<std_msgs::msg::String>("camera/compressed", 10);
	//detect_publisher = this->create_publisher<std_msgs::msg::String>("camera/detect", 10);
			
};
