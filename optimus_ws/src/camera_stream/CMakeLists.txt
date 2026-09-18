cmake_minimum_required(VERSION 3.8)
project(camera_stream)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# 1. Locate Dependencies Directory
set(DEPENDENCIES_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../../../Dependencies")

# 2. Find ROS 2 Packages
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(depthai_bridge REQUIRED)

# 3. Add depthai-core Source (Disable tests/examples to speed up build)
set(DEPTHAI_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(DEPTHAI_BUILD_TESTS OFF CACHE BOOL "" FORCE)
add_subdirectory("${DEPENDENCIES_DIR}/depthai-core" "${CMAKE_CURRENT_BINARY_DIR}/depthai-build")

# 4. Executable Configuration
add_executable(camera_stream_node src/main.cpp)
target_compile_features(camera_stream_node PUBLIC cxx_std_17)

target_include_directories(camera_stream_node PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

ament_target_dependencies(camera_stream_node 
  rclcpp
  std_msgs
  depthai_bridge
)

# Link the target exported directly by add_subdirectory
target_link_libraries(camera_stream_node
  depthai::core
)

# 5. Installation
install(TARGETS camera_stream_node
  DESTINATION lib/${PROJECT_NAME}
)

install(
  DIRECTORY include/
  DESTINATION include
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
