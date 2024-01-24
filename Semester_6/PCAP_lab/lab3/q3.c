/* Write a MPI program to read a string. Using N processes(string length is evenly 
divisible by N), find the number of non-vowels in the string. In the root process 
print number of non-vowels found by each process and print the total number of non-vowels*/

#include "mpi.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int isVowel(char c){
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') return 1;
	return 0;
}
int main(int argc, char *argv[]){
	int rank, size, N, M, count = 0, sub_count = 0, i, j, B[10]; 
	char str[30], sub_str[30], all_str[30]; 
	MPI_Init(&argc, &argv); 
	MPI_Comm_rank(MPI_COMM_WORLD, &rank); 
	MPI_Comm_size(MPI_COMM_WORLD, &size); 

	if(rank==0){
		N=size; 
		fprintf(stdout, "N: %d\n", N); 
		printf("Enter a string: ");
		fflush(stdout); 
		scanf("%s", str); 
		M=strlen(str)/N; 
	}
	MPI_Bcast(&M, 1, MPI_INT, 0, MPI_COMM_WORLD); 

	MPI_Scatter(str, M, MPI_CHAR, sub_str, M, MPI_CHAR, 0, MPI_COMM_WORLD); 
	//fprintf(stdout, "I have recieved %d in process %d\n", c, rank); 
	fflush(stdout); 

	for(i = 0; i<M; i++){
		if(!isVowel(sub_str[i]))
			sub_count++; 
	}
	fprintf(stdout, "%d\n",sub_count );
	fflush(stdout);
    MPI_Gather(&sub_count, 1, MPI_INT, B, 1, MPI_INT, 0, MPI_COMM_WORLD);
    if (rank == 0) {
        printf("Number of non-vowels found by each process: ");
        for (j = 0; j < size; j++) {
        	//printf("%s", str); 
            fprintf(stdout, "%d ", B[j]);
            count+=B[j];
            fflush(stdout); 
        }
        //count+=sub_count;
        fprintf(stdout, "\nTotal number of non-vowels: %d\n", count);
        fflush(stdout); 
    }

    MPI_Finalize();
    return 0;
}