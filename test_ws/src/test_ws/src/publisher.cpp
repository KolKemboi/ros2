#include <chrono>
#include <functional>
#include <geometry_msgs/msg/detail/twist__struct.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include <memory>
#include <rclcpp/logging.hpp>
#include <rclcpp/publisher.hpp>
#include <rclcpp/rclcpp.hpp>
#include <rclcpp/timer.hpp>
#include <rclcpp/utilities.hpp>

using namespace std::chrono_literals;

// Make a class -> make it inherit from rclcpp::Node
// In the public field:
//   Make the publisher
// In the private field
//   Make the timer
//   Make the publisher declaration
//   Make the function that publishes the messages
//

class Publisher : public rclcpp::Node {
public:
  Publisher() : Node("Custom Pub"), m_Count(0) {
    m_Publisher = this->create_publisher<geometry_msgs::msg::Twist>(
        "/turtle1/cmd_vel", 10);
    this->m_Timer = this->create_wall_timer(
        500ms, std::bind(&Publisher::publish_vel, this));
  }

private: // variables
  rclcpp::TimerBase::SharedPtr m_Timer;
  rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr m_Publisher;
  size_t m_Count;

private: // functions
  void publish_vel() {
    geometry_msgs::msg::Twist _msg = geometry_msgs::msg::Twist();
    _msg.linear.x = 1.0;
    _msg.angular.z = 1.0;
    RCLCPP_INFO(this->get_logger(), "Publishing Vel...");
    m_Publisher->publish(_msg);
  }
};

int main(int argc, char **argv) {
  // Init rclcpp
  // Make a smart_ptr to the class
  // spin the node
  // shut down rclcpp
  //

  rclcpp::init(argc, argv);
  std::shared_ptr<Publisher> pub = std::make_shared<Publisher>();
  rclcpp::spin(pub);

  rclcpp::shutdown();
  return 0;
}
