//Write a program in MPI to toggle the character of a given string indexed by the rank of the process
//Hint: suppose the string is HeLLO and there are 5 processes, then process 0 toggle 'H' to 'h', process 1 toggle 'e' to 'E' and so on
#include "mpi.h"
#include <stdio.h>

int main(int argc, char *argv[]){
	int rank, size;
	char str[]= "HeLL";  
	MPI_Init(&argc, &argv); 
	MPI_Comm_rank(MPI_COMM_WORLD, &rank); 
	MPI_Comm_size(MPI_COMM_WORLD, &size); 
	printf("\nRank: %d\t Size: %d    ", rank, size);
	if(str[rank]>=65 && str[rank]<=90)
	{
		str[rank]+=32; 
		printf("New String: %s", str); 
	}
	else {
		str[rank]-=32; 
		printf("New String: %s", str); 
	}
	MPI_Finalize(); 
	return 0; 
}