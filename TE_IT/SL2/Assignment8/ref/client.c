#include<stdio.h>
#include<stdlib.h>
#include<sys/shm.h>
#include<sys/stat.h>

#define SZ 3    //data size
#define DATA_NOT_FILLED_BY_SERVER -1    //if the data area has not yet filled
#define DATA_FILLED_BY_SERVER 0               //if server has filled the data
#define DATA_TAKEN_BY_CLIENT 1

typedef struct mem
{
	int status;
	int data[3];
}SHARED_REGION;

key_t getkey();
int shm_init();
SHARED_REGION *shm_attach(int shm_id);


int main()
{
	int shm_id;
	SHARED_REGION *shm_ptr;
	int i,j,ret_val;
	int client_data[SZ];

	shm_id = shm_init();
	if(shm_id < 0)
	{
		printf("client : shmget error\n");
		exit(-1);
	}

	shm_ptr = shm_attach(shm_id);

	if(shm_ptr == NULL)
	{
		printf("client : error shmat\n");
		exit(-1);
	}
	printf("client : attached to shared memory\n");

	while(shm_ptr -> status == DATA_NOT_FILLED_BY_SERVER)
	{
		;  	//null statement to [rovide looping 
	}

	printf("Now data ready client will get in\n");
	for(i=0; i<SZ ; i++)
	{
		client_data[i] = shm_ptr -> data[i] ;
	}
	printf("All data have been read by the client and data are : \n");

	for(i=0; i<SZ ; i++)
	{
		printf("data[%d] = %d\n", i , client_data[i]);
	}
return 0;
}

// Function definitions 

key_t getkey()
{
	key_t mykey;
	mykey = ftok("myid" , 'A');
	return mykey;
}

int shm_init()
{
	int shm_id;
	shm_id = shmget(getkey() , sizeof(SHARED_REGION), IPC_CREAT | 0666);
	if(shm_id < 0)
	{
		return -1;
	}
	else
		return shm_id;
}

SHARED_REGION *shm_attach(int shm_id)
{
	SHARED_REGION* shm_ptr;
	shm_ptr = (SHARED_REGION*)shmat(shm_id, NULL , 0);
	if((int)shm_ptr == -1)
		return NULL;
	else
		return shm_ptr;
}
