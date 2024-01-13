//Write a MPI program to read an integer value in teh root process. Root process sends
//this value to Process 1, process 1 sends this value to process 2 and so on. Last process
//sends the value back to root process. When sending the value each process will 
//increment the received value by one. Write the program using point communication routines


#include "mpi.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){
    int rank, size, x; 
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank); 
    MPI_Comm_size(MPI_COMM_WORLD, &size); 
    if(rank==0){
        printf("Enter a number in master process: "); 
        scanf("%d", &x); 
        MPI_Send(&x, 1, MPI_INT, 1, 1, MPI_COMM_WORLD); 
        MPI_Recv(&x, 1, MPI_INT, size - 1, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE); 
        printf("Final value received by process 0: %d\n", x);
    }
    else{
        MPI_Recv(&x, 1, MPI_INT, rank - 1, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE); 
        printf("Process: %d  Number: %d from Process: %d\n", rank, x, rank - 1); 
        x = x + 1; 
        MPI_Send(&x, 1, MPI_INT, (rank + 1) % size, 1, MPI_COMM_WORLD);
        
    }
    MPI_Finalize(); 
    return 0; 
}


/*
#include "mpi.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){
	int rank, size, x; 
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank); 
	MPI_Comm_size(MPI_COMM_WORLD, &size); 
	if(rank==0){
		printf("Enter a number in master process: "); 
		scanf("%d", &x); 
		MPI_Send(&x, 1, MPI_INT, 1, 1, MPI_COMM_WORLD); 
		MPI_Recv(&x, 1, MPI_INT, size-1, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE); 
		printf("Final value received by process 0: %d\n", x); 
	}
	else{
		for(int i= 1; i<size; i++){
			MPI_Recv(&x, 1, MPI_INT, i-1, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE); 
			printf("Process: %d  Number: %d from Process: %d\n",rank, x, i-1); 
			x=x+1; 
			MPI_Send(&x, 1, MPI_INT, (i+1)%size, 1, MPI_COMM_WORLD);
		
		}
	}
	MPI_Finalize(); 
	return 0; 
}*/