/*Write a MPI program to read a 3X3 matrix. Enter an element to be searched in the root 
process. Find the number of occurrences of this element in the matrix using three processes. 
Also, handle different errors using error handling routines. */

#include <stdio.h>
#include <mpi.h>
 
int main (int a,char *b[]) 
{
	int rank, ele,size;
	int A[3][3], B[3], count=0, tc = 0;
	MPI_Init(&a, &b);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Errhandler_set(MPI_COMM_WORLD,MPI_ERRORS_RETURN);

	int error; 
	error=MPI_Bcast(&size, 1, MPI_INT, 4, MPI_COMM_WORLD);
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
	    	
	if (rank == 0)
	{
		printf("Enter elements into matrix: \n");
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				scanf("%d", &A[i][j]);
		        
		printf("Enter the element to count: \n");
		scanf("%d", &ele);
	}
	MPI_Bcast(&ele, 1, MPI_INT, 0, MPI_COMM_WORLD);
	MPI_Scatter(A , 3, MPI_INT, B, 3, MPI_INT, 0, MPI_COMM_WORLD);
	 
	for (int i = 0; i < 3; i++) 
	{
		printf("%d ",B[i]);
		if (B[i] == ele) 
		{
			count ++;
		}
	}
	printf("\nProcess %d found %d occurrences\n",rank,count);
	MPI_Reduce(&count, &tc, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
	if (rank == 0)
	{
		printf("\nNumber of occurrences is %d\n",tc);
	}
	MPI_Finalize();
	return 0; 
}