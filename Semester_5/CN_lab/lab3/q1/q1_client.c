//Client Code

#include "PreProcessorD.h"

int main()
{
	int sockfd; 
	struct sockaddr_in address; 
	address.sin_family=AF_INET; 
	address.sin_addr.s_addr=inet_addr("172.16.59.27"); 
	address.sin_port=htons(9704); 

	int len=sizeof(address); 
	int m, n;
	printf("\nEnter the number of rows and columns: "); 
	scanf("%d", &n); 
	scanf("%d", &m);

	int a= sendto(sockfd, (int *)&n, sizeof(n), 0, (struct sockaddr *)&address,len);  
	int b=sendto(sockfd, (int *)&m, sizeof(m), 0, (struct sockaddr *)&address,len); 
	printf("Enter the elements: "); 
	for(int i=0; i<n; i++)
	{
		int buf[m]; 
		for(int j=0; j<m; j++)
		{
			printf("Enter the element: %d for row %d\n",j,i );
			scanf("%d", &buf[j]); 
		}
		int c=sendto(sockfd, buf, sizeof(buf), 0, (struct sockaddr *)&address,len); 
	}

	printf("\nMatrix received: "); 
	int rec[n][m];
	int d=recvfrom(sockfd, rec, sizeof(rec), 0, (struct sockaddr *)&address, &len);
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			printf("%d ", rec[i][j]);
			printf("\n"); 
		}
	}
	close(sockfd); 
	return 0; 
}