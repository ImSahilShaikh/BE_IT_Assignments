#include<sys/wait.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

int main()
{
	int i,j,k, pipefd1[2],pipefd2[2],cnt;
	pid_t cpid;
	char buf;
    char filew[30],filer[30],contr[40],contw[40];
	
	if (pipe(pipefd1) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	if (pipe(pipefd2) == -1)
	{
    	perror("pipe");
        exit(EXIT_FAILURE);
	}

    cpid = fork(); //Fork child process

	if (cpid == -1)
	{
		perror("fork");
        exit(EXIT_FAILURE);
	}

	//Child Process
	if (cpid == 0) 
	{    
		/* Child reads from pipe */
		close(pipefd1[1]);          /* Close unused write end */
		cnt=0;
		while (read(pipefd1[0], &buf, 1) > 0)
		filer[cnt++]=buf;
		filer[cnt]='\0';
               
		close(pipefd1[0]); //closing pipe after completion of task

		FILE *fp;
		fp=fopen(filer,"r"); //Open the specified file
		cnt=0;
		buf=fgetc(fp);
		while(buf!=EOF)
		{
			contr[cnt++]=buf;
			buf=fgetc(fp);
		}
		contr[cnt]='\0';

		printf("\nThe file content is:(Child)");
		for(i=0;i<strlen(contr);i++)
		{
			printf("%c",contr[i]);
		}
		printf("\n");
		close(pipefd2[0]);
		write(pipefd2[1], contr, strlen(contr));
		close(pipefd2[1]); 
		//_exit(EXIT_SUCCESS);
	} 
	//Parent 
	else
	{
		printf("\nEnter the file name & path:");
		scanf("%s",filew);
              
		/* Parent writes argv[1] to pipe */
		close(pipefd1[0]);/* Close unused read end */
              
		write(pipefd1[1], filew, strlen(filew));
		close(pipefd1[1]);          /* Reader will see EOF */

		//wait(NULL);                /* Wait for child */

		//exit(EXIT_SUCCESS);

		close(pipefd2[1]);
		cnt=0;
		while (read(pipefd2[0], &buf, 1) > 0)
			contw[cnt++]=buf;
		contw[cnt]='\0';

		printf("\nThe file content is:(Parent)");
		for(i=0;i<strlen(contw);i++)
		{
			printf("%c",contw[i]);
		}
		close(pipefd2[0]);
	}
	return 0;
}
