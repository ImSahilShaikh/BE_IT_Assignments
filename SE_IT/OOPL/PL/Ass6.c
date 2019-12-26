//Sahil A Shaikh
#include<stdio.h>
#include<string.h>
struct stud
{
	char name[20];
	int rollno;
};
void insert(struct stud s[10],int no)
{
	int i;
	for(i=0;i<c;i++)
	{
		printf("Enter Roll No.\n");
  		scanf("%d",&s[i].rollno);
		printf("Enter Name\n");
		scanf("%s",s[i].name);
 	}
}
void display(struct stud s[10],int no)
{
	int i;
	printf("RollNo\tName\n");
	for(i=0;i<c;i++)
    	printf("%d\t%s\n",s[i].rollno,s[i].name);
}
int bub_sort(struct stud s[10],int no)
{
	struct stud temp;
	int i,j,count=0;
	for(i=0;i<c-1;i++)
	{
		for(j=0;j<c-1-i;j++)
		{
       		if(s[j].rollno > s[j+1].rollno)
       		{
			 temp= s[j];
			 s[j]=s[j+1];
			 s[j+1]=temp;
       		}
    		}
		count++;
  	}
	printf("\nAfter Sorting\n");
	display(s,c);
	return count;
}
int sel_sort(struct stud s[10],int n)
{
	int i,j,min_i,count=0;
	struct stud temp;
	char str[10];
	for(i=0;i<n;i++)
	{
		min_i=i;
		strcpy(str,s[i].name);
		for(j=i+1;j<n;j++)
		{
			if(strcmp(str,s[j].name) > 0)
			{
				strcpy(str,s[j].name);
				min_i=j;
			}
		}
		if(min_i!=i)
		{
			temp=s[i];
			s[i]=s[min_i];
			s[min_i]=temp;
		}
		count++;
	}
	printf("After Sorting\n");
	display(s,n);
	return count;
}
void bin_search(struct stud s[10],int first,int last,int x)
{
	int mid;
	mid=(first+last)/2;
	while(first<=last)
	{
		if(s[mid].rollno < x)
		first = mid+1;
		else if(s[mid].rollno == x)
		{
			printf("%d found at location %d\n",x,(mid)+1);
			break;
    		}
    		else
		last= mid-1;
		mid = (first+last)/2;
	}
	if(first>last)
	printf("%d is not found\n",x);
}
void main()
{
	int no_of_entries,choice,x,pass1,pass2;
	struct stud s[10];
	printf("\nEnter Number of entries\n");
	scanf("%d",&no_of_entries);
	insert(s,no_of_entries);
	display(s,no_of_entries);
	do
	{
  		printf("\n1. Bubble Sort (Sorting By Roll No.)\n2. Selection Sort (Sorting by Name)\n3. Binary Search (Search using Roll No)\n4. Exit\n");
		printf("Enter your choice\n");
		scanf("%d",&choice);
		switch(choice)
  		{
			case 1:pass1=bub_sort(s,no_of_entries);
			printf("Number of passes = %d\n",pass1);
			break;
			case 2:pass2=sel_sort(s,no_of_entries);
			printf("Number of passes = %d\n",pass2);
			break;
			case 3:printf("Enter a roll no. to be searched\n");
			scanf("%d",&x);
			bin_search(s,0,no_of_entries,x);
			break;
			case 4:break;
			default: printf("Enter proper choice\n");
		}
	}while(choice!=4);
}
