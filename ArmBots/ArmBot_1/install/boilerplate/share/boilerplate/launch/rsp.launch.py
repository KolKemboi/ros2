from launch.actions import ExecuteProcess
from launch_ros.actions import Node
from launch import LaunchDescription
import xacro
import os
from ament_index_python.packages import get_package_share_directory

def generate_launch_description():
    share_dir = get_package_share_directory("boilerplate")
    
    xacro_file = os.path.join(share_dir, "urdf", "arm.urdf.xacro")
    robot_urf = xacro.process_file(xacro_file).toxml()

    rsp_node = Node(
        package="robot_state_publisher",
        executable="robot_state_publisher",
        name="robot_state",
        parameters= [
            {"robot_description": robot_urf},
            {"use_sim_time": True}
        ],
        output="screen"
    )

    jsp_node = Node(
        package="joint_state_publisher",
        executable="joint_state_publisher",
        name="joint_state_pub",
        parameters=[
            {"use_sim_time": True},
        ],

        output="screen"
    )


    return LaunchDescription([
        rsp_node,
        jsp_node,
    ])
