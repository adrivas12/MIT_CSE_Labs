# 2. Write a UDP simple chat program for message send and receive

#Server program 

import socket

HOST = '172.16.59.12'
PORT = 7878 
s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
s.bind((HOST, PORT))
print("\nWaiting for incoming connections...\n")
while True:
    data, addr = s.recvfrom(1024)
    print("Received message from", addr[0], "(", addr[1], ")")
    s_name = data.decode()
    print(s_name, "has connected to the chat room")
    
    name = input("Enter your name: ")
    s.sendto(name.encode(), addr)
    
    while True:
        message = input("Me: ")
        if message == "[e]":
            message = "Left chat room!"
            s.sendto(message.encode(), addr)
            print("\n")
            break
        s.sendto(message.encode(), addr)
        message, addr = s.recvfrom(1024)
        message = message.decode()
        print(f"{s_name}: {message}")

# Close the socket
s.close()
