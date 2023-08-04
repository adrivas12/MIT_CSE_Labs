/*To illustrate encryption and decryption of messages using TCP. The client accepts
messages to be encrypted through standard input device. The client will encrypt the string
by adding 4(random value) to ASCII value of each alphabet. The encrypted message is
sent to the server. The server then decrypts the message and displays both encrypted and
decrypted forms of the string. Program terminates after one session.*/

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

		//Read, Write and Decryption 
		n = read(newsockfd,buf,sizeof(buf));
		printf(" \nMessage from Client: %s \n",buf);
		for(int i=0; i<strlen(buf); i++)
		{
			buf[i]-=4; 
		}
		printf("Decrypted message: %s\n", buf); 
		n = write(newsockfd,buf,sizeof(buf));
	}
}

