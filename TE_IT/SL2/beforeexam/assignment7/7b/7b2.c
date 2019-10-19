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
	
	mkfifo(p2,0777);
	
	fd1=open(p1,O_RDWR);
	
	read(fd1,buff,sizeof(buff));
	close(fd1);
	
	printf("\nFile contents are: %s",buff);
	
	return 0;
}
