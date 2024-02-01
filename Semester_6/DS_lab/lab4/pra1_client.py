#1A) Write a program where client can send a message to the server and the 
#server can receive the message and send, or echo it back to the client

#Client program

import socket
HOST = '127.0.0.1' # The server's hostname or IP address
PORT = 2053

# The port used by the server
with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
	s.connect((HOST, PORT))
	s.sendall(b"Hello, world")
	data = s.recv(1024)
	print("Received Connection")
	print("Server:", data.decode())