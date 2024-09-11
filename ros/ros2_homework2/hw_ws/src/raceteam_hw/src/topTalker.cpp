#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int32.hpp"
#include <stdlib.h>
#include <chrono>
#include <functional>

using namespace std::chrono_literals;

class Talker : public rclcpp::Node
{
public:
	Talker() : Node("talker")
	{
		publisher_ = this->create_publisher<std_msgs::msg::Int32>("pedal_stroke", 10);
      		timer_ = this->create_wall_timer(500ms, std::bind(&Talker::timer_callback, this));
	}
private:
	void timer_callback()
	{
		int x = rand() % 4096;
		auto message = std_msgs::msg::Int32();
		message.data = x;
		publisher_ -> publish(message);
		RCLCPP_INFO(this->get_logger(), "Publishing: '%d'", message.data);
	}
	rclcpp::TimerBase::SharedPtr timer_;
    	rclcpp::Publisher<std_msgs::msg::Int32>::SharedPtr publisher_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<Talker>());
  rclcpp::shutdown();
  return 0;
}
