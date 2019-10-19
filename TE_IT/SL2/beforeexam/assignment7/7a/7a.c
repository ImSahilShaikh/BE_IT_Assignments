#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include<fcntl.h>

int main()
{
	int p1[2],p2[2],file;
	char buffer[50],filename[50];
	pid_t pid;
	
	pipe(p1);
	pipe(p2);
	
	pid=fork();
	
	if(pid<0)
		printf("\nFork Error");
	else if(pid>0)
	{
		close(p1[0]);
		
		printf("Enter the filename: ");
		scanf("%s",filename);
		
		write(p1[1],filename,sizeof(filename));
		printf("Parent sent %s file to child using pipe1",filename);
		
		close(p1[1]);
		

		close(p2[1]);
		read(p2[0],buffer,20);
		
		printf("\nData read by parent: %s\n",buffer);
		close(p2[0]);
	}
	else if(pid==0)
	{
		close(p1[1]);
		read(p1[0],filename,sizeof(filename));
		
		file=open(filename,O_RDONLY);
		read(file,buffer,sizeof(buffer));
		
		printf("\nChild is sending string %s to parent through pipe2",buffer);
		

		close(p2[0]);
		write(p2[1],buffer,sizeof(buffer));
		close(p2[1]);
		
	}
}
