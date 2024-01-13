//Write a MPI program where the master process(process 0) sends a number to each of 
//slaves and the slave processes receive the number and prints it. Use standard send

#include "mpi.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){
	int rank, size, x; 
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank); 
	MPI_Comm_size(MPI_COMM_WORLD, &size); 
	if(rank==0){
		printf("Enter a number in master process: "); 
		scanf("%d", &x); 
		for(int i =0; i<size; i++)
		{
			MPI_Send(&x, 1, MPI_INT, i, 1, MPI_COMM_WORLD); 
		}
	}
	else{
		MPI_Recv(&x, 1, MPI_INT, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE); 
		printf("Process: %d  Number received: %d \n",rank, x); 
	}
	MPI_Finalize(); 
	return 0; 
}