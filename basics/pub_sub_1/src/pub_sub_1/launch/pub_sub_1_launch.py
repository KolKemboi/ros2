from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from ament_index_python.packages import get_package_share_directory
import os

def generate_launch_description():
    return LaunchDescription([
        Node(
            package= "pub_sub_1",
            executable= "cust_pub",
            name= "My_Own_Publisher_In_Cpp",
            output= "screen",
        ),
        Node(
            package= "pub_sub_1",
            executable= "cust_sub",
            name= "My_Own_Subscriber_In_Cpp",
            output= "screen",
        ),
        Node(
            package= "turtlesim",
            executable= "turtlesim_node",
            name= "Turtle",
            output= "screen",
        )
    ])
