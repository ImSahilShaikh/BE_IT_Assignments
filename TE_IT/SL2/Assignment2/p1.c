#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void swap(int* a, int* b) 
{ 
    int t = *a;
    *a = *b; 
    *b = t; 
}

int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high];

    int i = (low - 1);
    for (int j = low; j <= high- 1; j++)
    { 
        if (arr[j] <= pivot) 
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
	int pid,sum,n,i,j;
	char str[sizeof(int)];
	char *ar[10];
	int nos[n];

	printf("Enter no of array elements(max 10): ");
	scanf("%d",&n);
	
	while(n>10 || n<1)
	{
		printf("Enter valid no of array elements(max 10): ");
		scanf("%d",&n);
	}
	
	printf("Enter array elements: \n");
	for(i=0;i<n;i++)
		scanf("%d",&nos[i]);
	
	pid=fork();
	
	if(pid<0)
	{
		printf("ERROR IN FORK\n");
	}
	
	if(pid==0)
	{
		printf("Child is running\nCalling execv\n");
		
		quickSort(nos, 0, n-1);
		
		for(i=0;i<n;i++)
		{
			snprintf(str,sizeof(int),"%d",nos[i]);
			ar[i] = malloc(sizeof(str));
			strcpy(ar[i],str);
		}
		
		ar[i] = NULL;

		execv("./p2",ar);
		
		//printf("\n\t\tTHIS SHOUDNT EXECUTE\n");
	}
	if(pid>0)
	{
		printf("Parent is running\n");
		wait(&pid);
		exit(0);
	}
	
	return 0;
}

/*

	
*/
