#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<fstream>
#include<string>

using namespace std;
//string mop[]={"ADD"};
//various keyword array for comparison
string mop[12]={"STOP","ADD","MULT","MOVER","MOVEM","COMP","BC","DIV","READ","PRINT"}; //STRING ARRAY for machine opcode
string ad[5]={"START","END","LTORG","ORIGIN","EQU"}; //STRING ARRAY for assembler directive
string dl[2]={"DS","DC"}; //STRING ARRAY for declarative statements
string reg[4]={"AREG","BREG","CREG","DREG"}; //STRING ARRAY for registers

//tokenization
/*Following functions return -1 if no proper key found */
int isMnemonic(string word);
int isAD(string word);
int isDL(string word);
int isReg(string word);
int isKey(string word);

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
	//Reading file character by character
	while(file.get(c))
	{
	
		//check for new word i.e when space,comma,new line or tab is encountered it is treated as new word
		if(c==' ' || c==',' || c=='\n' || c=='\t')
		{
			cout<<endl<<word;
			int check_mnemonic=isMnemonic(word);
			{
			if(check_mnemonic ==1)
				cout<<"mnemonic: "<<check_mnemonic;
			}
			int check_ad=isAD(word);
			if(check_ad ==1)
				cout<<"ad: "<<check_ad;
			
			int check_reg=isReg(word);
			if(check_reg==1)	
				cout<<"reg : "<<check_reg<<endl;
			
			int check_dl=isDL(word);
			if(check_dl==1)
				cout<<"dl : "<<check_dl;
			
			//initialse word to empty string to reset value of variable word				
			word="";
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
		if(c!=' ' && c!=',' && c!='\n' && c!='\t')
			word+=c;

//		cout<<word;

		if(!strcmp(word.c_str(),"END"))
			break;
	}
}
//return 1 if word is mnemonic op code else return -1
int isMnemonic(string word)
{
	for(int i=0;i<11;i++)
	{		
		if(strcmp(word.c_str(),mop[i].c_str())==0)
		{	
			return 1;
		}
	}
	//cout<<"a"<<word<<"a\n";
	return -1;
}
//return 1 if word is assembler directive else return -1
int isAD(string word)
{
	for(int i=0;i<6;i++)
	{
		if(!strcmp(word.c_str(),ad[i].c_str()))
			return 1;
		
	}
	return -1;
}
//return 1 if word is declarative statement else return -1
int isDL(string word)
{
	for(int i=0;i<=2;i++)
	{
		if(!strcmp(word.c_str(),dl[i].c_str()))
			return 1;
	}		
	return -1;	
}
//return 1 if word is register else return -1
int isReg(string word)
{
	for(int i=0;i<4;i++)
	{
		if(!strcmp(word.c_str(),reg[i].c_str()))
			return 1;
	}
	return -1;
}
int isKey(string word)
{
	//returns 1 if the key is mnemonic opcode
	if((int check=isMnemonic(word))==1)
	{
		return 1;
	}
	//return 2 if the key is assembler directive
	else if(int check=isAD(word)==1)
	{
		return 2;
	}
	//return 3 if the key is declarative statement
	else if(int check=isDL(word)==1)
	{
		return 3;
	}
	//return 4 if the key is register
	else if(int check=isReg(word)==1)
	{
		return 4;
	}
	else
	//return -1 if no proper key is found
		return -1;
}
