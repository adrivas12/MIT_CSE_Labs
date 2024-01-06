//Write a program in MPI to simulate simple calculator. Perform each operation using different process in parallel
#include "mpi.h"
#include <stdio.h>

int main(int argc, char *argv[]){
	int rank, size, x=3, y=4; 
	MPI_Init(&argc, &argv); 
	MPI_Comm_rank(MPI_COMM_WORLD, &rank); 
	MPI_Comm_size(MPI_COMM_WORLD, &size); 

	printf("\nRank: %d\t Size: %d    ", rank, size);
	switch(rank){
	case 0:
		printf("\nAddition: "); 
		printf("%d + %d = %d\n", x, y, (x+y)); 
		break; 
	case 1: 
		printf("\nSubstraction: "); 
		printf("%d - %d = %d\n", x, y, (x-y)); 
		break; 
	case 2:
		printf("\nMultiplication: "); 
		printf("%d * %d = %d\n", x, y, (x*y)); 
		break; 
	case 3:
		printf("\nDivision: "); 
		printf("%d / %d = %d\n", x, y, (x/y)); 
		break; 
	default: printf("Invalid"); 
	}
	MPI_Finalize(); 
	return 0; 
}