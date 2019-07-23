/*
Name		 : Sahil A. Shaikh
Class		 : TE-11
Roll.no.	 : 33364
Problem Statement: 1. Implement the C program in which main program accepts the integers to be sorted.
		     Main program uses the FORK system call to create a new process called a child
		     process. Parent process sorts the integers using sorting algorithm and waits for child
		     process using WAIT system call to sort the integers using any sorting algorithm.
		     Also demonstrate zombie and orphan states.
		   2. Implement the C program in which main program accepts an integer array. Main
		     program uses the FORK system call to create a new process called a child process.
		     Parent process sorts an integer array and passes the sorted array to child process
		     through the command line arguments of EXECVE system call. The child process
		     uses EXECVE system call to load new program that uses this sorted array for
		     performing the binary search to search the particular item in the array.	
*/
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//swap two elements
void swap(int* a, int* b) 
{ 
    int t = *a;
    *a = *b; 
    *b = t; 
}


int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high];	//assume last index element as pivote

    int i = (low - 1);
    for (int j = low; j <= high- 1; j++)	//iterate thr array
    { 
        if (arr[j] <= pivot) 		//arrange elements according to pivote
        { 
            i++;
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
}
  
void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        int pi = partition(arr, low, high); 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 


int main()
{
	int fd[2];	//for pipe
	int pid,sum,n,i,j;
	char str[sizeof(int)];
	char *ar[10];
	

	printf("Enter no of array elements(max 10): ");
	scanf("%d",&n);
	
	int nos[n];
	
	while(n>10 || n<1)
	{
		printf("Enter valid no of array elements(max 10): ");
		scanf("%d",&n);
	}
//accept array elements	
	printf("Enter array elements: \n");
	for(i=0;i<n;i++)
		scanf("%d",&nos[i]);
	
	//create pipe descriptor
	pipe(fd);
	
	
	pid=fork();
	
	if(pid<0)
	{
		printf("ERROR IN FORK\n");
	}
	
	if(pid==0)
	{
		printf("Child is running\nCalling execv\n");
//call quicksort on array		
//		quickSort(nos, 0, n-1);
//convert the sorted integer array to char * array

		close(fd[1]);
		read(fd[0],nos,sizeof(nos));


		for(i=0;i<n;i++)
		{
			snprintf(str,sizeof(int),"%d",nos[i]);
			ar[i] = malloc(sizeof(str));
			strcpy(ar[i],str);
		}
		
		
		
		ar[i] = NULL;
		
		close(fd[0]);
		
//pass the converted array to next code
		execv("./p2",ar);
				
		//printf("\n\t\tTHIS SHOUDNT EXECUTE\n");
	}
	if(pid>0)
	{
		printf("Parent is running\n");
		
//call quicksort on array		
		quickSort(nos, 0, n-1);		
		
		close(fd[0]);
		write(fd[1],nos,sizeof(nos));
		close(fd[1]); 	
		
		wait(NULL);
		exit(0);
	}
	
	return 0;
}
