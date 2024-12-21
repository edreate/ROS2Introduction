import rclpy
from rclpy.node import Node

from std_msgs.msg import String

class Listener(Node):

    def __init__(self):
        super().__init__("listener_py")

        self.subscriber = self.create_subscription(
            String,
            "talker",
            self.listener_callback,
            10
            )

    def listener_callback(self, msg: String):
        
        self.get_logger().info(f"Listener received messaged: {msg.data}")


def main(args=None):
    rclpy.init(args=args)

    listener = Listener()
    rclpy.spin(listener)

if __name__ == "__main__":
    main()
