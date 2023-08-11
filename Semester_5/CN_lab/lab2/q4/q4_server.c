/*Write a concurrent TCP client-server ‘C’ program where the client accepts a
sentence from the user and sends it to the server. The server will check for
duplicate words in the string. Server will find the number of occurrences of
duplicate words present and remove the duplicate words by retaining single
occurrence of the word and send the resultant sentence to the client. The client
displays the received data on the client screen. The process repeats until the user
enters the string “Stop”. Then both processes terminate.*/

//SERVER CODE: 

#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include <arpa/inet.h>
#include<netinet/in.h>
#include<stdlib.h>
#define PORTNO 10200


int isPresent(char ch, char character[], int index)
{
	for(int i = 0; i < strlen(character); i++)
	{
		if(i == index)
			continue;
		else if(ch == character[i])
			return 1;	
	} 
	return 0;
}
int count(char ch, char buffer[])
{
	int occurences = 0;
	for(int i = 0; i < strlen(buffer); i++)
	{
		if(ch == buffer[i])
			occurences++;
	}
	return occurences;
}

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
			char buf[256], result[256], character[256];
			int n = 1, ind = 0, unique_count = 0, countf = 0;
			int frequency[256];
		
			read(newsockfd, buf,sizeof(buf));

			if(strcmp(buf, "Stop") == 0)
			break;
		 	
			for(int i = 0; i < 256; i++)
			{
				frequency[i] = 0;
				character[i] = '\0';
				result[i] = '\0';
				
			}
			for(int i = 0; i < strlen(buf); i++)
			{
				if(isPresent(buf[i], character, i) == 1)
				{
					character[i] = '$';
					frequency[i] = -1;
				}	
				else
				{
					frequency[i] = count(buf[i], buf);
					character[i] = buf[i];
					result[unique_count] = character[i];
					printf("%c", character[0]);
					unique_count++;
				}	
			}
			
			
			write(newsockfd,result,sizeof(result));
			write(newsockfd, &p_id, sizeof(p_id)); 
			pclose(newsockfd);
			exit(0);
		}
		//Otherwise, you must be the parent and your work for this client is finished
		else
		pclose(newsockfd);
	}	
}