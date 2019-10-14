/*
	Roll Number : 33315
	Batch		: K-11
	Aim 		: File handling system calls.
		  		  Write a C program to update the details of student using C low level library functions for file handling
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

//Structure to Store Stundet data
struct Student
{
	int roll;
	char name[20];
	char dept[30];
}s;

//Insert data in File
void insert(int in)
{
	struct Student s1;
	printf("\nENter Roll Number :");
	scanf("%d",&s1.roll);
	
	printf("\nEnter Name :");
	scanf("%s",s1.name);
	
	printf("\nEnter Department :");
	scanf("%s",s1.dept);
	
	write(in, &s1, sizeof(s1));
}

//Display data from file
void display()
{
	int out = open("in.dat", O_RDONLY, S_IRUSR|S_IWUSR|S_IXUSR|S_IRGRP|S_IWGRP|S_IXGRP|S_IROTH|S_IWOTH|S_IXOTH);
	struct Student s1;
	int flag = 1;
	printf("\nRoll Number \t Name \t\t Department");
	printf("\n---------------------------------------------");
	while(read(out, &s1, sizeof(s1)))
	{
		printf("\n  %d\t\t",s1.roll);
		printf("  %s",s1.name);
		printf("\t\t %s",s1.dept);
		flag = 0;
	}
	if(flag)
	{
		printf("\nPlease Insert data in file..");
	}
}

//Search data from file
void search(int key)
{
	int out = open("in.dat", O_RDONLY, S_IRUSR|S_IWUSR|S_IXUSR|S_IRGRP|S_IWGRP|S_IXGRP|S_IROTH|S_IWOTH|S_IXOTH);
	int flag = 0;
	struct Student s1;
	printf("\nRoll Number \t Name \t\t Department");
	printf("\n--------------------------------------------");
	while(read(out, &s1, sizeof(s1)))
	{
		if(s1.roll == key)
		{
			printf("\n  %d\t\t",s1.roll);
			printf("  %s",s1.name);
			printf("\t\t %s",s1.dept);
			flag = 1;
		}
	}
	if(!flag)
	{
		printf("\nSorry, No records found!!");
	}
}

//Update record
void update(int key)
{
	int out = open("in.dat", O_RDWR, S_IRUSR|S_IWUSR|S_IXUSR|S_IRGRP|S_IWGRP|S_IXGRP|S_IROTH|S_IWOTH|S_IXOTH);
	int tmp = open("tmp.dat", O_RDWR | O_CREAT, S_IRUSR|S_IWUSR|S_IXUSR|S_IRGRP|S_IWGRP|S_IXGRP|S_IROTH|S_IWOTH|S_IXOTH);
	int flag = 0;
	struct Student s1;
	while(read(out, &s1, sizeof(s1)))
	{
		if(s1.roll == key)
		{
			printf("\nEnter new name:");
			scanf("%s",s1.name);
			printf("\nEnter new department:");
			scanf("%s",s1.dept);
			flag = 1;
		}
		write(tmp, &s1, sizeof(s1));
	}
	if(!flag)
	{
		printf("\nSorry, No records found!!");
		remove("in.dat");
	}
	else
	{
		remove("in.dat");
		rename("tmp.dat","in.dat");
		printf("\nRecord Updated Successfully..");
	}
}

//Delte record from file
void delete(int key)
{
	int out = open("in.dat", O_RDWR, S_IRUSR|S_IWUSR|S_IXUSR|S_IRGRP|S_IWGRP|S_IXGRP|S_IROTH|S_IWOTH|S_IXOTH);
	int tmp = open("tmp.dat", O_RDWR | O_CREAT, S_IRUSR|S_IWUSR|S_IXUSR|S_IRGRP|S_IWGRP|S_IXGRP|S_IROTH|S_IWOTH|S_IXOTH);
	int flag = 0;
	struct Student s1;
	while(read(out, &s1, sizeof(s1)))
	{
		if(s1.roll == key)
		{
			flag = 1;
			continue;
		}
		write(tmp, &s1, sizeof(s1));
	}
	if(!flag)
	{
		printf("\nSorry, No records found!!");
		remove("in.dat");
	}
	else
	{
		remove("in.dat");
		rename("tmp.dat","in.dat");
		printf("\nRecord Deleted Successfully..");
	}
}

int main()
{
	int in, sz, ch, key = 0;
	struct Student s1;
	in  = open("in.dat", O_RDWR | O_CREAT, S_IRUSR|S_IWUSR|S_IXUSR|S_IRGRP|S_IWGRP|S_IXGRP|S_IROTH|S_IWOTH|S_IXOTH);// All permissions (RD,WR,EX)
	 
	do
	{
		printf("\n\n-------------------FILE HANDLING--------------------");
		printf("\n-> 1.Insert Data\n\n-> 2.Display Data\n\n-> 3.Search\n\n-> 4.Update\n\n-> 5.Delete\n\n-> 6.Exit");
		printf("\n----------------------------------------------------");
		printf("\nEnter your choice:");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
				insert(in);
				break;
			case 2:
				display();
				break;
			case 3: 
				printf("\nEnter roll number to be searched:");
				scanf("%d",&key);
				search(key);
				break;
			case 4:
				printf("\nEnter roll number for Updation of data:");
				scanf("%d",&key);
				update(key);
				break;
			case 5:
				printf("\nEnter roll number for Deletion of data:");
				scanf("%d",&key);
				delete(key);
				break;
			default:
				break;
		}
		
	}while(ch!=6);
	
	return 0;
}
