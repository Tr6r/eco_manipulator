import os
from os import pathsep
from ament_index_python import get_package_share_directory,get_package_prefix

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, SetEnvironmentVariable, IncludeLaunchDescription
from launch.substitutions import Command, LaunchConfiguration

from launch_ros.actions import Node
from launch_ros.parameter_descriptions import ParameterValue
from launch.launch_description_sources import PythonLaunchDescriptionSource

def generate_launch_description():
    arm_mark1 = get_package_share_directory("arm_mark1")
    arm_mark1_prefix = get_package_prefix('arm_mark1')

    model_path = os.path.join(arm_mark1,"models")
    model_path += pathsep +  os.path.join(arm_mark1_prefix, "share")
    
    env_variable = SetEnvironmentVariable("GAZEBO_MODEL_PATH",model_path)


    model_arg = DeclareLaunchArgument(name="model",default_value=os.path.join(
                                                    arm_mark1,'urdf','arm.urdf.xacro'
                                                    ),
                                                    description="Absolute path to robot urdf file")
    
    arm_mark1_description = ParameterValue(Command(['xacro ', LaunchConfiguration('model')]),
                                           value_type=str)

    robot_state_publisher_node = Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        parameters=[{'robot_description':arm_mark1_description}]
    )
    start_gazebo_server = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(os.path.join(get_package_share_directory("gazebo_ros"),"launch","gzserver.launch.py"))
    )   

    start_gazebo_client = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(os.path.join(get_package_share_directory("gazebo_ros"),"launch","gzclient.launch.py"))
    )
    
    spawn_robot = Node(
        package="gazebo_ros",
        executable="spawn_entity.py",
        arguments=["-entity","arm","-topic","robot_description"],
        output="screen"

    )

    return LaunchDescription([
        env_variable,
        model_arg,
        robot_state_publisher_node,
        start_gazebo_server,
        start_gazebo_client,
        spawn_robot
    ])
