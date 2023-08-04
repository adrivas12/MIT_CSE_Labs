#include<stdio.h>
#include<stdlib.h>
void StringMatching(char t[], char p[], int n, int m)
{
	int opcount=0, opcount1=0, j; 
	for(int i=0; i<=n-m; i++)
	{
		j=0; 
		opcount++; 
		while(j<m && t[i+j]==p[j])
		{
			//opcount1++; 
			j=j+1;
		}
		if(j==m)
		{	
			printf("\nElement found at i: %d", i); 
			break;
		}
	}
	printf("\nOpcount: %d\n", opcount+j); 
}
int main()
{
	int n, m; 
	printf("\nEnter m, n: "); 
	scanf("%d %d", &n, &m); 
	char t[n], p[m];
	//t=(char*)malloc(sizeof(char)*n);
	//p=(char*)malloc(sizeof(char)*m);  
	printf("\nEnter Text: ");
	scanf("%s", t); 
	printf("\nEnter pattern: "); 
	scanf("%s", p); 
	StringMatching(t, p, n, m); 
 
	//free(t);
	//free(p);  
	return 0; 
}