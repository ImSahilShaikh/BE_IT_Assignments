/*
	Statement : Thread Synchronisation using counting semaphores.
				Application to demonstrate producer-consumer problem with counting semaphores and mutex.
	Roll no.  : 33364
*/

//Header Files 

#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<semaphore.h>

struct prc
{
	sem_t full,empty;
	int buffer[10],in,out;
	pthread_mutex_t lock;
}prc;

void *consumer(void *arg); 
void *producer(void *arg);

int item=1;

void init()
{
	prc.in=0; //in parameter for buffer
	prc.out=0; //in parameter for buffer
	sem_init(&prc.empty,0,10); //initializes the semaphore for empty 
	sem_init(&prc.full,0,0); //initializes the semaphore for full 
	pthread_mutex_init(&prc.lock,NULL); //initializes value of mutex
}

int main()
{
	//variable declarations
	int i,prd,cns,*arg;
	pthread_t p[10],c[10];
	
	//Taking input for number of producer and consumer
	printf("\nEnter the number of Producers\n");
	scanf("%d",&prd);
	printf("\nEnter the number of Consumers\n");
	scanf("%d",&cns);
	
	//calling init to initialize default start values to in, out , empty, full and mutex
	init();	
	
	for(i=0;i<prd;i++)
	{
		arg=&i;
		pthread_create(&p[i],NULL,*producer,(void*)arg);
	}
	for(i=0;i<cns;i++)
	{
		arg=&i;
		pthread_create(&c[i],NULL,*consumer,(void*)arg);
	}
    for(i=0;i<prd;i++)
    {
		pthread_join(p[i],NULL);
	}
	for(i=0;i<cns;i++)
	{
		pthread_join(c[i],NULL);
	}
}

//function for producer
void *producer(void *arg)
{
	int i;
	i=*(int *) arg;
	while(1){
		sleep(rand()%10);
		sem_wait(&prc.empty);  // lock a semaphore and decrease the value of the semaphore by one
		pthread_mutex_lock(&prc.lock); //lock critical section for process
		//critical section starts
			printf("\nProducer %d Produced item no: %d ",i,item);
			prc.buffer[(prc.in++)%10]=item++;
		//critical section ends
		pthread_mutex_unlock(&prc.lock);//unlock critical section for process
		sem_post(&prc.full); //increases the value of the semaphore by 1
	}
}

//function for consumer
void *consumer(void *arg)
{
	int i,j;
	i=*(int *) arg;
	int value;
	while(1)
	{
		sleep(rand()%10);
		sem_wait(&prc.full);
		pthread_mutex_lock(&prc.lock);
		//critical section starts
			value=prc.buffer[(prc.out++)%10];
			printf("\nConsumer %d Consumed item no: %d \n",i,value);
		//critical section ends
		pthread_mutex_unlock(&prc.lock);
		sem_post(&prc.empty);
	}
}
