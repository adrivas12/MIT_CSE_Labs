#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int **p1, **p2, **p3;
    int r1, c1, r2, c2, i, j, k;

    printf("Enter the rows and columns of the first matrix \n");
    scanf("%d%d", &r1, &c1);
    printf("Enter the rows and columns of the second matrix \n");
    scanf("%d%d", &r2, &c2);

    if(c1!=r2)
        printf("The matrices cannot be multiplied");

    p1 = (int **)malloc(sizeof(int *) * r1);
    p2 = (int **)malloc(sizeof(int *) * r2);
    p3 = (int **)malloc(sizeof(int *) * r1);

    for( i = 0; i<r1; i++)
    {
        p1[i] = (int *)malloc(sizeof(int) * c1);
    }
    for(i = 0; i<r2; i++)
    {
        p2[i] = (int *)malloc(sizeof(int) * c2);
    }
    for( i = 0; i<r1; i++)
    {
        p3[i] = (int *)malloc(sizeof(int) * c2);
    }

    printf("Enter the elements of the first matrix \n");
    for(i = 0; i<r1; i++)
    {
        for( j =0; j<c1; j++)
        {
            scanf("%d", &p1[i][j]);
        }
    }
    printf("Enter the elements of the second matrix \n");
    for( i = 0; i<r2; i++)
    {
        for(j = 0; j<c2; j++)
        {
            scanf("%d", &p2[i][j]);
        }
    }
    for ( i = 0; i<r1; i++)
    {
        for(j = 0; j<c2; j++)
        {
            p3[i][j] = 0;
            for(k = 0; k<c1; k++)
                p3[i][j] += p1[i][k]*p2[k][j];
        }
    }

    printf("The resultant matrix is : \n");
    for(i = 0; i<r1; i++)
    {
        for(j = 0; j<c2; j++)
            printf("%d \t", p3[i][j]);
        printf("\n");
    }
    return 0;
}
