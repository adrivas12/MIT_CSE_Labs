/*Write a concurrent TCP daytime server ‘C’ program. Along with the result, server 
should also send the process id to the clilen.*/
//Server Code

#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <time.h>
#define PORTNO 10200

int main()
{
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in serveraddress;
	serveraddress.sin_family = AF_INET;
	serveraddress.sin_addr.s_addr = inet_addr("172.16.59.27");
	serveraddress.sin_port = htons(PORTNO);
	
	bind(sockfd, (struct sockaddr*)&serveraddress, sizeof(serveraddress));
	listen(sockfd, 5);
	
	while(1)
	{
		struct sockaddr_in cliaddr;
		int clilen = sizeof(cliaddr);
		int newsockfd = accept(sockfd, (struct sockaddr*)&cliaddr, &clilen);
		
		int parent_id = fork();
		
		if(parent_id == 0)
		{
			char time_str[50];
			time_t current_time;  // time_t is a data type that represents calendar time
			struct tm *time_info; // holds components of the calendar time like day, month, year. Used to convert time_t into readable format
			time(&current_time);
			time_info = localtime(&current_time);
			
			strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", time_info); // Converts time into a string
			
			int p_id = getpid();
			send(newsockfd, time_str, sizeof(time_str), 0);
			send(newsockfd, &p_id, sizeof(p_id), 0);
			
			close(newsockfd);
			exit(0);					
		}
		else
		{
			wait(NULL);
		}
	}
	close(sockfd);
}