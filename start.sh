# Start script for Primus / Optimus, runs every node in ws/src upon start

# Source packages
cd optimus_ws
colcon build
source install/setup.bash

# Launch all camera nodes in background (&) discard stdout > /dev/null 2>&1
ros2 launch depthai_ros_driver_v3 driver.launch.py params_file:=camera.yaml > /dev/null 2>&1 & 
ros2 run neuralnetwork yolo_detector > /dev/null 2>&1 &
ros2 run neuralnetwork overlay_creator > /dev/null 2>&1 &
ros2 launch foxglove_bridge foxglove_bridge_launch.xml > /dev/null 2>&1 &
~                                                                             
