import launch
from launch import LaunchDescription
from launch.actions import ExecuteProcess, IncludeLaunchDescription, RegisterEventHandler
from launch.event_handlers import (OnProcessStart, OnProcessExit)
from launch.launch_description_sources import PythonLaunchDescriptionSource

from launch_ros.actions import Node

def generate_launch_description():
    image_subscriber_node = Node(
        package = "gesture_recognition",
        executable = "image_subscriber_node",
        name = "image_subscriber_node"
    )

    image_publisher_node = Node(
        package = "gesture_recognition",
        executable = "image_publisher_node",
        name = "image_publisher_node"
    )

    return LaunchDescription([
        image_publisher_node, 
        image_subscriber_node,
    ])