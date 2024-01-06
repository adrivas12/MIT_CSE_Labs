//Write a simple MPI program to find out pow(x, rank) for all the processes where 
//'x' is the integer constant and 'rank' of the process

#include "mpi.h"
#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[]){
	int rank, size, x = 2, power=1; 

	MPI_Init(&argc, &argv); 
	MPI_Comm_rank(MPI_COMM_WORLD, &rank); 
	MPI_Comm_size(MPI_COMM_WORLD, &size); 
	for(int i =1; i<=rank; i++){
		power *=x;
	}
	printf("Power: %d \t x: %d \t rank: %d\n", power, x, rank);
	MPI_Finalize(); 
	return 0; 
}