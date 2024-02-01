#2A)Write a program to create TCP time server in Python

#Client Program 

import socket
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
host = socket.gethostname()
port = 9991
s.connect((host, port))
tm = s.recv(1024)
print(' Current time from Sever :', tm.decode())
s.close()