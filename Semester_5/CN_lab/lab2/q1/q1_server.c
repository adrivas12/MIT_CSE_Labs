/*Write a concurrent TCP daytime server ‘C’ program. Along with the result, server
should also send the process id to the client.*/
//SERVER CODE: 

#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include <arpa/inet.h>
#include<netinet/in.h>
#include<stdlib.h>
#define PORTNO 10200

int main()
{
	int sockfd, newsockfd, portno, clilen, n=1; 
	struct sockaddr_in seraddr, cliaddr;
	int i, value; 

	sockfd=socket(AF_INET, SOCK_STREAM, 0); 
	seraddr.sin_family=AF_INET; 
	seraddr.sin_addr.s_addr=inet_addr("172.16.59.50"); 
	seraddr.sin_port=htons(PORTNO); 
	bind(sockfd, (struct sockaddr *)&seraddr, sizeof(seraddr)); 

	// Create a connection queue, ignore child exit details, and wait for clients
	listen(sockfd,5);
	while(1)
	{
		//Accept the connection
		clilen = sizeof(clilen);
		newsockfd=accept(sockfd,(struct sockaddr *)&cliaddr,&clilen);

		//Fork to create a process for this client and perform a test to see whether
		//you’re the parent or the child:
		if(fork()==0)
		{

		// If you’re the child, you can now read/write to the client on newsockfd.
			int p_id=getpid(); 
			int buf[256], m; 
			recv(newsockfd, &m,sizeof(m), 0);
			recv(newsockfd, buf,sizeof(buf), 0);
		
			//int m=sizeof(buf)/sizeof(buf[0]); 
			//for(int i=0; i<m; i++)
				//printf(" \nMessage from Client %d \n",buf[i]);
			for(int i = 0; i <m; i++)
			{
				for(int j = 0; j < m-i-1; j++)
				{
					if(buf[j]>buf[j+1])
					{
						int temp=buf[j]; 
						buf[j]=buf[j+1]; 
						buf[j+1]=temp; 
					}
				}
			}

			send(newsockfd,buf,sizeof(buf), 0);
			send(newsockfd, &p_id, sizeof(p_id), 0); 
			close(newsockfd);
			exit(0);
		}
		//Otherwise, you must be the parent and your work for this client is finished
		else
		close(newsockfd);
	}	
}