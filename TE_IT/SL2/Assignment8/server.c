//required libraries

#include<stdio.h>
#include<stdlib.h>
#include<sys/shm.h>
#include<sys/stat.h>

//Constants declared

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
int shm_removed(int,SHARED_REGION*);


int main(int argc, char *argv[])
{
	int shm_id;
	SHARED_REGION *shm_ptr;
	int i,j,ret_val;
	
	if(argc !=4)
	{
		printf("usage: %s arg1 arg2 arg3: less no of arguments\n", argv[0]);
		exit(-1);
	}
	
	shm_id = shm_init();
	
	if(shm_id == 1)
	{
		printf("server : shmget error\n");
		exit(-1);
	}
	
	shm_ptr = shm_attach(shm_id);
	
	if(shm_ptr == NULL)
	{
		printf("server: shmat error\n");
		exit(-1);
	}
	printf("server : shared region is attached at : %x\n", shm_ptr);
	
	shm_ptr->status = DATA_NOT_FILLED_BY_SERVER;
	
	/* fill up the shared memory region using command line arguments */
	j=1;
	for(i=0; i<SZ ; i++)
	{
		shm_ptr->data[i] = atoi(argv[j]);
		++j;
	}

	// Now set the status as filled

	shm_ptr->status = DATA_FILLED_BY_SERVER;

	//wait for the client to retrieve data

	while(shm_ptr->status!= DATA_TAKEN_BY_CLIENT)
	{
		sleep(1);
		printf("server waiting\n");
	}
	
	printf("client has retrived data");
	
	ret_val = shm_remove(shm_id, shm_ptr);
	
	if(ret_val == -1)
	{
		printf("server:shmctl error \n");
		exit(-1);
	}
	return 0;
}

key_t getkey()
{
	key_t mykey;

mykey = ftok("myid" , 'A');
return mykey;
}

int shm_init()
{
	int shm_id;
	//getkey() -> stat.h
	shm_id = shmget(getkey(),sizeof(SHARED_REGION), IPC_CREAT | 0666);
	if(shm_id  < 0)
	{
		return -1;
	}
	else
		return shm_id;
}

SHARED_REGION *shm_attach(int shm_id)
{
	SHARED_REGION* shm_ptr;
	shm_ptr = (SHARED_REGION*)shmat(shm_id,NULL, 0);
	if((int)shm_ptr == -1)
{
	return NULL;
}
else
	return shm_ptr;
}

int shm_remove(int shm_id , SHARED_REGION* shm_ptr)
{
	int ret_val;
	shmdt((void*)shm_ptr);
	ret_val = shmctl(shm_id , IPC_RMID, NULL);
	if(ret_val < 0)
		return -1;
	else
		return 0;
}
