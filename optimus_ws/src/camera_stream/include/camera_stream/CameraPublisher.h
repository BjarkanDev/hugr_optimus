#ifndef CAMERAPUBLISHER_H
#define CAMERAPUBLISHER_H

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

#include <iostream>
#include <depthai/depthai.hpp>

class CameraPublisher : public rclcpp::Node
{
private:
	// Camera specs
	int width;
	int height;
	int fps;

	// ROS2 Publishers
	rclcpp::Publisher<std_msgs::msg:String>::SharedPtr raw_publisher;
	rclcpp::Publisher<std_msgs::msg:String>::SharedPtr compressed_publisher;
	//rclcpp::Publisher<std_msgs::msg:String>::SharedPtr detect_publisher;
	
	// Luxonis interfaces
	std::shared_ptr<dai::Device> device;
	dai::Pipeline pipeline;
	auto cam;
	auto video_queue;
		
public:
	CameraPublisher();
	~CameraPublisher();
};

#endif
