# 1. Write a UDP time server to display the current time and day 

#Server Program 

import socket
import time

serversocket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
udp_host = socket.gethostname()
udp_port = 9991
serversocket.bind((udp_host, udp_port))

while True:
    data, addr = serversocket.recvfrom(1024)
    print("Received Message:", data.decode(), "from", addr)
    print("Got a connection from", str(addr))
    
    currentTime = time.ctime(time.time()) + "\r\n"
    serversocket.sendto(currentTime.encode('ascii'), addr)
