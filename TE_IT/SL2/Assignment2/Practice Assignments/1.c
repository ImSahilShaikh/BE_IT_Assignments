#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char*argv[])
{
	int a,b,res;
	
	printf("Enter a: ");
	scanf("%d",&a);
	
	printf("Enter b: ");
	scanf("%d",&b);

	int pid,i;
	pid=fork();
		

	//char *const arg[2]={"hello","world"};
	if(pid<0)
	{
		printf("\nINFO:ERROR IN FORK");
	}
	else if(pid==0)
	{
		printf("HAHAHA\nExecuting execv()\nHAHAHAHHAHAHAHAHAHAH");
		execv("./2",argv);
		printf("\nAfter execv()");
	}
	else
	{
		res=a+b;
	}
	return 0;
}
