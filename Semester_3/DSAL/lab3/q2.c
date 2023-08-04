#include<stdio.h>
#include<stdlib.h>

typedef struct 
{
	char name[100];
	int rollno;
	float cgpa;
}Student;

void read(Student *ptr, int i)
{
	printf("Enter the name of the student: \n");
	scanf("%s", ptr[i].name);
	printf("Enter the rollno of the student: \n");
	scanf("%d", &ptr[i].rollno);
	printf("Enter the cgpa of the student: \n");
	scanf("%f", &ptr[i].cgpa);
}

void display(Student *ptr, int i)
{
	printf("Name: %s\n", ptr[i].name);
	printf("Roll number: %d\n", ptr[i].rollno);
	printf("CGPA: %f\n", ptr[i].cgpa);
}

void sort(Student *ptr, int n)
{
	Student temp;
	int i,j;
	for(i = 0 ; i < n-1 ; i ++)
	{
		for(j = 0 ; j < n-i-1 ; j++)
		{
			if(ptr[j].rollno > ptr[j+1].rollno)
			{
				temp = ptr[j];
				ptr[j] = ptr[j+1];
				ptr[j+1] = temp;
			}
		}
	}
}

int main()
{
	Student *ptr;
	int n, i;
	printf("Enter the number of students: ");
	scanf("%d", &n);
	printf("\n");
	
	ptr = (Student *)calloc(n, sizeof(Student));
	for(i = 0; i<n; i++)
	{
		read(ptr, i);
		printf("\n");
	}
	sort(ptr, n);
	printf("\n\nThe sorted list of students: \n");
	for(i=0; i<n; i++)
	{
		display(ptr, i);
		printf("\n");
	}

	return 0;
}