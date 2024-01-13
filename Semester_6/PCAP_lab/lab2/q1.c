//Write a MPI program using synchronous send. The sender process sends a word to the receiver. 
//The second process receives the word, toggles each letter of the word and sends it back to 
//the first process. Both processes use synchronous send operations. 

#include "mpi.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){
	int rank, size;
	char x[1000]; 
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank); 
	MPI_Comm_size(MPI_COMM_WORLD, &size); 
	MPI_Status status; 
	if(rank==0){
		printf("Enter a word in master process: "); 
		scanf("%s", x); 
		MPI_Ssend(&x, strlen(x)+1, MPI_CHAR, 1, 1, MPI_COMM_WORLD); 
		fprintf(stdout, "I have sent %s from process 0\n", x); 
		fflush(stdout); 
		MPI_Recv(&x, 10, MPI_CHAR, 1, 1, MPI_COMM_WORLD, &status); 
		printf("New string is: %s", x); 
	}
	else{
		MPI_Recv(&x, 10, MPI_CHAR, 0, 1, MPI_COMM_WORLD, &status); 
		for(int i =0; i<strlen(x); i++)
		{
			if(x[i]>=65 && x[i]<=90)
			{
				x[i]+=32; 
			}
			else {
				x[i]-=32; 
			}
		}
		MPI_Ssend(&x, strlen(x)+1, MPI_CHAR, 0, 1, MPI_COMM_WORLD); 
		fflush(stdout); 
	}
	MPI_Finalize(); 
	return 0; 
}