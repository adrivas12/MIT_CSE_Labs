/*Write a concurrent TCP daytime server ‘C’ program. Along with the result, server
should also send the process id to the client.*/
//CLIENT CODE: 

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int len, result, sockfd, n=1, size; 
	struct sockaddr_in address; 
	int buf[256], arr[256];
	int p_id; 

	//Create a socket for the client
	sockfd=socket(AF_INET, SOCK_STREAM, 0); 

	//Name the socket as agreed with the server
	address.sin_family=AF_INET;
	address.sin_addr.s_addr=inet_addr("172.16.59.50"); 
	address.sin_port=htons(10200); 
	len=sizeof(address); 

	//Connect your socket to the server's socket
	result=connect(sockfd,(struct sockaddr *)&address,len);
	if(result==-1)
	{
		perror("\nCLIENT ERROR");
		exit(1);
	}

	//You can now read and write via sockfd (Logic for problem mentioned here)
	printf("Enter the size of the array: \n"); 
	scanf("%d", &size); 
	printf("\nEnter array of integers\n");
	for(int i=0; i<size; i++)
	{
		printf("Enter element %d: ", i); 
		scanf("%d", &arr[i]); 
	}
	printf("\nScanned\n"); 
	send(sockfd, &size, sizeof(size), 0); 
	send(sockfd,arr,sizeof(arr), 0);

	recv(sockfd, buf, sizeof(buf), 0); 
	recv(sockfd, &p_id, sizeof(p_id), 0); 

	printf("Sorted array is: "); 
	for(int i=0; i<size; i++)
	{
		printf("%d ", buf[i]); 
	}
	printf("\nProcess id is: %d", p_id); 
	close(buf); 
	close(sockfd); 
}
