from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    ld = LaunchDescription()
    
    robots_name = [
        "giskard",
        "bb8",
        "dannel",
        "lander",
        "c3po"
    ]
    '''
    robot_news_station_nodes = []

    for name in robot_names:
        robot_news_station_nodes.append(Node(
            package = "my_py_pkg",
            executable = "robot_news_station",
            name = "robot_news_station" + name.lower(),
            parameters = [{"robot_name": name}]
        ))

    for node in robot_news_station_nodes:
        ld.add_action(node)
    '''

    for i in range(5):
        station_node = Node(
            package="my_py_pkg",
            executable="robot_news_station",
            name=f"robot_news_station_{robots_name[i]}",
            parameters=[
                {"robot_name": robots_name[i]}
            ]
        )

        ld.add_action(station_node)

    smartphone_node = Node(
        package="my_py_pkg",
        executable="smartphone"
    )

    ld.add_action(smartphone_node)
    return ld