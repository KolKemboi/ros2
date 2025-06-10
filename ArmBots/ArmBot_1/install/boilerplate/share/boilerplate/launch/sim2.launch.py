import os
from ament_index_python import get_package_share_directory
from launch import LaunchDescription
from launch.actions import ExecuteProcess, IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch_ros.actions import Node

def generate_launch_description():
    pkg_name = 'boilerplate'

    rsp = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([os.path.join(
            get_package_share_directory(pkg_name), 'launch', 'rsp2.launch.py'
        )]), launch_arguments={'use_sim_time': 'true', 'use_ros2_control': 'true'}.items()
    )

    gazebo = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([os.path.join(
            get_package_share_directory('gazebo_ros'), 'launch', 'gazebo.launch.py'
        )])
    )

    spawn_entt = Node(
        package='gazebo_ros', 
        executable='spawn_entity.py',
        arguments=['-topic', 'robot_description',
                   '-entity', 'arm'],
        output = 'screen'
    )

    joint_state_broadcaster = ExecuteProcess(
        cmd=[
            "ros2", "control", "load_controller", "--set-state", "active", "joint_state_broadcaster"
        ],
        output="screen"
    )

    joint_trajectory_controller = ExecuteProcess(
        cmd=[
            "ros2", "control", "load_controller", "--set-state", "active", "Arm_Controller"
        ],
        output="screen"
    )
    return LaunchDescription([
        rsp,
        gazebo,
        spawn_entt,
        joint_state_broadcaster,
        joint_trajectory_controller,
    ])
