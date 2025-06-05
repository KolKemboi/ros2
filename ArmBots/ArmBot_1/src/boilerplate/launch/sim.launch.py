import os
from ament_index_python.packages import get_package_share_directory

from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch_ros.substitutions import FindPackageShare
from launch_ros.actions import Node
import xacro


def generate_launch_description():
    pkg_share_dir = get_package_share_directory("boilerplate")

    xacro_file = os.path.join(pkg_share_dir, "urdf", "armbot.urdf.xacro")

    robot_urdf = xacro.process_file(xacro_file).toxml()

    gz_server = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([
            PathJoinSubstitution([
            FindPackageShare('gazebo_ros'),
            'launch',
            "gzserver.launch.py"])

        ]),
        launch_arguments = {
            'pause': 'false'
        }.items()
    )

