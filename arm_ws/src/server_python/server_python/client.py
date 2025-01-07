import rclpy
from rclpy.node import Node
from custom_msgs.srv import AddVariable
import sys

class ServiceClient(Node):
    def __init__(self,a,b):
        super().__init__('service_client')
        self.client_ = self.create_client(AddVariable, "add_Variable")
        self.get_logger().info("Service ready to serve")
    
        while not self.client_.wait_for_service(timeout_sec = 1.0):
            self.get_logger().info("Waiting for service")

        self.request_ = AddVariable.Request()
        self.request_.a = a
        self.request_.b = b
        self.future_ = self.client_.call_async(self.request_)
        self.future_.add_done_callback(self.ResponseCallback)

    def ResponseCallback(self, future):
        self.get_logger().info("Response callback result %d "% future.result().sum)

def main():
    rclpy.init()
    if len(sys.argv) != 3:
        print("wron number of arguments, A and B")
        return -1
    service_client = ServiceClient(int (sys.argv[1]), int (sys.argv[2]))
    rclpy.spin(service_client)
    service_client.destroy_node()
    rclpy.shutdown()
     

if __name__ == "__main__":
    main()
        