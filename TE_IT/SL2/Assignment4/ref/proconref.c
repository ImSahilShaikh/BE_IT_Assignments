#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>
#define MAX 5

int buf[MAX], p, c, i, j, in = 0, out = 0;	//in is read pointer out is write pointer
sem_t full,empty;
pthread_mutex_t mu;


void buf_disp(){	
	printf("BUFFER--> [ ");
	for (int i = 0;i<MAX;i++)
		printf("%d ",buf[i]);
	
	printf("]");
}

int buf_write(){
	buf[out] = (rand() % 10 + 1);
	out = (out+1)%MAX;
	return 1;
}

int buf_read(){
	buf[in]	= 0;
	in = (in+1) % MAX; 
	return 1;
}


void *producer(void *no)
{
	printf("\nProducer %d Created\n",(int *)no);
	int er=1;
	//srand(time(0));
	while(1){
		//printf("In producer loop\n");
		sleep(rand() % 10 + 1);
		
		sem_wait(&empty);
		
		er = pthread_mutex_lock(&mu);
		if(er!=0){
			printf("ERROR IN MUTEX LOCKING ABORTING!");
			pthread_exit("Abort");
		}
			
		//printf("\tgoing to write\n");			
		//critical section
		buf_write();
		printf("\n\tProducer %d has Written \t\t",(int *)no);
		buf_disp();
						
		er = pthread_mutex_unlock(&mu);
		if(er!=0){
			printf("\n\t\tERROR IN MUTEX UNLOCKING ABORTING!");
			pthread_exit("Abort");
		}
		
		sem_post(&full);
	
	}
	pthread_exit("Successfull execution of producer");
}
void *consumer(void *no){
	int er=0;
	printf("\nConsumer %d Created\n",(int *)no);
	//srand(time(0));
	while(1){
	
		sem_wait(&full);
		
		er = pthread_mutex_lock(&mu);
		if(er!=0){
			printf("\n\t\tERROR IN MUTEX LOCKING ABORTING!");
			pthread_exit("Abort");
		}
						
		//critical section
		buf_read();
		printf("\n\tConsumer %d has read\t\t",(int *)no);
		buf_disp();
						
		er = pthread_mutex_unlock(&mu);
		if(er!=0){
			printf("\n\t\tERROR IN MUTEX UNLOCKING ABORTING!");
			pthread_exit("Abort");
		}
		
		sem_post(&empty);	
		sleep(rand() % 10 + 1);
	}
	pthread_exit("Successfull execution of consumer");
}

int main(){
	int er = 0;
	
	printf("Entre no of producers: ");
	scanf("%d", &p);
	printf("Enter no of consumers: ");
	scanf("%d", &c);
	
	printf("\n");
	
	pthread_t pro[p],con[c];
	void *trp[p*c];
	
	//initialize and display buffer
	for(i = 0;i<MAX;i++)
		buf[i]=0;	
	buf_disp();

	printf("\n");

	//initialize the semaphores
	er = sem_init(&empty, 0, MAX);
	if(er != 0){
		printf("Semaphore creation of empty failed aborting!");
		return 0;
	}

	er = sem_init(&full, 0, 0);
	if(er != 0){
		printf("Semaphore creation of full failed aborting!");
		return 0;
	}
	
	//initialize the mutex
	er  = pthread_mutex_init(&mu, NULL);
	if(er != 0){
		printf("MUTEX creation failed aborting!");
		return 0;
	}
	
	//Create producers
	for(i = 0; i < p; i++){
		er = pthread_create(&pro[i],NULL,producer,(void *)i);
		if(er != 0){
			printf("Producer %d creation failed aborting!",i);
			return 0;
		}
	}
	//Create consumers
	for(i = 0; i < c; i++){
		er = pthread_create(&con[i],NULL,consumer,(void *)i);
		if(er != 0){
			printf("Consumer %d creation failed aborting!",i);
			return 0;
		}	
	}
	
	//join producers
	for(i = 0; i < p; i++){
		er = pthread_join(pro[i],&trp[i]);
		if(er != 0){
			printf("Producer %d joining failed aborting!",i);
			return 0;
		}	
	}
	//join consumers
	for(i = 0; i < c; i++){
		er = pthread_join(con[i],&trp[i]);
		if(er != 0){
			printf("Consumer %d Joining failed aborting!",i);
			return 0;
		}	
	}
	
	return 0;
}
