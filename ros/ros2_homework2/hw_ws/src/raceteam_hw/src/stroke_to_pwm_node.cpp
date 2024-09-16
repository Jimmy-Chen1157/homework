#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float32.hpp"
#include "std_msgs/msg/int32.hpp"

using std::placeholders::_1;

class StrokeToPwmNode : public rclcpp::Node
{
public:
	StrokeToPwmNode() : Node("stroke_to_pwm_node")
	{
	        // Create publisher of topic "pwm_signal" with message type Int32
		publisher_ = this->create_publisher<std_msgs::msg::Int32>("pwm_signal", 10);
		
		// Create subscriber of topic "pedal_stroke", binding with pedalSignalCallback function
		subscription_ = this->create_subscription<std_msgs::msg::Int32>(
    		"pedal_stroke", 10, std::bind(&StrokeToPwmNode::pedalSignalCallback, this, _1));
	}

private:
	void pedalSignalCallback(const std_msgs::msg::Int32::SharedPtr msg)
	{
		int pwm = strokeToSignal(msg->data);	 // Convert received msg to pwm format
		auto output = std_msgs::msg::Int32();	 // Processed Data Holder
		output.data = pwm;			// Set output data to pwm
		publisher_ -> publish(output);		// Publisher publishes output through "pwm_signal" topic
		RCLCPP_INFO(this->get_logger(), "I heard: '%d'", msg->data);	  // Print received message on console
		RCLCPP_INFO(this->get_logger(), "Publishing: '%d'", output.data); // Print output data(processed message) on console 
	}
	
	// Linear conversion of pedal stroke to pwm signal
	int strokeToSignal(int num) const
	{
		int result = num*255/4095;
  		return result;	  
	}
	
	// Pointer to Publisher and Subscriber objects
	rclcpp::Subscription<std_msgs::msg::Int32>::SharedPtr subscription_;
 	rclcpp::Publisher<std_msgs::msg::Int32>::SharedPtr publisher_;
};


int main(int argc, char **argv)
{
	rclcpp::init(argc, argv);
	rclcpp::spin(std::make_shared<StrokeToPwmNode>());
	rclcpp::shutdown();
	return 0;
}
