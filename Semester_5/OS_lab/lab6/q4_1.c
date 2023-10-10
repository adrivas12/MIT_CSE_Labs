//Write a two-player 3x3 tic-tac-toe console game using shared memory

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

struct shared_use_st
{
	int count;
	char mat[3][3];
};

int checkWin(char matrix[3][3]) 
{
    int i, j;
    // Checking rows
    for (i = 0; i < 3; i++) 
    {
        if (matrix[i][0] == matrix[i][1] && matrix[i][1] == matrix[i][2] && matrix[i][0]!=' ') 
        {
            return 1;
        }
    }
    // Checking columns
    for (j = 0; j < 3; j++) 
    {
        if (matrix[0][j] == matrix[1][j] && matrix[1][j] == matrix[2][j] && matrix[0][j]!=' ') 
        {
            return 1;
        }
    }
    // Checking diagonals
    if (matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2] && matrix[0][0]!=' ') 
    {
        return 1;
    }
    if (matrix[0][2] == matrix[1][1] && matrix[1][1] == matrix[2][0] && matrix[1][1]!=' ') 
    {
        return 1;
    }
    return 0;
}


void display(char mat[][3])
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			printf("| %c ",mat[i][j]);
		}
		printf("\n____________\n");
	}
	printf("\n\n"); 
}

int main()
{
	void *shared_memory = (void *)0;
	struct shared_use_st *shared_stuff;
	char alphatosend;
	pid_t pid;
	int status;
	int smid = shmget((key_t)1231, sizeof(struct shared_use_st), 0666 | IPC_CREAT);
	if(smid == -1){
		printf("shmget failed!\n");
		exit(0);
	}
	shared_memory = shmat(smid, (void *)0, 0);
	if(shared_memory == (void *)-1){
		printf("shmat failed!\n");
		exit(0);
	}
	printf("Memory attached at %X\n", (int)shared_memory);
	shared_stuff = (struct shard_use_st *)shared_memory;
	shared_stuff->count=0;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			shared_stuff->mat[i][j]=' ';		
		}
	}
	while(shared_stuff->count!=9){
		while(1)
		{
			int row, col; 
			printf("Enter row and column: ");
			scanf("%d %d",&row,&col);
			if(shared_stuff->mat[row][col]==' ')
			{
				shared_stuff->mat[row][col]='X';
				if(checkWin(shared_stuff->mat))
				{
					printf("You have WON!!!!!!");
					shared_stuff->count=9;
					exit(0);
				}
				shared_stuff->count++;
				break;
			}
			else if(row >3 || col>3)
			{
				printf("Ivalid Row or Column\n"); 
			}
			else
			{
				printf("Position already occupied\n");
			}
		}
		display(shared_stuff->mat);
		int x=shared_stuff->count;
		while(shared_stuff->count==x);
		display(shared_stuff->mat);
	}
	
}