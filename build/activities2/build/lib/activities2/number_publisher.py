#!/usr/bin/env python3
import rclpy
from example_interfaces.msg import Int64
from rclpy.node import Node
import random

class Number_Publisher_Node(Node):
    def __init__(self):
        super().__init__("number_publisher")
        self.declare_parameter("number_to_publish", 3)
        self.declare_parameter("publish_frequency", 1)

        self.publsih_frequency = self.get_parameter("publish_frequency").value
        self.num = self.get_parameter("number_to_publish").value
        self.publisher = self.create_publisher(Int64, "number", 10)
        self.timer = self.create_timer(1/self.publsih_frequency, self.publish_number)
    
    def publish_number(self):
        publish_num = Int64()
        publish_num.data = self.num
        self.publisher.publish(publish_num)
        self.get_logger().info(f"Publish Data: {publish_num.data}")

def main(args=None):
    rclpy.init(args=args)
    node = Number_Publisher_Node()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == "__main__":
    main()