/*Implement concurrent Remote Math Server To perform arithmetic operations in the
server and display the result to the client. The client accepts two integers and an
operator from the user and sends it to the server. The server then receives integers and
operator. The server will perform the operation on integers and sends the result back
to the client which is displayed on the client screen. Then both the processes
terminate.*/
//SERVER CODE: 

#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/socket.h>
#define PORTNO 10200

int main(){
	int socketfd = socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in address;
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = inet_addr("172.16.59.50");
	address.sin_port = htons(PORTNO);
	
	bind(socketfd, (struct sockaddr*)&address, sizeof(address));
	listen(socketfd, 5);
	
	while(1){
		struct sockaddr_in clientaddress;
		int client = sizeof(clientaddress);
		int newsocketfd = accept(socketfd, (struct sockaddr*)&clientaddress, &client);
		
		int parent_id = fork();
		
		if(parent_id == 0){
			double operand1;
			double operand2;
			char operator;
			double answer;
			
			recv(newsocketfd, &operand1, sizeof(operand1), 0);
			recv(newsocketfd, &operand2, sizeof(operand2), 0);
			recv(newsocketfd, &operator, sizeof(operator), 0);
			
			if(operator == '+')
				answer = operand1 + operand2;
			else if(operator == '-')
				answer = operand1 - operand2;
			else if(operator == '*')
				answer = operand1 * operand2;
			else if(operator == '/')
				answer = operand1 / operand2;
			
			send(newsocketfd, &answer, sizeof(answer), 0);
			printf("%lf", answer);
			close(newsocketfd);
			exit(0);					
		}
		
		else{
			wait(NULL);
		}
	}
	close(socketfd);
}