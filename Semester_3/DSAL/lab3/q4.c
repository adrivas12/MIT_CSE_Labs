#include<stdio.h>
#include<stdlib.h>


struct DOB
{
	int day;
	int *month;
	int year;
};

struct STU_INFO
{
	int regNo;
	char *name;
	char address[100];
};

struct COLLEGE
{
	char *collName;
	char uniName[100];
};

struct Student
{
	struct DOB *dmy;
	struct STU_INFO stuInfo ;
	struct COLLEGE college ;
};

void readInfo(struct Student *p)
{
	printf("Enter date of birth\n");
	scanf("%d %d %d", &(p->dmy->day), p->dmy->month, &(p->dmy->year));
	printf("Enter Registration Number: ");
	scanf("%d", &p->stuInfo.regNo);
	printf("Enter Name: ");
	scanf("%s", p->stuInfo.name);
	printf("Enter Address: ");
	scanf("%s", p->stuInfo.address);
	printf("Enter College Name: ");
	scanf("%s", p->college.collName);
	printf("Enter University name: ");
	scanf("%s", p->college.uniName);
}
void display(struct Student *p){
	printf("Date of Birth: %d-%d-%d\n", p->dmy->day, *(p->dmy->month), p->dmy->year);
	printf("Reg No: %d\n",p->stuInfo.regNo);
	printf("Name: %s\n",p->stuInfo.name);
	printf("Address: %s\n", p->stuInfo.address);
	printf("College name: %s\n", p->college.collName);
	printf("University name: %s\n",p->college.uniName);
}

int main()
{
	struct Student *p;
	p = (struct Student*) malloc (sizeof(struct Student));
	p->dmy = (struct DOB*) malloc (sizeof(struct DOB));
	p->dmy->month = (int*) malloc (sizeof(int));
	p->stuInfo.name = (char *) malloc (sizeof(char));
	p->college.collName = (char *) malloc (sizeof(char));
	readInfo(p);
	display(p);
}
