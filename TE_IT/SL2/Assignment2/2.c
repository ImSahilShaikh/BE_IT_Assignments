#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
int main(int argc,char *argv[])
{
	
	printf("\nARGC is:%d",argc);
	printf("\n The argv1:%s",(argv[0]));
	printf("\n The argv1:%s",atoi(argv[1]));
	
	return 0;
}
