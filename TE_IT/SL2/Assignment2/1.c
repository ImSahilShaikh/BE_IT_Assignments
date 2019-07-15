#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main()//int argc, char*argv[])
{
	int a,b,res;
	
	printf("Enter a: ");
	scanf("%d",&a);
	
	printf("Enter b: ");
	scanf("%d",&b);

	res = a+b;
	char* myarg[50];
	char string[50];	
	
	int pid,i;
	pid=fork();
		
	

	if(pid<0)
	{
		printf("\nINFO:ERROR IN FORK");
	}
	
	else if(pid==0)
	{
		sprintf(string,"%d",res);
		myarg[0]=string;
		myarg[1]=NULL;
		//printf("HAHAHA\nExecuting execv()\nHAHAHAHHAHAHAHAHAHAH");
		execv("./2",myarg);
		printf("\nAfter execv()");
	}
	
	else
	{
		//res=a+b;
	}
	return 0;
}
