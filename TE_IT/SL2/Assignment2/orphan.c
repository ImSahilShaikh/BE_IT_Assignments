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
	
	int a[]={1,3,5,7,9};
	
	int bubblesort(int array[])
	{
		for(int i=0;i<4;i++)
		{
			for(int j=0;j<4-i;j++)
			{
				if(array[j]>array[j+1])
				{
					int temp=array[j];
					array[j]=array[j+1];
					array[j+1]=temp;
				}
			}
		}
		printf("\nINFO: The sorted array is: ");
		for(int i=0;i<5;i++)
		{
			printf("\n%d",array[i]);
		}
	}
	
	if(pid==0)
	{
		printf("\nChild is running\n");
		printf("\nChild process id is: %d\n",getpid());
		printf("\nOld Parent of child is: %d\n",getppid());
		bubblesort(a);
		sleep(5);
		printf("\nNew Parent of child is: %d\n",getppid());
	}
	else
	{
		printf("\nParent is running\n");
		bubblesort(a);
		sleep(1);
		printf("\nParent of child(PID) is: %d\n",getpid());
		printf("\nPPID: %d\n",getppid());
	}
	return 0;	
}

