#include <chrono>
#include <geometry_msgs/msg/detail/twist__struct.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include <memory>
#include <rclcpp/logging.hpp>
#include <rclcpp/publisher.hpp>
#include <rclcpp/rclcpp.hpp>
#include <rclcpp/timer.hpp>
#include <rclcpp/utilities.hpp>

using namespace std::chrono_literals;

class Publisher : public rclcpp::Node {
public:
  Publisher() : Node("Cust_Node") {
    m_Publisher = this->create_publisher<geometry_msgs::msg::Twist>(
        "/turtle1/cmd_vel", 10);
    m_Timer = this->create_wall_timer(
        500ms, std::bind(&Publisher::publish_cmd_vel, this));
  }

private:
  rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr m_Publisher;
  rclcpp::TimerBase::SharedPtr m_Timer;

private:
  void publish_cmd_vel() {
    geometry_msgs::msg::Twist _msg = geometry_msgs::msg::Twist();

    _msg.linear.x = 1.9;
    _msg.angular.z = 2.0;

    RCLCPP_INFO(this->get_logger(), "Publisher");
    m_Publisher->publish(_msg);
  }
};

int main(int argc, char *argv[]) {
  rclcpp::init(argc, argv);
  std::shared_ptr<Publisher> pub = std::make_shared<Publisher>();
  rclcpp::spin(pub);
  rclcpp::shutdown();
  return 0;
}
