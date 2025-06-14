#include <chrono>
#include <memory>
#include <rclcpp/executors.hpp>
#include <rclcpp/publisher.hpp>
#include <rclcpp/rclcpp.hpp>
#include <rclcpp/timer.hpp>
#include <rclcpp/utilities.hpp>
#include <trajectory_msgs/msg/detail/joint_trajectory_point__struct.hpp>
#include <trajectory_msgs/msg/joint_trajectory.hpp>
#include <vector>

class RobotCont : public rclcpp::Node {
public:
  RobotCont() : Node("Joint_Publisher") {
    m_Publisher = create_publisher<trajectory_msgs::msg::JointTrajectory>(
        "/Arm_Controller/joint_trajectory", 10);
    m_Timer = create_wall_timer(std::chrono::milliseconds(500), std::bind(&RobotCont::topicCallback, this));

  }

private:
  rclcpp::Publisher<trajectory_msgs::msg::JointTrajectory>::SharedPtr
      m_Publisher;
  rclcpp::TimerBase::SharedPtr m_Timer;

private:
  void topicCallback() {

    trajectory_msgs::msg::JointTrajectory _msg =
        trajectory_msgs::msg::JointTrajectory();

    _msg.joint_names = {"joint_1"};

    trajectory_msgs::msg::JointTrajectoryPoint point;
    point.positions = {100.0};
    point.velocities = {0.0};
    point.accelerations = {0.0};
    point.time_from_start.sec = 2;
    point.time_from_start.sec = 0;

    _msg.points.push_back(point);
    m_Publisher->publish(_msg);
  }
};

int main(int argc, char* argv[]) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<RobotCont>());
  rclcpp::shutdown();

}
