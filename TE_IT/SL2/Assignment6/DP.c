#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
//number of philosophers
#define n 5

enum
{
	THINKING,EATING,HUNGRY
}state[n];


//semaphores and mutex
pthread_mutex_t lock;
sem_t chopstick[n];

// Other functions
void grabfork(int i);
void putfork(int i);
void think(int i);
void eat(int i);

// Keep's track of how much each philosopher got chance to eat
int eatcount[n] = {0};

//philosopherfunction

void *philosopher(void *arg)
{
	int i;
	i=*(int*)arg;
	printf("\nPhilosopher %d has entered",i);
	while(1)
	{
		think(i);
		eat(i);
	}
}

void main()
{
	int *arg,i,result;
	result=pthread_mutex_init(&lock,NULL);
	
	//philosopher thread
	pthread_t philosopherThread;
	
	//init chopsticks
	for(i=0;i<n;i++)
	{
		result=sem_init(&chopstick[i],0,1);
		if(result!=0)
		{
			printf("\nERROR: Can't Initialize Chopsticks");
		}
	}
	for(i=0;i<n;i++)
	{
		arg=(int *)malloc(sizeof(int));
		*arg=i;
		result=pthread_create(&philosopherThread,NULL,philosopher,(void*)arg);
		if(result!=0)
		{
			printf("\nERROR: Can't Create Thread");
		}
	}
	for(i=0;i<n;i++)
	{
		result=pthread_join(philosopherThread,NULL);
		if(result!=0)
		{
			printf("\nERROR: Can't Join Threads");
		}
	}
}



//think function

void think(int i)
{
	if(state[i]==THINKING)
	{
		int temp = rand()%10;
		//condition ? value_if_true : value_if_false
		temp = (temp==0 ? 1 : temp );
		printf("\nPhilosopher %d is THINKING",i);
		sleep(temp);
		state[i]=HUNGRY;
	}
}

void grabfork(int i)
{
    sem_wait(&chopstick[i]);
    sem_wait(&chopstick[(i + 1) % n]);
}

// Put the Chopsticks
void putfork(int i)
{
    sem_post(&chopstick[i]);
    sem_post(&chopstick[(i + 1) % n]);
}


//eat function
void eat(int i)
{
	int temp = rand()%10;
	//condition ? value_if_true : value_if_false
	temp = (temp==0 ? 1 : temp );
	int j=0;
	if(state[(i+1)%n]!=EATING && state[(i+(n-1))%n]!=EATING && state[i]==HUNGRY)
	{
		state[i]=EATING;
		printf("\nPhilosopher %d is EATING",i);
		grabfork(i);
		sleep(temp);
		eatcount[i]++;
		
		printf("\nPhilosopher %d has finished EATING",i);
		putfork(i);
		state[i]=THINKING;
		
		pthread_mutex_lock(&lock);
		printf("\n========================================");
        printf("\n\nEat Count : [");
        for (j = 0; j < n; j++)
        {
            printf(" %d", eatcount[j]);
        }
        printf("]");
        printf("\n========================================\n");
        pthread_mutex_unlock(&lock);
    }
}
