#!/usr/bin/env python3
from functools import partial
import random
import rclpy
import math
from rclpy.node import Node
from turtlesim.srv import Spawn
from turtlesim.srv import Kill
from my_robot_interfaces.msg import Turtle
from my_robot_interfaces.msg import TurtleArray
from my_robot_interfaces.srv import CatchTurtle

class TurtleSpawner(Node):
    def __init__(self):
        super().__init__("turtle_spawner")

        self.declare_parameter("spawn_frequency", 1.0)
        self.declare_parameter("turtle_name_prefix", "turtle")

        self.spawn_frequency = self.get_parameter("spawn_frequency").value
        self.turtle_name_prefix = self.get_parameter("turtle_name_prefix").value
        self.turtle_counter = 0
        self.alive_turtles = []
        self.alive_turtles_publisher = self.create_publisher(TurtleArray, "alive_turtles", 10)
        self.spawn_turtle_timer = self.create_timer(1/self.spawn_frequency, self.spawn_new_turtle)
        self.catch_turtle_service = self.create_service(CatchTurtle, "catch_turtle", self.callback_catch_turtle)

    def callback_catch_turtle(self, request, response):
        self.call_kill_server(request.name)
        response.success = True
        return response

    def call_kill_server(self, turtle_name):
        client = self.create_client(Kill, "kill")
        while not client.wait_for_service(1):
            self.get_logger().info("Waiting for Kill Server...")

        request = Kill.Request()
        request.name = turtle_name

        future = client.call_async(request)
        future.add_done_callback(partial(self.callback_call_kill, turtle_name=turtle_name))
    
    def callback_call_kill(self, future,turtle_name):       
        try:
            future.result()
            for (idx, turtle) in enumerate(self.alive_turtles):
                if turtle.name == turtle_name:
                    del self.alive_turtles[idx]
                    self.publish_alive_turtles()
                    break
        except Exception as e:
            self.get_logger().warn(f"Service call for Kill {turtle_name} is failed.")

    def publish_alive_turtles(self):
        msg = TurtleArray()
        msg.turtles = self.alive_turtles
        self.alive_turtles_publisher.publish(msg)

    def spawn_new_turtle(self):
        self.turtle_counter += 1
        name = f"{self.turtle_name_prefix}{self.turtle_counter}"
        x = random.uniform(0.0, 11.0)
        y = random.uniform(0.0, 11.0)
        theta = random.uniform(0.0, 2*math.pi)

        self.call_spawn_server(name, x, y, theta)

    def call_spawn_server(self, turtle_name, x, y, theta):
        client  = self.create_client(Spawn, "spawn")
        while not client.wait_for_service(1.0):
            self.get_logger().warn("Waiting for Server Add Two Ints...")

        request = Spawn.Request()
        request.x = x
        request.y = y
        request.theta = theta
        request.name = turtle_name

        future = client.call_async(request)
        future.add_done_callback(partial(self.callback_call_spawn, turtle_name=turtle_name, x=x, y=y, theta=theta))
    
    def callback_call_spawn(self, future, turtle_name, x, y, theta):
        try:
            response = future.result()
            if response.name != "":
                self.get_logger().info(f"Turtle {response.name} is now alive")
                new_turtle = Turtle()
                new_turtle.name = response.name
                new_turtle.x = x
                new_turtle.y = y
                new_turtle.theta = theta
                self.alive_turtles.append(new_turtle)
                self.publish_alive_turtles()

            else:
                self.get_logger().warn(f"Service call to spawn {turtle_name} had not been successfull")

        except Exception as e:
            self.get_logger().error(f"Service call failed: {e}")

def main(args = None):

    rclpy.init(args = args)
    node = TurtleSpawner()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == "__main__":
    main()