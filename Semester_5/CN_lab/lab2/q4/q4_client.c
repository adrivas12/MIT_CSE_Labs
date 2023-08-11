/*Write a concurrent TCP client-server ‘C’ program where the client accepts a
sentence from the user and sends it to the server. The server will check for
duplicate words in the string. Server will find the number of occurrences of
duplicate words present and remove the duplicate words by retaining single
occurrence of the word and send the resultant sentence to the client. The client
displays the received data on the client screen. The process repeats until the user
enters the string “Stop”. Then both processes terminate.*/

//CLIENT CODE: 

#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>

int main()
{
	char buff[256];
	int n = 1;

	while(1)
	{
		int socket_id = socket(AF_INET, SOCK_STREAM, 0);
		struct sockaddr_in address;
		address.sin_family = AF_INET;
		address.sin_addr.s_addr = inet_addr("172.16.59.50");
		address.sin_port = htons(10200);
		int result = connect(socket_id, (struct sockaddr*)&address, sizeof(address));
		
	    if(result == -1)
	    {
			perror("\nClient Error");
			exit(1);
		} 
			
		char str[256];
		printf("\nEnter String: ");
		scanf("%s", str);
		
		if(strcmp(str, "Stop") == 0)
			exit(1);
		
		write(socket_id, str, sizeof(str)); 
		
		read(socket_id, buff, sizeof(buff));
		puts(buff);
		close(socket_id);
	}		
}	