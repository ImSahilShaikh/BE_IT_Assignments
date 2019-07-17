#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

char *msg={"First thread argument"};

void *tDemo(void *arg)
{
	printf("\nInside child thread");
	printf("\nArgument=%s",(char*)arg);
	pthread_exit("\nExiting from the child thread");
}

int main()
{
	int res;
	pthread_t tid;
	void *tres;
	printf("\nInside Main");
	res=pthread_create(&tid,NULL,tDemo,(void *)msg);
	if(res!=0)
	{
		printf("\nError in creating thread");
		exit(EXIT_FAILURE);
	}
	printf("\nJoining Child Thread");
	res=pthread_join(tid,&res);
	if(res!=0)
	{
		printf("\nError in child joining");
		exit(EXIT_FAILURE);
	}
	printf("\nBack to main");
	printf("\nChild sent %s msg",(char*)msg);
	exit(EXIT_SUCCESS);
}
