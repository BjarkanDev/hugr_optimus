# Start script for Primus / Optimus, runs every node in ws/src upon start

cd optimus_ws
colcon build 
source install/setup.bash

# Launch all camera nodes in background (&)
ros2 launch depthai_ros_driver driver.launch.py params_file:=camera.yaml
ros2 run neuralnetwork yolo_detector & 
ros2 run neuralnetwork overlay_creator & 

