#include<stdio.h>

int mat_mul(int m1[][10], int m2[][10], int mul[][10], int r1, int c1, int r2, int c2)
{
	int i, j, k;
	for(i = 0; i<r1; i++)
	{
		for ( j = 0; j<c2; j++)
		{
			mul[i][j] = 0;
			for(k = 0; k<c1; k++)
				mul[i][j]+=m1[i][k]*m2[k][j];
		}
	}
	printf("the final matrix is : \n");
	for(i =0; i<r1; i++)
	{
		for(j = 0; j<c2; j++)
		{
			printf("%d", mul[i][j]);
			printf(" ");
			printf("\n");
		}
	}
}

int main()
{
	int m1[10][10], m2[10][10], mul[10][10];
	int r1, c1, r2, c2;
	int i, j, k;
	printf("Enter the number of rows and columns in matrix 1 : \n");
	scanf("%d%d", &r1, &c1);
	printf("Enter the number of rows and columns in matrix 2 : \n" );
	scanf("%d%d", &r2, &c2);
	printf("Enter the elements of matrix 1: ");
	for(i = 0; i<r1; i++)
	{
		for(j = 0; j<c1; j++)
			scanf("%d", &m1[i][j]);
	}
	printf("Enter the elements of matrix 2: ");
	for(i =0; i<r2; i++)
	{
		for(j = 0; j<c2; j++)             
			scanf("%d", &m2[i][j]);
	}
	if(r1!=c2)
	{
		printf("The matrices are not compatible \n");
		return 0;
	}
	mat_mul(m1, m2, mul, r1, c1, r2, c2);

}