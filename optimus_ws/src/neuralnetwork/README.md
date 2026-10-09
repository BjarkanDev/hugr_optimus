# NeuralNetwork (NN) package


1. What does the package do?
2. What are the prerequisites and dependencies?
3. How do you install the package?
4. How do you configure the package?
5. How do you use the package? Include a minimal example (optional, but wanted).
6. How do you run the tests?
7. How do you build, develop?
8. Who maintains the package?

## What does the package do?

The package subscribes to the /oak/rgb/image_raw/compressed topic and runs a YOLO buoy detection model on the provided image frames, it then posts these detections as its own topic /oak/rgb/detections, which can be used to produce annotation overlay frames that can be displayed in GUI applications such as FoxGlove. 

## What are the prerequisites and dependencies?

## How do you install the package?

## How do you configure the package?

blank

## How do you use the package?

Once prerequisite system dependencies are established the package and its subsequent nodes are activated after standard `colcon build` and `ros2 run neuralnetwork <node name>` is performed.

Example bash commands to execute detection model:

```bash
cd ~/hugr_optimus/optimus_ws
colcon build
source install/setup.bash
ros2 run neuralnetwork yolo_detector
```

## How do you run the tests?

Tests have not yet been established for this package, this is to be rectified as soon as a model version good enough for everyday use is established. 
## Who maintains the package?

While the SeaBotics Student Association is overall responsible for the repository and subsequently this package; Bjørn Sødal is the original developer and maintainer of this package. Credentials are found in `package.xml`. 
