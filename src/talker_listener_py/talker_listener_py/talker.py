import rclpy
from rclpy.node import Node

from std_msgs.msg import String

class Talker(Node):

    def __init__(self):
        super().__init__("talker_py")

        self.publisher = self.create_publisher(String, "talker", 10)

        self.timer = self.create_timer(1.0, self.talker_callback)

        self.talker_count = 0
    
    def talker_callback(self):
        msg = String()
        msg.data = f"Hello from talker: {self.talker_count}"

        self.publisher.publish(msg)

        self.get_logger().info(f"Published message: {msg.data}")

        self.talker_count += 1


def main(args=None):
    rclpy.init(args=args)

    talker = Talker()
    rclpy.spin(talker)

if __name__ == "__main__":
    main()
