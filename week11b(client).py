import socket

# Set up the client
def start_client(host='127.0.0.1', port=65432):
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client_socket.connect((host, port))

    # Send data to the server
    message = "Hello, Server!"
    client_socket.sendall(message.encode())

    # Receive data from the server
    data = client_socket.recv(1024)
    print(f"Received from server: {data.decode()}")

    # Close the connection
    client_socket.close()

if __name__ == "__main__":
    start_client()
