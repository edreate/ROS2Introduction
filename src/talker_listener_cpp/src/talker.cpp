#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>

#include <string>
#include <chrono>


using namespace std::chrono_literals;

class Talker : public rclcpp::Node {
  public:
    Talker() : Node("talker_cpp"), count_(0) {
      // Create publisher
      publisher_ = this->create_publisher<std_msgs::msg::String>("talker", 10);

      // Create timer
      timer_ = this->create_wall_timer(1s, std::bind(&Talker::publish_message, this));
    }

  private:
    void publish_message() {
      auto message = std_msgs::msg::String();
      message.data = "Hello from talker_cpp: " + std::to_string(count_++);
      publisher_->publish(message);
      
      RCLCPP_INFO(this->get_logger(), "Published: %s", message.data.c_str());
    }

    // Member variables
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
    int count_;
};

int main(int argc, char *argv[]) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<Talker>());
}
