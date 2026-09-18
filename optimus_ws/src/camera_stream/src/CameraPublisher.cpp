#include "CameraPublisher.h"
#include "CameraUtils.h"

void CameraPublisher::setup_camera(){
	this->camera_width = CAMERA_WIDTH;
	this->camera_height = CAMERA_HEIGHT;
	this->camera_fps = DESIRED_FPS;
	this->device = std::make_shared<dai::Device>();
	this->pipeline(device);
	this->camera = this->pipeline.create<dai::node::Camera>()->build(dai::CameraBoardSocket::CAM_A);
	this->video_queue = this->camera->requestOutput({width, height})->createOutputQueue(
			ROS2_TOPIC_QUEUE_SIZE, 
			false);
	this->pipeline.start();
	this->calibration_handler = this->device->readCalibration();
	this->rgb_camera_info = this->ros_bridge->calibrationToCamera(
			this->calibration_handler, 
			dai::CameraBoardSocket::CAM_A, 
			width, 
			height);	
}

void CameraPublisher::setup_ros2(){
	this->tprefix = "oak";
	this->bridge = std::make_shared<depthai_bridge::ImageConverter>(
		depthai_bridge::getOpticalFrameName(
			this->tfprefix,
			depthai_bridge::getSocketName(dai::CameraBoardSocket::CAM_A, 
			this->device->getDeviceName())), false);	
}

void CameraPublisher::init(){
	this->setup_camera();
	this->setup_ros2();

	this->tf_publisher = std::make_unique<depthai_bridge::TFPublisher>(
			*this, 
			this->calibration_handler, 
			this->device->getConnectedCameraFeatures(), 
			this->tfprefix, 
			this->device->getDeviceName());

	this->rgb_publisher = std::make_unique<depthai_bridge::BridgePublisher<sensor_msgs::msg::Image,dai::ImgFRame>>(
	this->video_queue,
	*this,
	"rgb/image",
	[this->ros_bridge](std::shared_ptr<dai::ImgFrame> msg,
		std::deque<sensor_msgs::msg::Image>& rosMsgs) {
		this->ros_bridge->toRosMsg(msg, rosMsgs); },
	DESIRED_FPS,
	this->rgb_camera_info,
	"rgb");

	this->rgb_publisher->addPublisherCallback();
}
