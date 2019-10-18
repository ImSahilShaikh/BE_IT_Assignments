
#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>

void bubble_sort(int a[10],int n)
{
	int i=0,j=0;
	int temp=0;
	
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	printf("\nSorted Array : \n");
	for(i=0;i<n;i++)
	{	
		printf("%d\t",a[i]);	
	} 
}

int main()
{
	int num[10];
	int i=0, n;
	printf("\n[parent]: %d",getpid());
	printf("\n[root]: %d",getppid());
	printf("\nEnter how many elements you want to enter: \n");
	scanf("%d",&n);
	printf("\nEnter elements: ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&num[i]);
	}
	pid_t pid=fork();
	if(pid==-1)
	{	
		printf("Error in creating new process");
		
	}
	else if(pid==0)
	{
		printf("This is child block");
		printf("\nSorting in child");
		printf("\n[child]: %d",getpid());
		printf("\n[parent]: %d",getppid());
		bubble_sort(num,n);
		sleep(10);
		printf("\nAfter parent exits");
		printf("\n[child]: %d",getpid());
		printf("\n[parent]: %d",getppid());

	}
	else
	{
		//sleep(5);
		printf("This is parent block");	
		printf("\nSorting in parent");
		bubble_sort(num,n);
		//ait(NULL);
		printf("\n[parent]: %d",getpid());
		printf("\n[root]: %d",getppid());
		printf("\nParent Exits");

	}

}
