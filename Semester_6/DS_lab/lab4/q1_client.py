# 1. Write a UDP time server to display the current time and day 

#Client Program 

import socket

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
udp_host = socket.gethostname()
udp_port = 9991
s.connect((udp_host, udp_port))

msg = "Give time!"
s.sendto(msg.encode(), (udp_host, udp_port))

tm, addr = s.recvfrom(1024)
print("Current time from Server:", tm.decode())
s.close()
