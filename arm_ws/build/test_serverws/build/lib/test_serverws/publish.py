import asyncio
import websockets
import rclpy

from std_msgs.msg import String
from rclpy.qos import QoSProfile

# Declare the publisher as a global variable
publisher = None

async def handle_client(websocket, path):
    global publisher  # Declare that you are using the global variable

    while True:
        try:
            # Wait for message from client
            message = await websocket.recv()
            print(f"Received message from client: {message}")

            # Publish message to ROS 2 topic
            publisher.publish(String(data=message))
        except websockets.ConnectionClosed:
            print("Client disconnected")
            break

def ros_callback(msg):
    print(f"Received message from ROS 2: {msg.data}")

async def ros_to_ws():
    global publisher  # Declare that you are using the global variable

    # Initialize ROS 2 node
    rclpy.init()
    node = rclpy.create_node('publisws')

    # Create ROS 2 publisher
    publisher = node.create_publisher(String, 'ros_topic', QoSProfile(depth=10))

    # Start WebSocket server
    start_server = websockets.serve(handle_client, "localhost", 8000)

    print("WebSocket server starting...")

    # Run both ROS 2 and WebSocket server concurrently
    executor = rclpy.executors.MultiThreadedExecutor()
    executor.add_node(node)
    executor.create_task(start_server)

    try:
        executor.spin()
    finally:
        executor.shutdown()
        rclpy.shutdown()

def main():
    try:
        asyncio.run(ros_to_ws())
    except KeyboardInterrupt:
        pass

if __name__ == "__main__":
    main()
