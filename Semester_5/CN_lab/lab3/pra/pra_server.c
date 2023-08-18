#include "PreProcessorD.h"

int main()
{
	int sockfd;
	char buf[25]; 
	struct sockaddr_in sockaddr, cliaddr;
	sockfd=socket(AF_INET, SOCK_DGRAM, 0); 

	//Construct the address for use with sendto/recvfrom
	sockaddr.sin_family=AF_INET; 
	sockaddr.sin_addr.s_addr=inet_addr("172.16.59.27"); 
	sockaddr.sin_port=htons(9704); 

	int result=bind(sockfd, (struct sockaddr *)&sockaddr, sizeof(sockaddr)); 
	int clilen=sizeof(cliaddr); 
	int m=recvfrom(sockfd, buf, sizeof(buf), 0, (struct sockaddr *)&cliaddr, &clilen);
	printf("The server send is\n"); 
	puts(buf); 
	int n=sendto(sockfd, buf, sizeof(buf), 0, (struct sockaddr *)&cliaddr, clilen); 
	return 0; 
}