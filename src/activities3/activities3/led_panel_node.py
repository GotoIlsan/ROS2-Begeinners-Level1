#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from my_robot_interfaces.msg import LedPanelState
from my_robot_interfaces.srv import SetLed

class LedPanelNode(Node):
    def __init__(self):
        super().__init__("led_panel_node")

        self.declare_parameter("led_states", [False, False, False])
        self.led = self.get_parameter("led_states").value
        self.set_led_server = self.create_service(SetLed, "set_led", self.callback_set_led)
        self.led_panel_state_publisher = self.create_publisher(LedPanelState, "led_panel_state", 10)
        self.timer_led_state_publish = self.create_timer(1, self.publish_led_panel_state)
    
    def callback_set_led(self, request, response):
        print(self.led)
        print(request.state)
        if request.state == "on":
            if 0 < request.led_number and request.led_number <= len(self.led):
                self.led[request.led_number-1] = True
                response.success = True
            else:
                response.success = False
        elif request.state == "off":
            if 0 < request.led_number and request.led_number <= len(self.led):
                self.led[request.led_number-1] = False
                response.success = True
            else:
                response.success = False
        
        self.led_panel_state_publisher()
        return response
    
    def publish_led_panel_state(self):
        led_panel_state = LedPanelState()
        led_panel_state.led_state = self.led

        self.led_panel_state_publisher.publish(led_panel_state)

def main(args = None):
    rclpy.init(args = args)
    node = LedPanelNode()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == "__main__":
    main()