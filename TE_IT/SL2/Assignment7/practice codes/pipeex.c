#include<unistd.h>
#include<stdio.h>

int main()
{
  //pipe descriptor
	int f[2];
  //variable for keeping track of processid
	int pid;
  //buffer
	int readvar[5];
	
  //creating pipe
	pipe(f);
  //creating new process
	pid=fork();
	
  //if fork fails to create new process
	if(pid<0)
	{
		printf("\nERROR: Can't create new process! ERROR in fork!!");
	}
	
  //parent process
	if(pid>0)
	{
		printf("\nParent process RUNNING!");
		
		printf("\nEnter a number: ");
		scanf("%d",&readvar);
		
    //closing reading end of pipe for parent to write
    close(f[0]);
    
    //writing entered number to buffer
		write(f[1],readvar,sizeof(readvar));
		
    //closing pipe
    close(f);
	}
  
  //child process
	if(pid==0)
	{
		printf("\nChild process RUNNING!");
		
    //closing writinh end of pipe for child to read
		close(f[1]);
    
    //reading the number from buffer
		read(f[0],&readvar,sizeof(readvar));
		printf("\nEntered number is: %d",readvar[0]);
		
    //closing pipe
    close(f);
	}
}
