#!/usr/bin/env python3
import rclpy
import time
import random
from rclpy.node import Node
from my_robot_interfaces.srv import SetLed
from functools import partial


class BatteryNode(Node):
    def __init__(self):
        super().__init__("battery_node")
        self.last_led_num = random.randint(-1, 3)
        self.battery = True
        self.check_battery_start_time = time.time()
        self.last_led_num = 0
        self.battery_timer = self.create_timer(0.1, self.callback_battery_timer)

    def callback_battery_timer(self):
        if self.battery == True:
            if time.time() - self.check_battery_start_time > 4:
                self.battery = False
                self.check_battery_start_time = time.time()
                self.last_led_num = random.randint(-1, 3)
                self.call_set_led_on(self.last_led_num, FLAG_ON = True)
        else:
            if time.time() - self.check_battery_start_time > 6:
                self.battery = True
                self.check_battery_start_time = time.time()
                self.call_set_led_on(self.last_led_num, FLAG_ON = False)

    def get_current_time_seconds(self):
        secs, nsecs = self.get_clock().now().seconds_nanoseconds()
        return secs + nsecs / 1000000000.0
    
    def call_set_led_on(self, led_num, FLAG_ON):
        client = self.create_client(SetLed, "set_led")
        while not client.wait_for_service(5):
            self.get_logger().info("Waiting for set_led Server...") 

        request = SetLed.Request()
        request.led_number = self.last_led_num
        if FLAG_ON == True:
            request.state = "on"
        else:
            request.state = "off"

        future = client.call_async(request)
        future.add_done_callback(partial(self.callback_set_led, led_num = self.last_led_num, FLAG_ON = FLAG_ON))
    
    def callback_set_led(self, future, led_num, FLAG_ON):
        response = future.result()
        try:
            if response.success == True:
                self.get_logger().info(f"Service call for {led_num} to {FLAG_ON} success.")
            else:
                self.get_logger().info(f"Service call for {led_num} to {FLAG_ON} failed.")
        except Exception as e:
            self.get_logger(f"Service call failed: {e}")

def main(args = None):
    rclpy.init(args = args)
    node = BatteryNode()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == "__main__":
    main()