#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
	printf("[PARENT]  : %d \n",getpid());
	printf("[ROOT]    : %d \n",getppid());
	
	pid_t pid = fork();
	printf("Fork (ID) : %d \n",pid);
	
	if(pid == 0)
	{
		printf("\n\nInside Child Process\n");
		printf("[CHILD]   : %d \n",getpid());
		printf("[PARENT]  : %d \n",getppid());	
		printf("Child is exiting..\n\n");
		//exit(-1);
	}
	
	else
	{
		printf("\n\nInside Parent Process\n");
		
		printf("[PARENT] : %d \n",getpid());
		printf("[ROOT]   : %d \n",getppid());
		
		printf("Parent is Sleeping..\n\n");
		sleep(5);

		printf("[ZOMBIE] : %d \n",getpid());

		wait(NULL);
		exit(-1);
	}
	return 0;	
}
