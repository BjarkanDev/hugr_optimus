# Building optimus_ws

Remember to **ALWAYS** *colcon build* in root-workspace `~/hugr_optimus/optimus_ws`.

First source ROS2: In your terminal, run.

```bash
source /opt/ros/jazzy/setup.bash
```

After ROS2 is sourced, source the workspace.

```bash
source install/setup.bash
```

You can also run specific packages with.

```bash
colcon build --packages-select <package-name>
```

To update files changed/install after editig without compiling the entire packages again.

```bash
colcon build --symlink-install
```
