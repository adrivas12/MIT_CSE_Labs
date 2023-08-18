//Client Code 

#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#define PORTNO 10200

int main()
{
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in address;
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = inet_addr("172.16.59.27");
	address.sin_port = htons(PORTNO);
	
	int result = connect(sockfd, (struct sockaddr*)&address, sizeof(address));
	
	if(result == -1)
	{
		perror("\nClient Error");
		exit(0);
	}
	
	int p_id;
	char time_str[50];
	recv(sockfd, time_str, sizeof(time_str), 0);
	recv(sockfd, &p_id, sizeof(p_id), 0);
	
	printf("\nTime is : %s", time_str);
	printf("\nProcess ID: %d", p_id);
	close(sockfd);
}