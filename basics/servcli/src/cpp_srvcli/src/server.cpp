#include "example_interfaces/srv/add_two_ints.hpp"
#include <example_interfaces/srv/detail/add_two_ints__struct.hpp>
#include <memory>
#include <rclcpp/executors.hpp>
#include <rclcpp/logger.hpp>
#include <rclcpp/logging.hpp>
#include <rclcpp/rclcpp.hpp>
#include <rclcpp/service.hpp>
#include <rclcpp/utilities.hpp>

void add(
    const std::shared_ptr<example_interfaces::srv::AddTwoInts::Request> request,
    std::shared_ptr<example_interfaces::srv::AddTwoInts::Response> response) {
  response->sum = request->a + request->b;
  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Incoming request");
  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Outgoing responce [%ld]", (long int)response->sum);
}

int main(int argc, char **argv) {
  rclcpp::init(argc, argv);
  std::shared_ptr<rclcpp::Node> node =
      rclcpp::Node::make_shared("add_two_ints_server");

  rclcpp::Service<example_interfaces::srv::AddTwoInts>::SharedPtr service =
      node->create_service<example_interfaces::srv::AddTwoInts>("add_two_ints",
                                                                &add);

  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "ready to add two ints");

  rclcpp::spin(node);
  rclcpp::shutdown();
}
