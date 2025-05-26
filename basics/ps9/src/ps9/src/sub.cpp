#include <memory>
#include <rclcpp/logging.hpp>
#include <rclcpp/node.hpp>
#include <rclcpp/rclcpp.hpp>
#include <rclcpp/subscription.hpp>
#include <rclcpp/utilities.hpp>
#include <turtlesim/msg/detail/pose__struct.hpp>
#include <turtlesim/msg/pose.hpp>

using std::placeholders::_1;

class Sub : public rclcpp::Node {
public:
  Sub() : Node("Sub") {
    this->m_Sub = create_subscription<turtlesim::msg::Pose>(
        "/turtle1/pose", 10, std::bind(&Sub::topic_callback, this, _1));
  }

private:
  rclcpp::Subscription<turtlesim::msg::Pose>::SharedPtr m_Sub;
  void topic_callback(const turtlesim::msg::Pose &pose) const {
    RCLCPP_INFO(this->get_logger(), "X=%.3f", pose.x);
  }
};

int main(int argc, char *argv[]) {
  rclcpp::init(argc, argv);
  std::shared_ptr<Sub> node = std::make_shared<Sub>();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}
