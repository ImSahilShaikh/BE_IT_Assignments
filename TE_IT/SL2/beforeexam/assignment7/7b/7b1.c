#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
	int fd1, fd2;
	int words,lines,characters;
	words=lines=characters=0;
	
	int result[3];
	char buff[50];
	
	char *p1="parent";
	char *p2="child";
	
	mkfifo(p1,0777);
	
	fd1=open(p1,O_RDWR);
	
	printf("\nEnter into file");
	fgets(buff,50,stdin);
	
	printf("%s",buff);
	
	write(fd1,buff,sizeof(buff));
	close(fd1);
	
	fd2=open(p2,O_RDWR);
	read(fd2,result,sizeof(result));
	
	printf("\nWords: %d",result[0]);
	printf("\nCharacters: %d",result[1]);
	printf("\nLines: %d",result[2]);
	
	close(fd2);
	return 0;
}
