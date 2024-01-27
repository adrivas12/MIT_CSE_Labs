//Write a MPI program using N processes to find 1!+2!+...+N!. Use scan. Also, handle 
//different errors using error handling routines

#include <mpi.h>
#include <stdio.h>
#include <string.h>
 
int fact(int n) 
{
	if (n<=1)
		return 1;
	return n*fact(n-1);
}
 
int main(int argc,char* argv[])
{
	int rank, size;
	int i = 0,k = 0,fact=1,ans[1000],sum=0, n;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Errhandler_set(MPI_COMM_WORLD, MPI_ERRORS_RETURN);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	 
	//Get the error code on broadcasting; purposely fail this
	int error;
	error = MPI_Bcast(&fact, 1, MPI_INT, 0, MPI_COMM_WORLD);
	 
	if (error != MPI_SUCCESS){
		char s[100];
		int len, class1;
		MPI_Error_string(error, s, &len);
		MPI_Error_class(error, &class1);
		fprintf(stderr, "Error description is %s\n", s);
		fflush(stderr);
		fprintf(stderr, "Error class is %d\n", class1);
		fflush(stderr);
	}

	for (i=1;i<=rank+1;i++) 
		fact = fact*i;

	MPI_Scan(&fact,&k,1,MPI_INT,MPI_SUM,MPI_COMM_WORLD);
	if (rank == size-1) {
		fprintf(stdout,"%d\n",k);
		fflush(stdout);
	}
	MPI_Finalize();
	return 0;
}
