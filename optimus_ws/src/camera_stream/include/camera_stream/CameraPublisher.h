#ifndef CAMERAPUBLISHER_H
#define CAMERAPUBLISHER_H

#include <cstdio>

#include "depthai/device/Device.hpp"
#include "depthai/pipeline/Pipeline.hpp"
#include "depthai/pipeline/node/Camera.hpp"
#include "depthai_bridge/BridgePublisher.hpp"
#include "depthai_bridge/ImageConverter.hpp"
#include "depthai_bridge/TFPublisher.hpp"
#include "depthai_bridge/depthaiUtility.hpp"
#include "rclcpp/node.hpp"

class CameraPublisher : public rclcpp::Node
{
private:
	int camera_width;
	int camera_height;
	int camera_fps;
	std::string tfprefix;
	auto device;
	auto camera;
	auto video_queue;
	dai::Pipeline pipeline;
	auto ros_bridge;
	auto calibration_handler;
	auto tf_publisher;
	auto rgb_camera_info;
	auto rgb_publisher;

	void setup_camera();
	void setup_ros2();
	void setup_pipeline();	
		
public:
	CameraPublisher() : Node("camera_publisher"){};
	~CameraPublisher();

	void init();
};

#endif
