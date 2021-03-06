// #############################################################################
// keyboard_teleop.h
//
// Node allows user to publish Twist commands to a topic (default: /cmd_vel).
// #############################################################################

#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp" // Allows you to use the most common pieces of the ROS2 system.
#include "geometry_msgs/msg/twist.hpp"

class KeyboardTeleop : public rclcpp::Node
{
public:
    KeyboardTeleop();

private:
    std::string topic_name = "/cmd_vel";

    void read_arrow_keys();

    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_pub_;
};
