//Write a MPI program to read N elements of an array in the root process (process 0)
//where N is equal to the total number of process. The root process sens one value to 
//each of slaves. Let even ranked process finds square of the received element and odd
//ranked process funds cube of received element Use Buffered send. 


#include <mpi.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
    int rank, size, N;
    int square=1, cube=1; 
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    N = size;
    int arr[N];
    if (rank == 0) {
        printf("Enter %d elements of the array:\n", N);
        for (int i = 0; i < N; i++) {
            scanf("%d", &arr[i]);
        }
        
        int buffer_size = N * sizeof(int) + MPI_BSEND_OVERHEAD;
        void *buffer = malloc(buffer_size);
        MPI_Buffer_attach(buffer, buffer_size);
        for (int i = 1; i < size; i++) {
            MPI_Bsend(&arr[i], 1, MPI_INT, i, 0, MPI_COMM_WORLD);
        }
        MPI_Buffer_detach(&buffer, &buffer_size);
        free(buffer);
    } 
    else {
        int x;
        MPI_Recv(&x, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE); 
        if(rank%2==0){
			square=x*x; 
			printf("Rank:%d Number: %d Square: %d \n",rank, x, square );
		} 
		else{
			cube=x*x;
			cube*=x;   
			printf("Rank:%d Number: %d cube: %d \n", rank, x, cube );
		}
	}
    MPI_Finalize();
    return 0;
}

