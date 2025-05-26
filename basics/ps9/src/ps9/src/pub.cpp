#include <chrono>
#include <geometry_msgs/msg/detail/twist__struct.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include <memory>
#include <rclcpp/create_publisher.hpp>
#include <rclcpp/logging.hpp>
#include <rclcpp/node.hpp>
#include <rclcpp/publisher.hpp>
#include <rclcpp/rclcpp.hpp>
#include <rclcpp/utilities.hpp>

using namespace std::chrono_literals;

class Pub : public rclcpp::Node {
public:
  Pub() : Node("Pub") {
    this->m_Pub =
        create_publisher<geometry_msgs::msg::Twist>("/turtle1/cmd_vel", 10);
    this->m_Timer = create_wall_timer(500ms, std::bind(&Pub::pub_vel, this));
  }

private:
  rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr m_Pub;
  rclcpp::TimerBase::SharedPtr m_Timer;

private:
  void pub_vel() {
    geometry_msgs::msg::Twist _msg = geometry_msgs::msg::Twist();

    _msg.linear.x = 1.0;
    _msg.angular.z = 1.0;

    RCLCPP_INFO(this->get_logger(), "PUB NODE");
    this->m_Pub->publish(_msg);
  }
};

int main(int argc, char *argv[]) {
  rclcpp::init(argc, argv);
  std::shared_ptr<Pub> node = std::make_shared<Pub>();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}
