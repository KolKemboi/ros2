from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    cust_pub = Node(
        package="ps9",
        executable="cust_pub",
        name="Publisher",
        output="screen",
    )
    cust_sub = Node(
        package="ps9",
        executable="cust_sub",
        name="Subscriber",
        output="screen",
    )
    turtle_node = Node(
        package="turtlesim",
        executable="turtlesim_node",
        name="TurtleNode",
        output="screen",
    )
    rqt_node = Node(
        package="rqt_graph",
        executable="rqt_graph",
        output="screen",
    )
    return LaunchDescription([
        cust_sub,
        cust_pub,
        turtle_node,
        rqt_node,
    ])
