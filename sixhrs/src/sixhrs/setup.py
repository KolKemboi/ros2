
from setuptools import setup

package_name = 'sixhrs'

setup(
    name=package_name,
    version='0.0.1',
    packages=[package_name],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='Kol',
    maintainer_email='kol@example.com',
    description='A simple ROS 2 package for visualizing a cube in RViz.',
    license='Apache-2.0',
    entry_points={
        'console_scripts': [
            'launch_cube = sixhrs.launch_file_name:generate_launch_description',
        ],
    },
)
