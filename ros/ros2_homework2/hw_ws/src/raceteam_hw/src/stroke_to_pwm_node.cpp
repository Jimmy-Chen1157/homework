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
		publisher_ = this->create_publisher<std_msgs::msg::Int32>("pwm_signal", 10);
		subscription_ = this->create_subscription<std_msgs::msg::Int32>(
    		"pedal_stroke", 10, std::bind(&StrokeToPwmNode::pedalSignalCallback, this, _1));			//pedal_stroke
	}

private:
	void pedalSignalCallback(const std_msgs::msg::Int32::SharedPtr msg)
	{
		int pwm = strokeToSignal(msg->data);
		auto output = std_msgs::msg::Int32();
		output.data = pwm;
		publisher_ -> publish(output);
		RCLCPP_INFO(this->get_logger(), "I heard: '%d'", msg->data);
		RCLCPP_INFO(this->get_logger(), "Publishing: '%d'", output.data);
	}

	int strokeToSignal(int num) const
	{
		int result = num*255/4095;
  		return result;	  
	}

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
