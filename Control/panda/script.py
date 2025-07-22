#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
import tf2_ros
from tf2_ros import TransformException
from geometry_msgs.msg import TransformStamped
from tf_transformations import euler_from_quaternion
import time

class PandaTfDumper(Node):
    def __init__(self):
        super().__init__('panda_tf_dumper')
        self.tf_buffer = tf2_ros.Buffer()
        self.tf_listener = tf2_ros.TransformListener(self.tf_buffer, self)

        # Wait time to ensure TF tree is available
        self.timer = self.create_timer(5.0, self.dump_all_link_poses)

        # All panda links (edit here if needed)
        self.links = [
            'base_link',
            'panda_link1', 'panda_link2', 'panda_link3',
            'panda_link4', 'panda_link5', 'panda_link6', 'panda_link7', 'panda_link8',
            'panda_hand', 'panda_leftfinger', 'panda_rightfinger'
        ]
        self.output_file = 'panda_link_poses.txt'

    def dump_all_link_poses(self):
        self.get_logger().info("Collecting TF transforms relative to 'world'...")

        with open(self.output_file, 'w') as f:
            for link in self.links:
                try:
                    now = rclpy.time.Time()
                    trans: TransformStamped = self.tf_buffer.lookup_transform(
                        'world', link, now, timeout=rclpy.duration.Duration(seconds=1.0))

                    translation = trans.transform.translation
                    rotation = trans.transform.rotation

                    # Convert quaternion to RPY
                    rpy = euler_from_quaternion([
                        rotation.x,
                        rotation.y,
                        rotation.z,
                        rotation.w
                    ])

                    line = (
                        f"{link}: XYZ = [{translation.x:.4f} {translation.y:.4f} {translation.z:.4f}], "
                        f"RPY = [{rpy[0]:.4f} {rpy[1]:.4f} {rpy[2]:.4f}]\n"
                    )
                    f.write(line)

                except TransformException as e:
                    self.get_logger().warn(f"Could not transform {link}: {e}")
        
        self.get_logger().info(f"Link poses saved to {self.output_file}")
        self.destroy_node()

def main():
    rclpy.init()
    node = PandaTfDumper()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
