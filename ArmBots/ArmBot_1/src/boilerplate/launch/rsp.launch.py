
import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.substitutions import LaunchConfiguration, Command
from launch.actions import DeclareLaunchArgument
from launch_ros.actions import Node

import xacro

def generate_launch_description():
    use_sim_time = LaunchConfiguration("use_sim_time")
    use_ros2_cont = LaunchConfiguration("use_ros2_control")
    pkg_path = os.path.join(get_package_share_directory("boilerplate"))
    xacro_file = os.path.join(pkg_path, "urdf", "arm.urdf.xacro")

    robot_descr_conf = Command(['xacro ', xacro_file, " use_ros2_control:=", use_ros2_cont, " sim_mode:=", use_sim_time])

    params = {'robot_description': robot_descr_conf, "use_sim_time": use_sim_time}

    rsp_node = Node(
        package="robot_state_publisher",
        executable="robot_state_publisher",
        output= "screen",
        parameters=[params]
    )

    return LaunchDescription([
       DeclareLaunchArgument(
            'use_sim_time',
            default_value='false',
            description='Use sim time if true'),
        DeclareLaunchArgument(
            'use_ros2_control',
            default_value='true',
            description='Use ros2_control if true'), rsp_node
    ])
