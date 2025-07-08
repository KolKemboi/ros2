#include <geometry_msgs/msg/detail/pose__struct.hpp>
#include <geometry_msgs/msg/pose.hpp>
#include <iostream>
#include <moveit/move_group_interface/move_group_interface.h>
#include <rclcpp/logging.hpp>
#include <rclcpp/rclcpp.hpp>
#include <rclcpp/utilities.hpp>

class WelderArmPlanner {
public:
  WelderArmPlanner(const rclcpp::Node::SharedPtr &node,
                   const std::string &planning_group)
      : move_group_interface_(node, planning_group),
        logger_(rclcpp::get_logger("WelderArmPlanner")) {}
  geometry_msgs::msg::Pose getDefaultTargetPose() const {
    geometry_msgs::msg::Pose pose;
    pose.orientation.w = 1.0;
    pose.position.x = 0.1;
    pose.position.y = 0.05;
    pose.position.z = 0.1;
    return pose;
  }

  bool planToPose(const geometry_msgs::msg::Pose &target_pose) {
    move_group_interface_.setPoseTarget(target_pose);
    moveit::planning_interface::MoveGroupInterface::Plan plan;

    bool success = static_cast<bool>(move_group_interface_.plan(plan));
    if (success) {
      move_group_interface_.execute(plan);
      RCLCPP_INFO(logger_, "EXECUTED");
    } else {
      RCLCPP_WARN(logger_, "FAILED");
    }
    return success;
  }

private:
  moveit::planning_interface::MoveGroupInterface move_group_interface_;
  rclcpp::Logger logger_;
};

int main(int argc, char **argv) {
  rclcpp::init(argc, argv);
  auto node = std::make_shared<rclcpp::Node>(
      "hello_mvt",
      rclcpp::NodeOptions().automatically_declare_parameters_from_overrides(
          true));

  WelderArmPlanner planner(node, "Welder_Arm");

  auto target_pose = planner.getDefaultTargetPose();
  planner.planToPose(target_pose);

  rclcpp::shutdown();
  return 0;
}
