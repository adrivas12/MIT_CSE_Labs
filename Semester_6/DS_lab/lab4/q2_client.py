# 2. Write a UDP simple chat program for message send and receive

#Client program 

import socket

HOST = "172.16.59.12"
PORT = 7878
s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

name = input("Enter your name: ")
name = "hello"
s.sendto(name.encode(), (HOST, PORT))
s_name, addr = s.recvfrom(1024)
s_name = s_name.decode()
print(s_name, "has joined the chat room\nEnter [e] to exit chat room\n")

while True:
    message = input("Me: ")
    if message == "[e]":
        message = "Left chat room!"
        s.sendto(message.encode(), (HOST, PORT))
        print("\n")
        break
    s.sendto(message.encode(), (HOST, PORT))
    message, addr = s.recvfrom(1024)
    message = message.decode()
    print(f"{s_name}: {message}")
s.close()
