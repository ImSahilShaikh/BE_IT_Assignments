#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<stdio.h>

typedef struct student
{
	int roll,marks;
	char name[30];
}student;

void createFile()
{
	int fd=open("mydb.dat",O_CREAT|O_WRONLY,0777);
	if(fd==-1)
	{
		printf("\nERROR");
	}
	printf("FILE created successfully!");
}
void insertRecords()
{
	student s;
	printf("\nEnter the roll no:");
	scanf("%d",&s.roll);

	printf("\nEnter the name:");
	scanf("%s",&s.name);
	
	printf("\nEnter marks:");
	scanf("%d",&s.marks);
	
	int fd=open("mydb.dat",O_WRONLY | O_APPEND);
	if(fd<0)
		printf("\nError while inserting records");
	else
	{
		write(fd,&s,sizeof(s));
		printf("Records written");
	}
	close(fd);
}
void display()
{
	student s;
	int fd=open("mydb.dat",O_RDONLY);
	if(fd<0)
		printf("ERROR");
	else
	{
		printf("\nROLL NO\tNAME\tMARKS");
		while(read(fd,&s,sizeof(s)))
		{
			printf("\n%d\t%s\t%d",s.roll,s.name,s.marks);
		}
	}
	close(fd);
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
				display();
				break;
			case 4:				
				
				break;
			case 5:
				//modifyRecord();
				break;
			case 6:
				
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
