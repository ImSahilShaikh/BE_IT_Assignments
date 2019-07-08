#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
int main(int argc, char *argv[])
{
	int pid;
	pid=fork();
	
	if(pid==0)
	{
		printf("\nChild is running\n");
		printf("\nChild process id is: %d\n",getpid());
		printf("\nOld Parent of child is: %d\n",getppid());
		sleep(5);
		printf("\nNew Parent of child is: %d\n",getppid());
	}
	else
	{
		printf("\nParent is running\n");
		sleep(1);
		printf("\nParent of child(PID) is: %d\n",getpid());
		printf("\nPPID: %d\n",getppid());
	}
	return 0;	
}

