#include<stdio.h>
#include<stdlib.h>

typedef struct DOB
{
	int date;
	int month;
	int year;
}DOB;
typedef struct
{
	int houseNo;
	int zipcode;
	char state[30];
}address;

typedef struct
{
	char name[100];
	DOB dob;
	address addr;
}Data;

void read(Data *p)
{
	printf("Enter the name of the employee: ");
	scanf("%s", p->name);
	printf("Enter the date of birth of the employee (dd-mm-yyyy): ");
	scanf("%d-%d-%d", &(p->dob).date, &(p->dob).month, &(p->dob).year);
	printf("Enter the address of the employee (house number, zipcode, state): ");
	scanf("%d, %d, %s", &(p->addr).houseNo, &(p->addr).zipcode, (p->addr).state);
}

void display(Data *p)
{
	printf("Name: %s", (p->name));
	printf("\nDate of birth: %d-%d-%d", (p->dob).date, (p->dob).month, (p->dob).year);
	printf("\nAddress: %d, %d, %s", (p->addr).houseNo, (p->addr).zipcode, (p->addr).state);

}
int main()
{
	int i, n;
	Data *p;
	printf("\nEnter the number of employees: ");
	scanf("%d", &n);
	printf("\n");
	p=(Data *)calloc(n, sizeof(Data));
	for(i = 0; i<n; i++)
	{
		read(p);
		printf("\n");
	}
	printf("\n\nThe information of the employees is: \n");
	for(i =0 ; i<n; i++)
	{
		display(p);
		printf("\n");
	}
	printf("\n");

	return 0;
}