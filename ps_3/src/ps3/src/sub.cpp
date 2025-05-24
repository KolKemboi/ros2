#include <functional>
#include <memory>
#include <rclcpp/logging.hpp>
#include <rclcpp/rclcpp.hpp>
#include <rclcpp/subscription.hpp>
#include <rclcpp/utilities.hpp>
#include <turtlesim/msg/detail/pose__struct.hpp>
#include <turtlesim/msg/pose.hpp>

using std::placeholders::_1;

class Subscriber : public rclcpp::Node {
public:
  Subscriber() : Node("Cust_Sub") {
    m_Subscriber = this->create_subscription<turtlesim::msg::Pose>(
        "/turtle1/pose", 10, std::bind(&Subscriber::topic_callback, this, _1));
  }

private:
  rclcpp::Subscription<turtlesim::msg::Pose>::SharedPtr m_Subscriber;

  void topic_callback(const turtlesim::msg::Pose &pose) const {
    RCLCPP_INFO(this->get_logger(), "X = %.2f, Theta = %.2f", pose.x,
                pose.theta);
  }
};

int main(int argc, char *argv[]) {
  rclcpp::init(argc, argv);

  std::shared_ptr<Subscriber> sub = std::make_shared<Subscriber>();
  rclcpp::spin(sub);
  rclcpp::shutdown();
  return 0;
}
