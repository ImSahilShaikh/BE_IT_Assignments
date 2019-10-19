#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void sort(int num[],int size)
{
	int i=0,j=0;
	int temp=0;
	for(i=0;i<size-1;i++)
	{
		for(j=0;j<size-i-1;j++)
		{
			if(num[j]>num[j+1])
			{
				temp=num[j];
				num[j]=num[j+1];
				num[j+1]=temp;		
			}
		}
	}
	printf("\nSorted Elements");
	for( i=0;i<size;i++)
	{
		printf("%d\t",num[i]);
	}
}


int main(int argc, char *argv[])
{
	int size,i,num[20];
	char rst[4],*array[10];
	printf("\nEnter Size");
	scanf("%d",&size);
	printf("\nEnter elements");
	for(i=0;i<size;i++)
	{
		scanf("%d",&num[i]);	
	}
	sort(num,size);
		
	pid_t pid=fork();
	
	if(pid<0)
	{
		printf("\nFork failure");
	}
	else if(pid == 0 )
	{
		printf("\nThis is child block");
		for(i=0;i<size;i++)
		{
			//rst=malloc(sizeof(int));
			sprintf(rst,"%d",num[i]);
			array[i]=malloc(sizeof(int));
			strcpy(array[i],rst);	
		}
		array[i+1]='\0';
		printf("calling exec..");
		execv("./p2",array);
//		printf("\n\nFAILED");		
	}
	else 
	{
		printf("\nThis is parent");
		wait(NULL);
	}
		
	return 0;
}
