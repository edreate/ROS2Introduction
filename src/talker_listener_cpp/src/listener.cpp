#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>


class Listener : public rclcpp::Node {
    public:
        Listener() : Node("listener_cpp") {
            // Create subscription
            subscription_ = this->create_subscription<std_msgs::msg::String>(
                "talker", 10, std::bind(&Listener::listener_callback, this, std::placeholders::_1)
            );
        }
    private:
        void listener_callback(const std_msgs::msg::String::SharedPtr msg) {
            RCLCPP_INFO(this->get_logger(), "Received: %s", msg->data.c_str());
        }

    // Member variables
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;   
};


int main(int argc, char *argv[]) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<Listener>());
  
  return 0;
}
