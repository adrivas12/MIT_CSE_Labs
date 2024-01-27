//Write a MPI program usin N processes to find 1!+2!+....N! Use collective communication routines

#include <stdio.h>
#include "mpi.h"
#include <stdlib.h>

int main(int argc, char *argv[]){
	int rank, size, fact = 1, factsum, i; 
	MPI_Init(&argc, &argv); 
	MPI_Comm_rank(MPI_COMM_WORLD, &rank); 
	MPI_Comm_size(MPI_COMM_WORLD, &size); 

	MPI_Errhandler_set(MPI_COMM_WORLD, MPI_ERRORS_RETURN);
	int error; 
	error= MPI_Bcast(&fact, 1, MPI_INT, 4, MPI_COMM_WORLD);
	if(error!=MPI_SUCCESS){
		char s[100];
		int len, class1;
		MPI_Error_string(error, s, &len);
		MPI_Error_class(error, &class1);
		fprintf(stderr, "Error description is %s\n", s);
		fflush(stderr);
		fprintf(stderr, "Error class is %d\n", class1);
		fflush(stderr);
	} 
	for(i = 1; i<=rank+1; i++)
		fact = fact*i; 

	MPI_Reduce(&fact, &factsum, 1, MPI_INT, MPI_SUM, 4, MPI_COMM_WORLD);
	if (rank == size-1) {
		fprintf(stdout,"%d\n",factsum);
		fflush(stdout);
	}
	MPI_Finalize(); 
	exit(0); 
}