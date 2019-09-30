#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>

typedef struct 
{
	int roll,marks;
	char name[30],dept[10];

}student;

void createFile()
{
	int file_id=open("student_database.txt",O_CREAT|O_WRONLY, 0777);	
	if(file_id==-1)
	{
		printf("ERROR: Cannot open/create file!");
	}
	else
		printf("NOTE: File created Successfully!");
}

void insertRecords()
{
	
}

int main()
{
	int ch=0;
	while(1)
	{
		printf("\n------------STUDENT DATABASE------------");
		printf("\nWelcome.");
		printf("\n------------MENU------------");
		printf("\n1.Create File\n2.Insert Records\n3.Display Records\n4.Search Records\n5.Modify Records\n6.Delete Records\n7.Truncate All records\n8.Delete Database\n9.Exit");
		printf("\n----------------------------");
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
	
		switch(ch)
		{
			case 1:
				createFile();
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:		
				break;
			case 6:
				break;
			case 7:
				break;
			case 8:
				break;
			case 9:
				exit (0);
				break;
		}
	}
}
