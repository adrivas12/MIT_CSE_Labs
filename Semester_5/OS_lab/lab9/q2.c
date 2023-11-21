//Write a C program using Malloc for implementing Multilevel feedback queue using
//three queues with each of them working with different scheduling policies
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

typedef struct Process
{
    int id;
    int AT,BT,CT,Priority,TAT,WT,RT;
}Process;
//ADD PRIORITY LATER

//TAT = CT-AT
//WT = TAT-BT
//RT = 1st time CPU - AT

void sortByAT(Process *P,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(P[i].AT > P[j].AT)
            {
                Process temp = P[i];
                P[i] = P[j];
                P[j] = temp;
            }
            else if(P[i].AT == P[j].AT)
            {
                if(P[i].id > P[j].id)
                {
                    Process temp = P[i];
                    P[i] = P[j];
                    P[j] = temp;
                }
            }
        }
    }
}

void FCFS(Process P[],int n,int tq1)
{
    for(int i=0;i<n;i++)
    {
        if(P[i].BT != 0)
        {
            if(P[i].BT <= tq1)
            {
                printf("Process %d completed in queue 1.\n",P[i].id);
                P[i].BT = 0;
            }
            else
            {
                P[i].BT  = P[i].BT - tq1;
                printf("Process %d moved to queue 2 with remaining time %d.\n",P[i].id,P[i].BT);
            }
            sleep(1);
        }
    }
}


void RR(Process *P,int n,int tq2)
{
    int count = 0;
    while(count < 2)
    {
        for(int i=0;i<n;i++)
        {
            if(P[i].BT != 0)
            {
                if(P[i].BT < tq2)
                {
                    printf("Process %d completed in queue 2.\n",P[i].id);
                    P[i].BT = 0;
                }
                else
                {
                    P[i].BT = P[i].BT - tq2;
                    if(P[i].BT != 0)
                        printf("Process %d was given tq = %d in queue 2.Remaining time:%d\n",P[i].id,tq2,P[i].BT);
                    else
                        printf("Process %d was given tq = %d in queue 2.Process completed in queue 2.\n",P[i].id,tq2);
                }
            }
            sleep(1);
        }
        count++;
    }
    for(int i=0;i<n;i++)
    {
        if(P[i].BT != 0)
        {
            printf("Process %d moved to queue 3 with remaining time %d.\n",P[i].id,P[i].BT);
            sleep(1);
        }
    }
    
}

void executePriority(Process *P,int tq3,int i)
{
    if(P[i].BT < tq3)
    {
        printf("Process %d completed in queue 3.\n",P[i].id);
        P[i].BT = 0;
    }
    else
    {
        P[i].BT = P[i].BT - tq3;
        if(P[i].BT != 0)
            printf("Process %d sent back into queue 3 with remaining time:%d\n",P[i].id,P[i].BT);
        else
            printf("Process %d completed in queue 3.\n",P[i].id);
    }
}

void sortByATAndPriority(Process *P,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(P[i].AT == P[j].AT)
            {
                if(P[i].Priority > P[j].Priority)
                {
                    Process temp = P[i];
                    P[i] = P[j];
                    P[j] = temp;
                }
                else if(P[i].Priority == P[j].Priority)
                {
                    if(P[i].id > P[j].id)
                    {
                        Process temp = P[i];
                        P[i] = P[j];
                        P[j] = temp;
                    }
                }
            }
        }
    }
}

//lesser no. priority should be executed first.
void Priority(Process *P,int n,int tq3)
{
    for(int i=0;i<n;i++)
    {
        if(P[i].BT != 0)
            executePriority(P,tq3,i);
        sleep(1);
    }
    int flag = 0;
    for(int i=0;i<n;i++)
    {
        if(P[i].BT != 0)
        {
            flag = 1;
            break;
        }
    }
    if(flag == 1)
    {
        Priority(P,n,tq3);
    }
    else
        return;
}

void input(Process *P,int n)
{
    for(int i=0;i<n;i++)
    {
        printf("\nenter AT,BT,Priority of process %d:",i);
        scanf("%d %d %d",&P[i].AT,&P[i].BT,&P[i].Priority);
        P[i].id = i;
    }
    sortByAT(P,n);
    for(int i=0;i<n;i++)
    {
        printf("\nAT:%d,BT:%d,Priority:%d\n",P[i].AT,P[i].BT,P[i].Priority);
    }
}

int main()
{
    int tq1 = 5,tq2 = 8,tq3 = 16;
    int n;
    printf("Enter the no. of processes:");
    scanf("%d",&n);
    Process *P = (Process*)calloc(n,sizeof(Process));
    input(P,n);
    printf("FCFS IN QUEUE 1:\n\n");
    FCFS(P,n,tq1);
    printf("RR IN QUEUE 2:\n\n");
    RR(P,n,tq2);
    printf("PRIORITY IN QUEUE 3:\n\n");
    Priority(P,n,tq3);
}
