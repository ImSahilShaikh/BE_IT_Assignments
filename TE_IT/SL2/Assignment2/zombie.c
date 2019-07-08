#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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

/*void selectionSort(int array[])  
{  
    int i, j, min_idx;  
  
    // One by one move boundary of unsorted subarray  
    for (i = 0; i < 5; i++)  
    {  
        // Find the minimum element in unsorted array  
        min_idx = i;  
        for (j = i+1; j < 5; j++)  
        if (array[j] < array[min_idx])  
            min_idx = j;  
  
        // Swap the found minimum element with the first element  
 				int temp=array[j];
				array[j]=array[j+1];
				array[j+1]=temp; 
    }  
    printf("\nINFO: The sorted array is: ");
	for(int i=0;i<5;i++)
	{
		printf("\n%d",array[i]);
	}
} */ 
 

int main(int argc, char *argv[])
{
	int pid;
	pid=fork();
	
	int a[]={5,4,3,2,1};
	
	
	if(pid==0)
	{
		
		printf("\nChild is running\n");
		printf("\nChild process id is: %d\n",getpid());
		bubblesort(a);
		printf("\nOld Parent of child is: %d\n",getppid());
		sleep(1);
		printf("\nNew Parent of child is: %d\n",getppid());
	}
	else
	{
		printf("\nParent is running\n");
		bubblesort(a);
		sleep(10);
		printf("\nParent of child(PID) is: %d\n",getpid());
		printf("\nPPID: %d\n",getppid());
		wait(NULL);
	}
	return 0;	
}

