#include<stdio.h>
int main()
{
	//declaration of filepointer
	FILE *fp,*fop;
	//buffer variable to store the character and display
	char c='\0';
	
	int word=0,lines=0,characters=0,s;
	
	//open file using fopen
	// use second paramater as w to write if file exist, if not creates new file
	// use second paramater as r to read from the existing file

	//fp=fopen("sahil.txt","w");
	
	fp=fopen("sahil.txt","r");
	
	if(fp==NULL)
		printf("\nWARNING: Failed to open the file");
	else
		printf("\nINFO: File opened");
		printf("\nINFO: Reading from the file");
		printf("\n--------------File contents--------------\n\n");
		//copy the file contents into buffer c till EOF
		while((c=fgetc(fp))!=EOF)
		{
			//character count increments as we are reading file character by character
			characters++;
			//wordcount if space next line or tab is encountered
			if(c==' '||c=='\n'||c=='\t')
				word++;
			//line count if newline is encountered
			if(c=='\n')
				lines++;
			//print the contents of buffer
			printf("%c",c);			
		}
	printf("\n-----------------------------------------");
	printf("\nINFO: Data readed from the file successfully!!");	
	//close file using argument filepointer
	fclose(fp);

	printf("\nINFO: File Closed");
	printf("\n\n*********SUMMARY*********\n1)Characters: %d\n2)Words: %d\n3)Lines: %d\n*************************",characters,word,lines);	
	
	fop=fopen("fileinfo.dat","w");
	if(fop==NULL)
		printf("\nWARNING: Failed to open the file");
	else
		printf("\nINFO: File opened");
		printf("\nINFO: Writing in the file");
		s=fprintf(fop,"*********SUMMARY*********\n1)Characters: %d\n2)Words: %d\n3)Lines: %d\n*************************",characters,word,lines);
		
		printf("\nINFO: File Closed");
	fclose(fop);	
	return 0;
}
