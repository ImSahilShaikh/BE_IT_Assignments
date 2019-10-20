#include<stdio.h>
#include<semaphore.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
#include<pthread.h>

sem_t full,empty;
pthread_mutex_t lock;
int n,count=0;
int *buffer;

void *producer(void *args)
{	
	int i;
	int pos= *(int*)args;
	while(1)
	{
		sleep(rand()%5);
		sem_wait(&empty);
		pthread_mutex_lock(&lock);
		//this is critical section
			buffer[count]=rand()%8;
			printf("\n%d PRODUCER generated value : %d",pos+1,buffer[count]);
			count++;
			sleep(1);
			printf("\nBUFFER is : ");
			for(i=0;i<n;i++)
			{
				printf("\t%d\t",buffer[i]);
			}
			printf("\n");
		pthread_mutex_unlock(&lock);
		sem_post(&full);
	}
	pthread_exit(NULL);
}
void *consumer(void *args)
{	
	int i;
	int pos= *(int*)args;
	while(1)
	{
		sleep(rand()%5);
		sem_wait(&full);
		pthread_mutex_lock(&lock);
		//this is critical section
			
			printf("\n%d CONSUMER consumed value : %d",pos+1,buffer[count-1]);
			buffer[count-1]=0;
			count--;
			sleep(1);
			printf("\nBUFFER is : ");
			for(i=0;i<n;i++)
			{
				printf("\t%d\t",buffer[i]);
			}
			printf("\n");
		pthread_mutex_unlock(&lock);
		sem_post(&empty);
	}
	pthread_exit(NULL);
}


int main()
{
	int *b,p,c,i;
	pthread_t thread1[10],thread2[10];
	int pshared;
	
	printf("\nHow many producers?");
	scanf("%d",&p);
	printf("\nHow many consumers?");
	scanf("%d",&c);
	printf("\nSize of buffer");
	scanf("%d",&n);
	
	buffer=(int*)calloc((n+1),sizeof(int));
	pthread_mutex_init(&lock,NULL);
	sem_init(&full,0,0);
	sem_init(&empty,0,n);
	for(i=0;i<p;i++)
	{
		b=&i;
		pthread_create(&thread1[i],NULL,producer,b);
	}
	for(i=0;i<c;i++)
	{
		b=&i;
		pthread_create(&thread2[i],NULL,consumer,b);
	}	
	for(i=0;i<p;i++)
	{
		pthread_join(thread1[i],NULL);
	}
	for(i=0;i<c;i++)
	{
		pthread_join(thread2[i],NULL);
	}
	sem_destroy(&full);
	sem_destroy(&empty);
	return 0;	
}
