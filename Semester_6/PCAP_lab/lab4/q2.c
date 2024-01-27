/*Write a MPI program using N processes to calculate pi-value by integrating f(x) = 4/(1+x)^2
Area under the curve is divided into rectangles and the rectangles are distributed to the procvessors. 
Also handle different errors using error handling routines. */

#include <mpi.h>
#include <stdio.h>
#include <string.h>
  
int main(int argc,char* argv[])
{
	int rank, size;
	int i = 0, j, k = 0, fac=1, ans[1000], sum=0, n, a[100][100], b[100];
	float x, y, area, pi1;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Errhandler_set(MPI_COMM_WORLD, MPI_ERRORS_RETURN);

	int error = MPI_Bcast(&size, 1, MPI_INT, 4, MPI_COMM_WORLD);
	if (error != MPI_SUCCESS) 
	{
		char s[100];
		int len, class1;
		MPI_Error_string(error, s, &len);
		MPI_Error_class(error, &class1);
		fprintf(stderr, "Error description is %s", s);
		fflush(stderr);
		fprintf(stderr, "Error class is %d", class1);
		fflush(stderr);
	}

	x = (float)(rank+1)/size;
	y = 4.f/(1+x*x);
	area = (1/(float)size)*y;

	MPI_Reduce(&area, &pi1, 1, MPI_FLOAT, MPI_SUM, 0, MPI_COMM_WORLD); 
	if (rank == 0) 
	{
		fprintf(stdout, "%f\n", pi1);
		fflush(stdout);
	}
	MPI_Finalize();
	return 0;
}
