#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>

sem_t mutex,wrt;
int readcount = 0;

void* reader(void *arg)
{
    while(1)
    {
        sem_wait(&mutex);
        readcount++;
        if(readcount == 1)
        {
            sem_wait(&wrt);
        }
        sem_post(&mutex);
        printf("Reading %d.....\n",readcount);
        sleep(1);
        sem_wait(&mutex);
        readcount--;
        if(readcount == 0)
        {
            sem_post(&wrt);
        }
        sem_post(&mutex);
        sleep(2);
    }
}

void* writer(void *arg)
{
    while(1)
    {
        sem_wait(&wrt);
        printf("Writing %d.....\n",readcount);
        sem_post(&wrt);
        sleep(4);
    }
}

int main()
{
    pthread_t th[3];
    sem_init(&mutex,0,1);
    sem_init(&wrt,0,1);
    pthread_create(&th[0],NULL,reader,NULL);
    pthread_create(&th[1],NULL,reader,NULL);
    pthread_create(&th[2],NULL,writer,NULL);
    pthread_join(th[0],NULL);
    pthread_join(th[1],NULL);
    pthread_join(th[2],NULL);
}