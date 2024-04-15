#!/usr/bin/env python3
import rclpy
from example_interfaces.msg import Int64
from rclpy.node import Node
from example_interfaces.srv import SetBool

class Number_Counter_Node(Node):
    def __init__(self):
        super().__init__("number_counter")
        self.counter = 0
        self.subscriber = self.create_subscription(Int64, "number", self.callback_number, 10)
        self.publisher = self.create_publisher(Int64, "number_count", 10)
        self.server = self.create_service(SetBool, "reset_number_count", self.callback_reset_number_count)

    def publish_number_counter(self):
        number_counter = Int64()
        number_counter.data = self.counter
        self.publisher.publish(number_counter)
        self.get_logger().info(f"Published counter: {number_counter.data}")

    def callback_number(self, msg):
        self.get_logger().info(f"Recived number: {msg.data}")
        self.counter += 1
        self.get_logger().info(f"Current counter: {self.counter}")
        self.publish_number_counter()

    def callback_reset_number_count(self, request, response):
        if request.data == True:
            self.get_logger().info("Counter Reseted")
            self.counter = 0
            response.success = True
            response.message = f"Reset counter successful"
        else:
            self.get_logger().info("Counter didn't Reseted")
            response.success = False
            response.message = f"Didnot counter Reset"
        
        return response

    
def main(args=None):
    rclpy.init(args=args)
    node = Number_Counter_Node()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == "__main__":
    main()