import socket

# Set up the server
def start_server(host='127.0.0.1', port=65432):
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind((host, port))
    server_socket.listen(1)  # Only 1 connection at a time for simplicity
    print(f"Server listening on {host}:{port}...")

    # Accept a connection from the client
    conn, addr = server_socket.accept()
    print(f"Connected by {addr}")

    # Receive and send data to the client
    data = conn.recv(1024)  # Receive up to 1024 bytes
    print(f"Received from client: {data.decode()}")

    # Send data back to the client
    message = "Hello, Client!"
    conn.sendall(message.encode())

    # Close the connection
    conn.close()

if __name__ == "__main__":
    start_server()
