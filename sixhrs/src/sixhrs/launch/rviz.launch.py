
from launch_ros.actions import Node
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch.conditions import IfCondition
import os
from ament_index_python.packages import get_package_share_directory


def generate_launch_description():
    pkg_name = "sixhrs"
    share_dir = get_package_share_directory(pkg_name)

    # Launch argument for GUI
    use_gui = LaunchConfiguration('use_gui', default='true')

    # URDF path
    robot_urdf = os.path.join(share_dir, 'cube', 'robot.urdf')

    # Read URDF content
    try:
        with open(robot_urdf, "r") as file:
            robot_content = file.read()
    except FileNotFoundError:
        raise FileNotFoundError(f"URDF file not found: {robot_urdf}")

    robot_state_publisher_node = Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        name='robot_state_publisher',
        parameters=[
            {'robot_description': robot_content}
        ]
    )

    joint_state_publisher_node = Node(
        package='joint_state_publisher',
        executable='joint_state_publisher',
        name='joint_state_publisher'
    )

    joint_state_publisher_gui_node = Node(
        package='joint_state_publisher_gui',
        executable='joint_state_publisher_gui',
        name='joint_state_publisher_gui',
        condition=IfCondition(use_gui)
    )

    return LaunchDescription([
        DeclareLaunchArgument('use_gui', default_value='true', description='Launch joint_state_publisher with GUI'),
        robot_state_publisher_node,
        joint_state_publisher_node,
        joint_state_publisher_gui_node,
    ])
