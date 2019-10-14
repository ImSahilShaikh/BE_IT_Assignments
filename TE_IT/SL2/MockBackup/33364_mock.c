/*
NAME: SAHIL SHAIKH
ROLL NO: 33364
PROBLEM STATEMENT: File handling using System calls
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>

struct student{
	int roll, marks;
	char name[30];
};

void createFile()
{
	int file_id = open("student_database.txt",O_CREAT|O_WRONLY,0777);
	if(file_id==-1)
		printf("\nERROR: Unable to create file!!!!");
	printf("INFO: File created successfully!!");
	close(file_id);
}
void insertRecords()
{
	int file_id = open("student_database.txt",O_WRONLY|O_APPEND,0777);
	struct student s;
	printf("\n-------------------ENTER STUDENT DETAILS-------------------");
	printf("\nEnter ROLL_NO: ");
	scanf("%d", &s.roll);
	printf("\nEnter Name: ");
	scanf("%s", s.name);
	printf("\nEnter Marks(in percent): ");
	scanf("%d", &s.marks);
	write(file_id, &s, sizeof(s));
}
void displayRecords()
{
	int file_id = open("student_database.txt",O_RDONLY,0777);
	struct student s;
	int flag = 1;
	printf("\nROLL NUMBER \t NAME \t\t MARKS");
	printf("\n---------------------------------------------");
	while(read(file_id, &s, sizeof(s)))
	{
		printf("\n  %d\t\t",s.roll);
		printf("  %s",s.name);
		printf("\t\t %d",s.marks);
		flag = 0;
	}
	if(flag==0)
	{
		printf("\nPlease Insert data in file..");
	}

}
void searchRecord()
{
	int file_id = open("student_database.txt", O_RDONLY,0777);
	int flag = 0,key=0;
	struct student s;
	printf("\nEnter the ROLL NO you want to search: ");				
	scanf("%d",&key);
	
	while(read(file_id, &s, sizeof(s)))
	{
		if(s.roll == key)
		{
			printf("\nROLL NUMBER \t NAME \t\t MARKS");
			printf("\n--------------------------------------------");
			printf("\n  %d\t\t",s.roll);
			printf("  %s",s.name);
			printf("\t\t %d",s.marks);
			flag = 1;
		}
	}
	if(flag==0)
	{
		printf("\nSorry, No records found!!");
	}
}
/*
void modifyRecord()
{
	int file_id = open("student_database.txt", O_WRONLY|O_APPEND,0777);
	int file_id2 = open("tmp.txt", O_CREAT|O_WRONLY,0777);
	int flag = 0,key=0;
	struct student s;
	
	printf("\nEnter the ROLL NO you want to search: ");				
	scanf("%d",&key);
	while(read(file_id, &s, sizeof(s)))
	{
		if(s.roll == key)
		{
			printf("\nEnter new name:");
			scanf("%s",s.name);
			printf("\nEnter new marks:");
			scanf("%d",&s.marks);
			flag = 1;
		}
		write(file_id2, &s, sizeof(s));
	}
	if(flag==0)
	{
		printf("\nSorry, No records found!!");
		remove("student_database.txt");
	}
	else
	{
		remove("student_database.txt");
		rename("tmp.txt","student_database.txt");
		printf("\nRecord Updated Successfully..");
	}
}
*/

void deleteRecord()
{
	int file_id = open("student_database.txt", O_WRONLY|O_APPEND,0777);
	int file_id2 = open("tmp.txt", O_CREAT|O_WRONLY,0777);
	int flag = 0,key=0;
	
	printf("\nEnter the ROLL NO you want to delete: ");				
	scanf("%d",&key);
	
	struct student s;
	while(read(file_id, &s, sizeof(s)))
	{
		if(s.roll == key)
		{
			flag = 1;
			continue;
		}
		write(file_id2, &s, sizeof(s));
	}
	if(flag==0)
	{
		printf("\nINFO: No records found!!");
		remove("student_database.txt");
	}
	else
	{
		remove("student_database.txt");
		rename("tmp.txt","student_database.txt");
		printf("\nRecord Deleted Successfully..");
	}
}

int main()
{
	int ch=0;
	while(1)
	{
		printf("\n-------------------STUDENT DATABASE-------------------");
		printf("\n-------------------------MENU-------------------------");
		printf("\n1.Create File\n2.Insert Records\n3.Display records\n4.Search Records\n5.Modify Record\n6.Delete Records\n7.Delete File\n8.Exit");
		printf("\nINFO: Enter Your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				createFile();
				break;
			case 2:
				insertRecords();
				break;
			case 3:
				displayRecords();
				break;
			case 4:				
				searchRecord();
				break;
			case 5:
				//modifyRecord();
				break;
			case 6:
				deleteRecord();
				break;
			case 7:
				remove("student_database.txt");
				printf("\nINFO: FILE DELETED SUCCESSFULLY!!");
				break;	
			case 8:
				exit(0);
			default:
				printf("\nWARNING: Please Enter valid choice!");
		}
	}
}
