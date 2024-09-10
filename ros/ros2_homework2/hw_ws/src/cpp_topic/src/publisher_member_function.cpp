#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int32.hpp"
// Fill the missing line of code
// Hint: include the ROS2 integer 32 bit library for messaging

int main(int argc, char** argv)
{
    rclcpp::init(argc, argv); // Explain this line
    auto node = rclcpp::Node::make_shared("publisher_node"); // Explain this line
    auto publisher = node->create_publisher<std_msgs::msg::Int32>("count_values", 10); // Explalin this line
    
    // 
    rclcpp::Rate loop_rate(1);
        
    int count = 1;
    while (rclcpp::ok() && count <= 5)
    {
	rclcpp::spin_some(node);
        auto msg = std_msgs::msg::Int32();
        // Fill the missing line of code
   	msg.data = count;
        // Hint: makes the content of "msg" to be the value of "count" variable

        publisher->publish(msg);
        RCLCPP_INFO(node->get_logger(), "Publishing: %d", msg.data); // Explain this line
        // Fill the missing line of code
        // Hint: execute the callback function under the "node" node

        loop_rate.sleep();
        count++;
    }
    
    rclcpp::shutdown();
    return 0;    
}
