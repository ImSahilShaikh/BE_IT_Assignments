#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<fstream>

using namespace std;

int main()
{
	string mnemonics[]={"ADD","MOVEM","READ","PRINT","MOVER"};
	string word;
	char c;
	fstream file;
	
	file.open("pass1.txt");
	if(file==NULL)
		cout<<"\nERROR: CANNOT OPEN FILE";
	else
		cout<<"\nINFO: File opened!!";
	
	while(file.getc(c))
	{
		if(c==' ' || c==',' || c=='\n' || c=='\t')
		{
			word++;
		}
		word+=c;
	}
	
}
