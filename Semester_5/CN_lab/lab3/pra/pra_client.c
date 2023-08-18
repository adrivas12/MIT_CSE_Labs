#include "PreProcessorD.h"

int main()
{
	int sockfd; 
	struct sockaddr_in address; 
	address.sin_family=AF_INET; 
	address.sin_addr.s_addr=inet_addr("172.16.59.27"); 
	address.sin_port=htons(9704); 

	char buf[25], buf1[25]; 
	printf("Enter buf\n"); 
	gets(buf); 
	int len=sizeof(address); 
	int m=sendto(sockfd, buf, sizeof(buf), 0, (struct sockaddr *)&address, len); 
	int n=recvfrom(sockfd, buf, sizeof(buf), 0, (struct sockaddr *)&address, &len);
	printf("The server echo is\n");
	puts(buf); 
	return 0; 
}