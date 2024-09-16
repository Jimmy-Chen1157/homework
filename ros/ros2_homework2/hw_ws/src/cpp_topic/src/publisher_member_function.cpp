#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int32.hpp"
// Fill the missing line of code
// Hint: include the ROS2 integer 32 bit library for messaging

int main(int argc, char** argv)
{
    // Initialize rclcpp for passing values through command line
    rclcpp::init(argc, argv);  

    // Create a Node named "publisher_node", assigned to variable "node" as a pointer
    auto node = rclcpp::Node::make_shared("publisher_node");
    
    // Create publisher of topic "count_values" with message type Int32
    auto publisher = node->create_publisher<std_msgs::msg::Int32>("count_values", 10); 
     
    //  Create a Rate object of 1Hz
    rclcpp::Rate loop_rate(1);
        
    int count = 1;
    while (rclcpp::ok() && count <= 5)
    {
	// Start node
	rclcpp::spin_some(node);
        auto msg = std_msgs::msg::Int32();

        // Fill the missing line of code
   	msg.data = count;
        // Hint: makes the content of "msg" to be the value of "count" variable

        publisher->publish(msg);
	
	// Print data of msg to console
        RCLCPP_INFO(node->get_logger(), "Publishing: %d", msg.data); 

        loop_rate.sleep();
        count++;
    }
    
    rclcpp::shutdown();
    return 0;    
}
