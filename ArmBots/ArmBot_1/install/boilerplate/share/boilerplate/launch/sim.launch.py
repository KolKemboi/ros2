import os
from ament_index_python.packages import get_package_share_directory

from launch import LaunchDescription
from launch.actions import ExecuteProcess, IncludeLaunchDescription, RegisterEventHandler, TimerAction
from launch.event_handlers import OnProcessExit
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import PathJoinSubstitution
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare

def generate_launch_description():
    share_dir = get_package_share_directory("boilerplate")

    rsp_launch_source = PythonLaunchDescriptionSource([
        os.path.join(share_dir, "launch", "rsp.launch.py")
    ])

    rsp_launch = IncludeLaunchDescription(
        rsp_launch_source,
        launch_arguments={'use_sim_time': "true", "use_ros2_control": "true"}.items()
    )

    gz_server = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([
            PathJoinSubstitution([
                FindPackageShare('gazebo_ros'),
                'launch',
                'gzserver.launch.py'
            ])
        ])
    )

    gz_client = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([
            PathJoinSubstitution([
                FindPackageShare('gazebo_ros'),
                'launch',
                'gzclient.launch.py'
            ])
        ])
    )

    gz_robot_spawn = Node(
        package="gazebo_ros",
        executable="spawn_entity.py",
        arguments=[
            '-entity', "armbot",
            "-topic", "robot_description"
        ],
        output="screen"
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

    load_controllers = RegisterEventHandler(
        OnProcessExit(
            target_action=gz_robot_spawn,
            on_exit=[
                joint_state_broadcaster,
                joint_trajectory_controller
            ]
        )
    )

    delayed_spawn = TimerAction(
        period=3.0,
        actions=[gz_robot_spawn]
    )

    return LaunchDescription([
        rsp_launch,
        gz_server,
        gz_client,
        delayed_spawn,
        load_controllers,
    ])
