/*
 ============================================================================
 Name        : fileoperations.c
 Author      : Sahil Shaikh
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[]) {
	//int i;
	char ch;
	FILE *fp,*fq;
	printf("The number of arguments are %d\n",argc);
	fp=fopen(argv[2],"r");
	fq=fopen(argv[3],"w");
	if(argc==3)
	{
	if(fp==NULL)
	{
		printf("File doesn't exits");
	}
	ch=getc(fp);
	while(ch!=EOF)
	{
		printf("%c",ch);
		ch=getc(fp);
	}
	fclose(fp);
	}
	else if(argc==4)
	{
		/*if(argv[1]!="Copy")
		{
			printf("incorrect argument");
		}*/
		if(fp==NULL || fq==NULL)
		{
			printf("File doesn't exits");
		}
		printf("\nCopied contents are:\n");
		while(ch!=EOF){
				ch=getc(fp);
				putc(ch,fq);
				printf("%c",ch);
		}

			fclose(fp);
			fclose(fq);
	}
	else
	{
		printf("Enter correct arguments");
	}
	return 0;
}
