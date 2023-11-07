/*Consider the following snapshot of the system. Write C program to implement
Banker’s algorithm for deadlock avoidance. The program has to accept all inputs
from the user. Assume the total number of instances of A,B and C are 10,5 and 7
respectively.*/

#include <stdio.h>
#include <stdlib.h>

int check_if_finish(int arr[], int n)
{
	for(int i = 0; i<n; i++)
	{
		if(arr[i] == 0) return 1; 
	}
	return 0; 
}
int main(){
	int n, m; 
	printf ("Enter the number of processes and instances: "); 
	scanf("%d%d", &n, &m); 
	int allocation[n][m]; 
	printf("Enter allocation of each matrix: "); 
	for(int i =0; i<n; i++){
		for(int j = 0; j<m; j++){
			scanf("%d", &allocation[i][j]); 
		}
	}
	int max[n][m], need[n][m]; 
	printf("Enter Max matrix: "); 
	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++){
			scanf("%d", &max[i][j]); 
			need[i][j] = max[i][j] - allocation[i][j]; 
		}
	}
	int available[m]; 
	printf("Enter available: " );
	for(int i = 0; i<m; i++){
		scanf("%d", &available[i]); 
	}
	int finish[n];
	for(int i = 0; i<n; i++)
		finish[i] = 0;  


	int counter = 0; 
	while(check_if_finish(finish, n)){
		int truer = 1; 
		for(int j= 0; j<m; j++){
			if(need[counter][j]>available[j]) truer = 0; 
		}
		if( truer && finish[counter]==0){
			printf("P%d->", counter); 
			for(int j = 0; j<m; j++)
				available[j] = available[j] + allocation[counter][j]; 
			
			finish[counter] = 1; 
		}
		counter = (counter+1)%n; 
	}
}
