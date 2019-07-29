//include required libraries

#include<sys/types.h>
#include<sys/wait.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

//function to swap values
void swap(int *xp, int *yp)
{
	  int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
}

//bubble sorting function
int* bubbleSort(int *array)
{
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4-i;j++)
		{
			if(array[j] > array[j+1])
			{
				swap(&array[j],&array[j+1]);
			}
		}
	}
	
	printf(" \nSorted array is : ");
	for(int x=0;x<5;x++)
	{
		printf(" %d ",array[x]);
	}
	printf("\n");
}

int main()
{
	pid_t cpid;//child process id variable
	int array[]={5,8,34,9,12};
	cpid=fork();//fork creates child process
	if(cpid == 0)//if return status = 0 child is running
	{
		printf("child is running \n");
		printf("Child pid is %d \n", getpid());
		bubbleSort(array);
		printf("OLd Parent pid is %d \n", getppid());
		sleep(5);
		printf("New Parent pid is %d \n", getppid());
	}
	if(cpid > 0)//if return status is greater than zero parent is running
	{
		printf("parent is running \n");
		printf("Parent is %d \n", getpid());
		bubbleSort(array);
		sleep(1);
	}
	
	return 0;
	
}
