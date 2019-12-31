#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<fstream>
#include<string.h>

using namespace std;

string mop[]={"STOP","ADD","MULT","MOVER","MOVEM","COMP","BC","DIV","READ","PRINT"};
string ad[]={"START","END","LTORG","ORIGIN","EQU"};
string dl[]={"DS","DC"};
string reg[]={"AREG","BREG","CREG","DREG"};

//return 1 if word is mnemonic op code else return 0
int isMnemonic(string word)
{
	for(int i=0;i<11;i++)
	{
		if(!strcmp(word.c_str(),mop[i].c_str()))
		{
			cout<<"This is word"<<word<<"This is mnemonic"<<mop[i];
			return 1;
		}
		return 0;
	}
}
//return 2 if word is assembler directive else return 0
int isAD(string word)
{
	for(int i=0;i<6;i++)
	{
		if(!strcmp(word.c_str(),ad[i].c_str()))
			return 2;
		return 0;
	}
}
//return 3 if word is declarative statement else return 0
int isDL(string word)
{
	for(int i=0;i<=2;i++)
	{
		if(!strcmp(word.c_str(),dl[i].c_str()))
			return 3;
		return 0;
	}		
		
}
//return 4 if word is register else return 0
int isReg(string word)
{
	for(int i=0;i<5;i++)
	{
		if(!strcmp(word.c_str(),reg[i].c_str()))
			return 4;
		return 0;
	}
}

int main()
{
	int LC=0;
	string word;
	int count=0;
	char c;
	fstream file;
	
	file.open("pass1.txt");
	if(file==NULL)
		cout<<"\nERROR: CANNOT OPEN FILE";
	else
		cout<<"\nINFO: File opened!!"<<endl;
	
	string myword="ADD";
	int a=isMnemonic(myword);
	cout<<a;
	
	while(file.get(c))
	{
		//initialse word to empty string to reset value of variable word
		word="";
		//check for new word i.e when space,comma,new line or tab is encountered it is treated as new word
		if(c==' ' || c==',' || c=='\n' || c=='\t')
		{
			/*int i=isMnemonic(word);
			cout<<i;
			if((i=isMnemonic(word))==1)
			{
				cout<<"The word: "<<word <<" is mnemonic opcode!";
			}
			else if(isAD(word)==2)
			{
				cout<<"The word: "<<word <<" is assembler directive!";
			}
			else if(isDL(word)==3)
			{
				cout<<"The word: "<<word <<" is declarative statement!";
			}*/
		}
		word+=c;
		cout<<word;
		if(!strcmp(word.c_str(),"END"))
			break;
	}
}
