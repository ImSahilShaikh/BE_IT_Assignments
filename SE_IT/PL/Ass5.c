
/*
 ============================================================================
 Name        : SequentialFile.c
 Author      : Sahil Shaikh(23376)
 Version     :Database Operations On Sequential File
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct student
{
    int Roll_No;
    char name[50],year[50],div[30];
    float percent;
};

void writeFile(struct student stud)
{
int i,n=0;
FILE *fp;
    fp=fopen("studentInfo.txt","a");
    if(fp==NULL)
    {
        printf("can't create file");
        exit(1);
    }
    printf("\nHow Many Records You Want to Enter:=");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\nEnter Student's Roll_No := ");
        scanf("%d",&stud.Roll_No);

        printf("\nEnter Student's Name := ");
        scanf("%s",&stud.name);

        printf("\nEnter Student's Percent := ");
        scanf("%f",&stud.percent);

        printf("\nEnter Student's Learning Year := ");
        scanf("%s",&stud.year);

        printf("\nEnter Student's Division := ");
        scanf("%s",&stud.div);

        printf("\n---------------------------------------------\n");
        fprintf(fp,"%3d  %s  %0.2f  %s  %s\n",stud.Roll_No,stud.name,stud.percent,stud.year,stud.div);
    }
    printf("\nData Successfully Saved.");
    fclose(fp);
}

void readFile()
{
    char ch;
    int Roll_No;
    char name[50],year[50],div[50];
    float percent;
    FILE *inFile;
    inFile=fopen("studentInfo.txt","r");

    printf("\n------------------------------------------------------------------------------------");
    printf("\nRoll_No\t\tName\t\tPercent\t\tLearning Year\t\tDivision");
    printf("\n------------------------------------------------------------------------------------");
    while(fscanf(inFile,"%d\t%s\t%f\t%s\t%s",&Roll_No,&name,&percent,&year,&div) != EOF)
    {
            printf("\n%2d \t\t%s \t\t%0.2f \t\t    %s \t\t\t%s",Roll_No,name,percent,year,div);
            printf("\n------------------------------------------------------------------------------------");

    }
    fclose(inFile);

}

void searchFile()
{
    FILE *inFile;
    int Roll,Roll_No;
    char name[50],year[50],div[50];
    float percent;

    inFile=fopen("studentInfo.txt","r");

    printf("\nEnter The Roll_No To Search Data := ");
    scanf("%d",&Roll);

    while(fscanf(inFile,"%d\t%s\t%f\t%s\t%s",&Roll_No,&name,&percent,&year,&div) != EOF)
    {
        if(Roll == Roll_No)
        {
            printf("\n------------------------------------------------------------------------------------");
            printf("\nRoll_No\t\tName\t\tPercent\t\tLearning Year\t\tDivision");
            printf("\n------------------------------------------------------------------------------------");
            printf("\n%2d \t\t%s \t\t%0.2f \t\t    %s \t\t\t%s",Roll_No,name,percent,year,div);
            printf("\n------------------------------------------------------------------------------------");

        }
        else
        {
            if(feof(inFile))
            {
                    printf("\nThere Is No Data Present With Roll_No %2d ",Roll);
            }

        }

    }
    fclose(inFile);
}

void modifyAllRecord()
{

    FILE *inFile,*outFile;
    int Roll=0,Roll_No=0;
    char name[20],div[10],year[20];
    float percent;
    int flag=0;
    inFile = fopen("studentInfo.txt","r+");
    outFile = fopen("new.txt","w+");
    printf("\nEnter Student Roll_No Which Records You Want To Modify :");
    scanf("%d",&Roll);
    while(fscanf(inFile,"%d\t%s\t%f\t%s\t%s",&Roll_No,&name,&percent,&year,&div) != EOF)
    {
        if(Roll == Roll_No)
        {
            printf("\nEnter Student's Name := ");
            scanf("%s",&name);

            printf("\nEnter Student's Percent := ");
            scanf("%f",&percent);

            printf("\nEnter Student's Learning Year := ");
            scanf("%s",&year);

            printf("\nEnter Student's Division := ");
            scanf("%s",&div);

            printf("\n---------------------------------------------\n");
            fprintf(outFile,"%3d  %s  %0.2f  %s  %s\n",Roll_No,name,percent,year,div);
            printf("\nData Successfully Modified.");
            flag = 1;
            continue;
        }
        fprintf(outFile,"%3d  %s  %0.2f  %s  %s\n",Roll_No,name,percent,year,div);

    }
    if(!flag)
        {
            printf("\nThere Is No Data Present With Roll_No %2d ",Roll);
        }
    fclose(inFile);
    fclose(outFile);
    remove("studentInfo.txt");
    rename("new.txt","studentInfo.txt");
}

void deleteRecord()
{

    FILE *inFile,*outFile;
    int Roll=0,Roll_No=0;
    char name[20],div[10],year[20];
    float percent;
    int flag=0;
    inFile = fopen("studentInfo.txt","r+");
    outFile = fopen("new.txt","w+");
    printf("\nEnter Student Roll_No Which Record Delete :");
    scanf("%d",&Roll);
    while(fscanf(inFile,"%d\t%s\t%f\t%s\t%s",&Roll_No,&name,&percent,&year,&div) != EOF)
    {
        if(Roll == Roll_No)
        {
            flag = 1;
            continue;
        }
        fprintf(outFile,"%3d  %s  %0.2f  %s  %s\n",Roll_No,name,percent,year,div);
    }
    if(!flag)
    {
      printf("\nThere Is No Data Present With Roll_No %2d ",Roll);
    }
    fclose(inFile);
    fclose(outFile);
    remove("studentInfo.txt");
    rename("new.txt","studentInfo.txt");
}


int main(void) {
	int choice,c1;
    struct student stud;
	do
	{
		printf("\n--------------------------------------");
		printf("\n1 --> Add Record In a File.\n2 --> Display Record.\n3 --> Search For Record.\n4 --> Modify Record.\n5 --> Delete Record.\n6 --> Exit");
		printf("\n--------------------------------------");
		printf("\nEnter Your Choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
		   case 1:
                    writeFile(stud);
                    break;
		   case 2:
                    readFile();
                    break;
		   case 3:
                    searchFile();
			       break;
		   case 4:
                    modifyAllRecord();
			       break;
		   case 5:
                   deleteRecord();
			       break;
		   case 6:
			      return 0;
		   default:
			       printf("\n Please Enter Valid Choice");
		}
	}while(choice != 6);
	return EXIT_SUCCESS;
}
