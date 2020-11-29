//Header files
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

//Function for swapping
int swap(int *a,int *b){

		int temp = *a;
		*a = *b;
		*b = temp;
}

//Function for bubble sort
void bubble_sort(int *num,int n)
{
	int i=0,j=0;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(num[j] > num[j+1])
			{
					swap(num+j,num+j+1);
			}
		}
	}
}

//Main function 
int main(int argc,char *argv[])
{
	//Declaring Variables
	int *num,pid,n = 0,i = 0;
	char *rst,*array[10];
	
	//Taking Total Number Of Elements From User	
	printf("\n\nEnter The Number Of Elements: ");
	scanf("%d",&n);
	printf("\n");

	//Assigning Memory To Array
	num = malloc(n*sizeof(int));
	
	//Taking Array Elements From User
	for(i = 0;i< n;i++){
		printf("Enter Number %d: ",(i+1));
		scanf("%d",num+i);
	}

	printf("\nINFO: Parent Is Sorting The Data");

	//Calling Bubble Sort Function
	bubble_sort(num,n);
	printf("\nINFO: Parent Waiting For Child Process Completion");

	//Creating New Child Process
	pid=fork();
		
	//Assigning Task to Child	
	if(pid == 0)
	{
		printf("\nINFO: Child Process Id: %d",getpid());
		printf("\nINFO: Childs Parent Process Id: %d",getppid());					
				
		//Converting Integer To String
		for(i = 0;i<n;i++)
		{
			rst = (char *)malloc(sizeof(int));
			sprintf(rst,"%d",num[i]);
			array[i] = (char *)malloc(sizeof(int));
			array[i] = rst;
		}
		array[i]=NULL;
	    printf("\n Calling execv");
		execv("./p2",array);
	}
	//Remaining code from parent	
	else
	{
		printf("\nINFO: Parent Process Id in pid (greater than 0): %d",getpid());
		wait(NULL);
	}
}