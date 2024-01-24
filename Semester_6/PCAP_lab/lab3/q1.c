/* Write a MPI program to read N values in the root process. Root process sends
one value to each process. Every process receives it and finds the factorial 
of that number and returns it to the root process. Root process gathers the factorial 
and finds the sum of it. Use N number of processes*/

#include "mpi.h"
#include <stdio.h>

int main(int argc, char *argv[]){
	int rank, size, N, A[10], B[10], fact=1, c, i; 
	MPI_Init(&argc, &argv); 
	MPI_Comm_rank(MPI_COMM_WORLD, &rank); 
	MPI_Comm_size(MPI_COMM_WORLD, &size); 

	if(rank==0){
		N=size; 
		fprintf(stdout, "Enter %d values: \n", N); 
		fflush(stdout); 
		for(i = 0; i<N; i++)
			scanf("%d", &A[i]); 
	}
	MPI_Scatter(A, 1, MPI_INT, &c, 1, MPI_INT, 0, MPI_COMM_WORLD); 
	fprintf(stdout, "I have recieved %d in process %d\n", c, rank); 
	fflush(stdout); 

	for(i=1; i<=c; i++)
		fact= fact*i;

	MPI_Gather(&fact, 1, MPI_INT, B, 1, MPI_INT, 0, MPI_COMM_WORLD); 
	int sum = 0; 
	if(rank==0){
		fprintf(stdout, "The result gathered in the root\n"); 
		fflush(stdout); 
		for(i = 0; i<N; i++)
		{
			sum += B[i];
			fprintf(stdout, "%d\t", B[i]); 
		}
		fprintf(stdout, "Sum: %d\t\n", sum); 
		fflush(stdout); 
	}
	MPI_Finalize(); 
	return 0; 
}