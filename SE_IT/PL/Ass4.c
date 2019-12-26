#include<stdio.h>
//#include<conio.h>
struct data
{
	int rollno;
	char name[20];
	int age;
	int per;
};

void create(struct data d[10], int i)
{
	printf("\nStudent No.: %d\n",i+1);
	printf("Enter Roll No: ");
	scanf("%d",&d[i].rollno);
	printf("Enter Name: ");
	scanf("%s",d[i].name);
	printf("Enter Age: ");
	scanf("%d",&d[i].age);
	printf("Enter Percentage: ");
	scanf("%d",&d[i].per);
}
void display(struct data d[10],int i)
{
	printf("%d\t\t%s\t%d\t%d\n",d[i].rollno,d[i].name,d[i].age,d[i].per);
}

void add(struct data d[4],int c)
{
	printf("\nAdd the datails\n");
	printf("\nStudent No.: %d\n",c);
	printf("Enter Roll No: ");
	scanf("%d",&d[c-1].rollno);
	printf("Enter Name: ");
	scanf("%s",d[c-1].name);
	printf("Enter Age: ");
	scanf("%d",&d[c-1].age);
	printf("Enter Percentage: ");
	scanf("%d",&d[c-1].per);
}

void search(struct data d[10],int r,int entry)
{
	int i,flag=0;
 	for(i=0;i<entry;i++)
 	{
  		if(r==d[i].rollno)
  		{
			printf("\nSerach Found\n");
			printf("Roll No.\tName\tAge\tPercent\n");
			printf("%d\t\t%s\t%d\t%d\n",d[i].rollno,d[i].name,d[i].age,d[i].per);
			flag=1;
  		}
	}
 		if(flag==0)
		printf("Search Not Found\n");
}
void modify(struct data d[10],int r, int entry)
{
	int i,flag=0;
	for(i=0;i<entry;i++)
 	{
		if(r==d[i].rollno)
		{
			printf("\nStudent No.: %d\n",i+1);
		   	printf("Enter Roll No: ");
		   	scanf("%d",&d[i].rollno);
		   	printf("Enter Name: ");
		   	scanf("%s",d[i].name);
		   	printf("Enter Age: ");
		   	scanf("%d",&d[i].age);
		   	printf("Enter Percentage: ");
		   	scanf("%d",&d[i].per);
		   	flag=1;
  		}
 	}
	if(flag==0)
	printf("Roll No. Not Found\n");
}
int delete(struct data d[10],int r,int entry)
{
	int i,flag=0,str;
	for(i=0;i<entry;i++)
	{
  		if(r==d[i].rollno)
  		{
   			str=i;
   			flag=1;
			break;
   		}
  	}
	if(flag==1)
	{
		printf("Record is deleted\n");
    		entry--;
    		for(i=str;i<entry;i++)
    		{
     		d[i]=d[i+1];
    		}
  	}
  	else
  	printf("Record can not be deelted given roll no. not found\n");
	return entry;
}

void main()
{
	struct data d[100];
	int choice,i,count=0,entry=0,ser;
	do
	{
		printf("\n1.Insert Data\n2.Display Data\n3.Add Data\n4.Search a Record\n5.Modify a Record\n6.Delete a Record\n");
		printf("\nEnter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1: printf("Enter the number of entries\n");
		scanf("%d",&entry);
		for(i=0;i<entry;i++)
		{
		create(d,i);
		count++;
	   	}
	   	break;
		case 2: printf("Roll No.\tName\tAge\tPercent\n");
		for(i=0;i<entry;i++)
		{
			display(d,i);
		}
	  	break;
	 	case 3: add(d,count+1);
		entry++;
		count++;
		break;
	 	case 4:printf("\nEnter a roll no. to be searched\n");
		scanf("%d",&ser);
		search(d,ser,entry);
		break;
	 	case 5:printf("\nEnter a roll no. which you want to modify\n");
		scanf("%d",&ser);
		modify(d,ser,entry);
		break;
	 	case 6:printf("\nEnter a roll no. which you want to delete\n");
		scanf("%d",&ser);
		entry=delete(d,ser,entry);
		break;

   }
   }while(choice<7);
}
