#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Event
{
    int date;
    char *month;
    char *activity;
};
void read(struct Event *p)
{
    printf("Enter date: ");
    scanf("%d", &p->date);
    p->month=(char *)malloc(sizeof(char));
    printf("Enter month: ");
    scanf("%s", p->month);
    p->activity=(char *)malloc(sizeof(char));
    printf("Enter activity: ");
    scanf("%s", p->activity);
    
}
void display(struct Event *p)
{
    printf("\n\nDate: %d \nMonth: %s\nActivity: %s", p->date, p->month, p->activity);
}
void modify(struct Event *p, int n)
{
    int d1; char *m1; char a1[10];
    printf("\n\nEnter the date and month you want to modify: ");
    scanf("%d", &d1);
    scanf(" %s",m1);
    printf("Enter the new activity: ");
    scanf("%s", a1);
    for(int i = 0; i<n; i++)
    {
        if(d1==(p+i)->date)
        {
            if(strcmp(m1, (p+i)->month))
            {
                strcpy((p+i)->activity, a1);
                break;
            }
        }
    }
    //printf("\nDate: %d \nMonth: %s\nNew Activity: %s", p->date, p->month, p->activity);
}

int main()
{
    int n;
    struct Event *p;
    printf("Enter the number of entries: ");
    scanf("%d", &n);
    p = (struct Event *)calloc(n, sizeof(struct Event));
    for(int i = 0; i<n; i++)
    { 
        read(p+i);
    }
    for(int i = 0; i<n; i++)
    {
        printf("\n");
        display(p+i);
    }
    
    modify(p, n);
    for(int j=0; j<n; j++)
    {
        display(p+j);
    }

    return 0; 
}