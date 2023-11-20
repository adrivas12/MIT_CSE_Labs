#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
#include<pthread.h>
#include<unistd.h>

sem_t mutex,waiting,barber;
int chairs[5];
int f,r;
int customerno = 0;

void* customer(void* arg)
{
    while(1)
    {
        sem_wait(&waiting);
        printf("customer %d is waiting\n",customerno);
        chairs[(++r) % 5] = customerno;
        customerno++;
        sem_post(&mutex);
        sleep(1);
    }
}

void* barb(void *arg)
{
    while(1)
    {
        sem_wait(&barber);
        sem_wait(&mutex);
        int item = chairs[(++f) % 5];
        printf("cutting started for customer %d\n",item);
        sem_post(&waiting);
        sleep(4);
		printf("Cutting complete for %d\n",item);
		sem_post(&barber);
    }
}

int main()
{
    pthread_t th[3];
    sem_init(&waiting,0,5);
    sem_init(&barber,0,1);
    sem_init(&mutex,0,1);
    pthread_t th1,th2;
    pthread_create(&th1,NULL,customer,NULL);
    pthread_create(&th2,NULL,barb,NULL);
    pthread_join(th1,NULL);
    pthread_join(th2,NULL);

}