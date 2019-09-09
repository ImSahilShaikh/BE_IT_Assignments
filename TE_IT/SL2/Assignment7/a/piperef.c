#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
void main()
{
    FILE *fptr;
    char buffer[20];;
    pid_t pid;
    char c;
    char str[100],str1[20];	
    int fd1[2],fd2[2];
    pipe(fd1);
    pipe(fd2);
    pid=fork();
    if(pid<0)
    {
        perror("fork()");
    }
    else if(pid>0)
    {
        printf("\nParent Process\n");
        printf("\nParent:Transferring File To Child Process\n");
        close(fd1[0]);
        write(fd1[1],"file.txt",20);
        close(fd1[1]);
        
        close(fd2[1]);
        read(fd2[0],buffer,20);
        close(fd2[0]);
        printf("\nParent:File Recieved\n");
        printf("\nParent:Contents Of the File %s Are As Follows\n",buffer);
        fptr=fopen(buffer,"r");     
        fgets(str1,100,fptr);
		printf("%s \n",str1);
        exit(0);
        
    }
    else
    {
    
        printf("\nWelcome To Child Process\n");
        close(fd1[1]);
        read(fd1[0],buffer,20);
        close(fd1[0]);
        printf("\nChild:File Recieved\n");
       // fptr=fopen(buffer,"a+");
		fptr=fopen("file.txt","+a");
		printf("\nEnter a Message!!\t");
		gets(str);
        fputs(str,fptr);
        printf("\nChild:Contents Successfully Written To File %s\n",buffer);
        printf("\nChild:Transferring File To Parent Process\n");
        close(fd2[0]);
        write(fd2[1],buffer,20);
        close(fd2[1]);
        
    }
}
 
