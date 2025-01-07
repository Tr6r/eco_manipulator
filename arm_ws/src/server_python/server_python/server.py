import rclpy
from rclpy.node import Node
from custom_msgs.srv import AddVariable

class ServiceServer(Node):
    def __init__(self):
        super().__init__('service_server')
        self.service_ = self.create_service(AddVariable, "add_Variable",self.serviceCallback)
        self.get_logger().info("Service ready to serve")
    
    def serviceCallback(self, request, response):
        self.get_logger().info("new messge get %d and %d" %(request.a, request.b))
        response.sum = request.a + request.b
        return response
    
def main():
    rclpy.init()
    service_server = ServiceServer()
    rclpy.spin(service_server)
    service_server.destroy_node()
    rclpy.shutdown()

if __name__ == "__main__":
    main()
        