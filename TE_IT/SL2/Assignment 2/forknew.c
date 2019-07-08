#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
int main() 
{ 
    pid_t pid;
    int ch;
    printf("Parent process\n");
    printf("PID for parent is ::%d\n",getpid());
    
    printf("\tCHOICE :: 1.Orphan\t2.Zombie");
	scanf("%d",&ch);
      
    printf("Forking now !!!");
    pid=fork();
    
    if(pid<0)
    {
    	printf("\nError ");
    	return 0;
    }
    else if (pid==0)
    {
    	printf("\nChild process");
 		printf("\nPID for child :: %d",getpid());
 		printf("\nPPID for child :: %d",getppid());
    
		
		
		if(ch==1)
		{
			printf("Child is sleeping ");
			sleep(10);
			printf("\n New PID for child :: %d",getpid());
	 		printf("\n New PPID for child :: %d",getppid());
	 		    	
		}
		system("ps -elf | grep a.out");
    }
    else
    {
    	system("wait");
    	printf("PID for parent is ::%d\n",getpid());
    	if (ch==2)
    	{
    		printf("Parent is sleeping ");
    		sleep(10);
    	}
    	system("ps -elf | grep a.out");
    }
    return 0; 
} 
