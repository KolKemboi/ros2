from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from ament_index_python.packages import get_package_share_directory
import os

def generate_launch_description():
    return LaunchDescription([
        Node(
            package="ps5",
            executable="cust_pub",
            name="pub",
            output="screen",
        ),
        Node(
            package="ps5",
            executable="cust_sub",
            name="sub",
            output="screen",
        ),
        Node(
            package="turtlesim",
            executable="turtlesim_node",
            name="Turtle",
            output="screen",
        ),
        Node(
            package="rqt_graph",
            executable="rqt_graph",
            output="screen",
        ),
        Node(
            package="rviz2",
            executable="rviz2",
            output="screen",
        ),
    ])