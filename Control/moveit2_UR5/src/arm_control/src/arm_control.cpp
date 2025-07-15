#include <cstdio>
#include <cstdlib>
#include <memory>
#include <moveit/move_group_interface/move_group_interface.h>
#include <rclcpp/logging.hpp>
#include <rclcpp/rclcpp.hpp>
#include <rclcpp/utilities.hpp>
#include <utility>

int main(int argc, char **argv) {
  rclcpp::init(argc, argv);

  auto const node = std::make_shared<rclcpp::Node>(
      "Arm_Controller",
      rclcpp::NodeOptions().automatically_declare_parameters_from_overrides(
          true));

  auto const logger = rclcpp::get_logger("Arm_Controller");

  using moveit::planning_interface::MoveGroupInterface;
  auto move_group_interface = MoveGroupInterface(node, "arm");

  auto const target_pose = [] {
    geometry_msgs::msg::Pose msg;
    msg.orientation.w = 1.0;
    msg.position.x = 0.1;
    msg.position.y = 0.1;
    msg.position.z = 0.2;
    return msg;
  }();
  move_group_interface.setPoseTarget(target_pose);

  auto const [success, plan] = [&move_group_interface] {
    moveit::planning_interface::MoveGroupInterface::Plan msg;
    auto const ok = static_cast<bool>(move_group_interface.plan(msg));
    return std::make_pair(ok, msg);
  }();

  if (success) {
    move_group_interface.execute(plan);
  } else {
    RCLCPP_ERROR(logger, "failed");
  }

  rclcpp::shutdown();
  return EXIT_SUCCESS;
}
