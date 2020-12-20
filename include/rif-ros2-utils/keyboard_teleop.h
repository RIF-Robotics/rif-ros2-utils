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
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;

/* This example creates a subclass of Node and uses std::bind() to register a
 * member function as a callback from the timer. */

class KeyboardTeleop : public rclcpp::Node
{
public:
    KeyboardTeleop() : Node("keyboard_teleop"), count_(0) {
        publisher_ = this->create_publisher<std_msgs::msg::String>("sergiotest", 10);
        timer_ = this->create_wall_timer(500ms, std::bind(&KeyboardTeleop::timer_callback, this));
    }

private:
    void timer_callback();
    /* void timer_callback() { */
    /*     auto message = std_msgs::msg::String(); */
    /*     message.data = "Hello, world! " + std::to_string(count_++); */
    /*     RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str()); */
    /*     publisher_->publish(message); */
    /* } */
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    size_t count_;
};