#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from example_interfaces.srv import SetBool
from functools import partial

class MyCustomNode(Node):
    def __init__(self):
        super().__init__("counter_reseter")
        self.get_logger().info("counter reseter start")
        self.set_counter_zero(True)
        self.set_counter_zero(False)

    def set_counter_zero(self, Reset_Flag):
        client = self.create_client(SetBool, "reset_number_count")
        while not client.wait_for_service(5):
            self.get_logger().warn("Waiting for reset number counter Server...")
        
        request = SetBool.Request()
        request.data = Reset_Flag
        
        future = client.call_async(request)
        future.add_done_callback(partial(self.callback_call_reset_number_counter, Reset_Flag=Reset_Flag))

    def callback_call_reset_number_counter(self, future, Reset_Flag):
        print(Reset_Flag)
        try:
            response = future.result()
            self.get_logger().info(f"{response.success}, {response.message}")
        
        except Exception as e:
            self.get_logger().info(f"Service call failed: {e}")

def main(args = None):
    rclpy.init(args = args)
    node = MyCustomNode()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == "__main__":
    main()