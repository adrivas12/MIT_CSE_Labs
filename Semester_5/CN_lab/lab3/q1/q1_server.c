/*Write a UDP client-server program where t he client sends rows of a matrix, and the
servercombines them together as a matrix.*/
//Server Code

#include "PreProcessorD.h"

int main()
{
	int sockfd;
	struct sockaddr_in sockaddr, cliaddr;
	sockfd=socket(AF_INET, SOCK_DGRAM, 0); 

	//Construct the address for use with sendto/recvfrom
	sockaddr.sin_family=AF_INET; 
	sockaddr.sin_addr.s_addr=inet_addr("172.16.59.27"); 
	sockaddr.sin_port=htons(9704); 

	int result=bind(sockfd, (struct sockaddr *)&sockaddr, sizeof(sockaddr)); 
	int clilen=sizeof(cliaddr);

	int m, n; 
	int a=recvfrom(sockfd, (int*)&n, sizeof(n), 0, (struct sockaddr *)&cliaddr, &clilen); 
	int b=recvfrom(sockfd, (int*)&m, sizeof(m), 0, (struct sockaddr *)&cliaddr, &clilen); 
	int buf[n][m]; 
	printf("Hello world\n");
	for(int i=0; i<n; i++)
	{
		int temp[m]; 
		recvfrom(sockfd, temp, sizeof(temp), 0, (struct sockaddr *)&cliaddr, &clilen); 
		for(int j=0; j<m; j++)
		{
			buf[i][j]=temp[j];  
		}
	}
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			printf("%d ", buf[i][j]);
			printf("\n"); 
		}
	}
	sendto(sockfd, buf, sizeof(buf), 0, (struct sockaddr *)&cliaddr, clilen); 
	return 0; 
}