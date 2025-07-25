from launch import LaunchDescription
from launch_ros.actions import Node
from launch.launch_description_sources import PythonLaunchDescriptionSource
from ament_index_python.packages import get_package_share_directory
import os

def generate_launch_description():
    return LaunchDescription([
        Node(
            package= "turtlesim",
            executable= "turtlesim_node",
            name= "turtlesim_node",
            output= "screen"
        ),
    ])
