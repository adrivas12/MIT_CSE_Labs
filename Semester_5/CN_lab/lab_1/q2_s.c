/*Where the client accepts a sentence from the user and sends it to the server. The server
will check for duplicate words in the string. Server will find number of occurrences of
duplicate words present and remove the duplicate words by retaining single occurrence of
the word and send the resultant sentence to the client. The client displays the received
data on the client screen. The process repeats until the user enter the string “Stop”. Then
both the processes terminate.*/

//Incomplete

#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#define PORTNO 10200

int main()
{
	int sockfd,newsockfd,portno,clilen,n=1;
	struct sockaddr_in seraddr,cliaddr;
	int i,value;

	// create an unnamed socket for the server
	sockfd = socket(AF_INET,SOCK_STREAM,0);

	//Name the socket
	seraddr.sin_family = AF_INET;
	seraddr.sin_addr.s_addr = inet_addr("172.16.59.27");// **
	seraddr.sin_port = htons(PORTNO);
	bind(sockfd,(struct sockaddr *)&seraddr,sizeof(seraddr));

	//Create a connection queue and wait for clients
	listen(sockfd,5);
	while (1) 
	{
		char buf[256];
		printf("server waiting");

		//Accept a connection
		clilen = sizeof(clilen);
		newsockfd=accept(sockfd,(struct sockaddr *)&cliaddr,&clilen);

		//Read, Write and delete the duplicates 
		n = read(newsockfd,buf,sizeof(buf));
		printf(" \nMessage from Client %s \n",buf);
		

		printf("\nDecrypted message: %s\n", buf); 
		n = write(newsockfd,buf,sizeof(buf));
	}
}

