#include "camera_stream/CameraPublisher.h"

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  
  // Init node of type CameraPublisher
  auto node = std::make_shared<CameraPublisher>();
  node->init(); 

  rclcpp::spin(node);

  rclcpp::shutdown();
  return 0;
}
