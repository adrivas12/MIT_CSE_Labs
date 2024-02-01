#Server program 

import socket 

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM) #for UDP
udp_host = socket.gethostname()
udp_port = 12345
sock.bind((udp_host, udp_port))
while True: 
	print ("Waiting for Client..")
	data, addr = sock.recvfrom(1024)
	print ("Received Messages: ", data.decode(), " from ", addr )