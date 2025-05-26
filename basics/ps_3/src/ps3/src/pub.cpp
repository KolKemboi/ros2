#include <chrono>
#include <functional>
#include <geometry_msgs/msg/detail/twist__struct.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include <memory>
#include <rclcpp/logging.hpp>
#include <rclcpp/node.hpp>
#include <rclcpp/publisher.hpp>
#include <rclcpp/rclcpp.hpp>
#include <rclcpp/utilities.hpp>

using namespace std::chrono_literals;

class Publisher : public rclcpp::Node {
public:
  Publisher() : Node("Cust_Pub") {
    m_Publisher = this->create_publisher<geometry_msgs::msg::Twist>(
        "/turtle1/cmd_vel", 10);
    this->m_Timer = this->create_wall_timer(
        500ms, std::bind(&Publisher::publish_vel, this));
  }

private:
  rclcpp::TimerBase::SharedPtr m_Timer;
  rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr m_Publisher;

private:
  void publish_vel() {
    geometry_msgs::msg::Twist _msg = geometry_msgs::msg::Twist();

    _msg.linear.x = 1.0;
    _msg.angular.z = 1.0;

    RCLCPP_INFO(this->get_logger(), "PUB-----");
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
