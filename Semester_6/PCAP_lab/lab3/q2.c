/* Write a MPI program to read an integer value M and NXM elements into an 1D array 
in the root process, where N is the number of processes. Root process sends M elements 
to each process. Each process finds average of M elements it received and sends these
average values to root. Root collects all the values and finds the total average. Use 
collective communication routines. */


#include "mpi.h"
#include <stdio.h>

int main(int argc, char *argv[]){
    int rank, size, N, M, A[20], B[20], ave=0, sum=0, c[50], i, j; 
    MPI_Init(&argc, &argv); 
    MPI_Comm_rank(MPI_COMM_WORLD, &rank); 
    MPI_Comm_size(MPI_COMM_WORLD, &size); 

    if(rank==0){
        N=size; 
        printf("Enter M: ");
        scanf("%d", &M); 
     	fprintf(stdout, "N: %d", N); 
        fprintf(stdout, "\nEnter %d values: \n", N*M); 
        fflush(stdout); 
        for(i = 0; i<N; i++)
            for(j = 0; j<M; j++)
                scanf("%d", &A[i*M+j]); 
    }
	    MPI_Bcast(&M, 1, MPI_INT, 0, MPI_COMM_WORLD);

    MPI_Scatter(A, M, MPI_INT, &c, M, MPI_INT, 0, MPI_COMM_WORLD); 
    //fprintf(stdout, "I have received %d values in process %d\n", M, rank); 
    fflush(stdout); 

    for(i = 0; i<M; i++)
    {
        sum += c[i]; 
        ave = sum/M; 
    }

    MPI_Gather(&ave, 1, MPI_INT, B, 1, MPI_INT, 0, MPI_COMM_WORLD); 

    int TotAve=0; 
    if(rank==0){
        fprintf(stdout, "The result gathered in the root\n"); 
        fflush(stdout); 
        for(i = 0; i<N; i++)
        {
            TotAve+=B[i];
            fprintf(stdout, "%d\t", B[i]); 
        }
        TotAve /= size;
        fprintf(stdout, "\nTotal Average: %d\t\n", TotAve); 
        fflush(stdout); 
    }
    MPI_Finalize(); 
    return 0; 
}

