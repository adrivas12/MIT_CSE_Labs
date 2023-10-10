#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

int buf[100], f, r, mul=0; 
sem_t mutex, full, empty; 

void *produce(void *arg)
{
	int i;
	while(1) 
	{
		for(i=0; i<mul+10; i++)
		{
			sem_wait(&empty);
			sem_wait(&mutex); 
			printf("Produced item is: %d\n", i); 
			buf[(++r)%100]=i; 
			usleep(100000); 
			sem_post(&mutex); 
			sem_post(&full); 
			//printf("full %u\n", full); 
		}
	sleep(1);
	}
}

void *consume(void *arg)
{
	int item, i; 
	while(1)
	{
		for(i=0; i<10; i++)
		{
			sem_wait(&full); 
			//printf("full %u\n", full); 
			sem_wait(&mutex); 
			mul++; 
			item=buf[(++f)%10]; 
			usleep(100000); 
			printf("consumed item is: %d\n", item); 
			sleep(1); 
			sem_post(&mutex); 
			sem_post(&empty); 
		}
	}
}
int main()
{
	pthread_t tid1, tid2; 
	sem_init(&mutex, 0, 1); 
	sem_init(&full, 0, 1); 
	sem_init(&empty, 0, 100); 
	pthread_create(&tid1, NULL, produce, NULL);
	pthread_create(&tid2, NULL, consume, NULL); 
	pthread_join(tid1, NULL); 
	pthread_join(tid2, NULL); 
}