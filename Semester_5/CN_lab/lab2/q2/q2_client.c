/*Implement concurrent Remote Math Server To perform arithmetic operations in the
server and display the result to the client. The client accepts two integers and an
operator from the user and sends it to the server. The server then receives integers and
operator. The server will perform the operation on integers and sends the result back
to the client which is displayed on the client screen. Then both the processes
terminate.*/
//CLIENT CODE:

#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#define PORTNO 10200

int main()
{
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in address;
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = inet_addr("172.16.59.50");
	address.sin_port = htons(PORTNO);
	
	int result = connect(sockfd, (struct sockaddr*)&address, sizeof(address));
	
	if(result == -1){
		perror("\nClient Error");
		exit(0);
	}
	
	double operand1;
	double operand2;
	char operator;
	double answer;
	
	printf("\nEnter first operand: ");
	scanf(" %lf", &operand1);
	printf("Enter second operand: ");
	scanf(" %lf", &operand2);
	printf("Enter operator: ");
	scanf(" %c", &operator);
	
	send(sockfd, &operand1, sizeof(operand1), 0);
	send(sockfd, &operand2, sizeof(operand2), 0);
	send(sockfd, &operator, sizeof(operator), 0);
	recv(sockfd, &answer, sizeof(answer), 0);
	
	printf("\nResult is : %.2lf", answer);
	close(sockfd);
}