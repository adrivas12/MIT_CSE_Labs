//Write a program in MPI where even ranked process prints "Hello" and odd ranked process prints "World". 
#include "mpi.h"
#include <stdio.h>

int main(int argc, char *argv[]){
	int rank, size; 
	MPI_Init(&argc, &argv); 
	MPI_Comm_rank(MPI_COMM_WORLD, &rank); 
	MPI_Comm_size(MPI_COMM_WORLD, &size); 

	if(rank%2==0){
		printf("rank: %d Hello \n", rank); 
	}
	else{
		printf("rank: %d World \n", rank); 
	}
	//printf("My rank is %d in total %d processes\n", rank, size);
	MPI_Finalize(); 
	return 0; 
}