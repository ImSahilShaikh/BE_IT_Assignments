//header files

#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<fstream>
#include<string>
#include<ctype.h>

using namespace std;

//structure for all keywords
struct keyword{

//various keyword array for comparison

string mop[13]={"STOP","ADD","SUB","MULT","MOVER","MOVEM","COMP","BC","DIV","READ","PRINT","STORE","LOAD"}; //STRING ARRAY for machine opcode
string ad[6]={"START","END","EQU","ORIGIN","LTORG"}; //STRING ARRAY for assembler directive
string reg[5]={"AREG","BREG","CREG","DREG"}; //STRING ARRAY for registers
string dl[3]={"DS","DC"}; //STRING ARRAY for declarative statements
}k;

//literal pool
string literal_pool[10];

//structure for literal table
struct literal_table{
	int index; //index
	string lit; //actual literal
	int addresss; //address of the literal
}littab[20];

//structure for symbol table
struct symbol_table{
	string symbol; //symbol
	int address; //address of sybmol
	int length; //length of the symbol
}symtab[20];

// pool table
int pooltab[20];

//tokenization
//Following functions return -1 if no proper keyword is found
int isMnemonic(string word,struct keyword k);
int isAD(string word,struct keyword k);
int isDL(string word,struct keyword k);
int isReg(string word,struct keyword k);
int isLiteral(string word);
int isNumber(string word);

//all keywords are called in this function
int isKey(string word,struct keyword k);

//main function
int main()
{
	struct keyword k;
	int LC=0;
	string word;
	int count=0;
	char c;
	fstream file;
	
	file.open("pass1.txt");
	if(!file)
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
			
			//function isKey() is called for tokenization
			int check=isKey(word,k);
			if(check!=-1)
			{
				switch(check)
				{
					case 1:
						cout<<": mnemonic opcode";
						for(int i=0;i<11;i++)
						{
							if(word==k.mop[i])
							{
								if(i<9)
									cout<<0<<""<<i+1;
								else
									cout<<i+1;
							}
						}
						break;
					case 2:
						cout<<": assembler directive";
						for(int i=0;i<6;i++)
						{
							if(word==k.ad[i])
							{
								if(i<9)
									cout<<0<<""<<i+1;
								else
									cout<<i+1;
							}
						}
						break;
					case 3:
						cout<<": declarative statement";
						for(int i=0;i<3;i++)
						{
							if(word==k.mop[i])
							{
								if(i<9)
									cout<<0<<""<<i+1;
								else
									cout<<i+1;
							}
						}
						break;
					case 4:
						cout<<": register";
						for(int i=0;i<4;i++)
						{
							if(word==k.reg[i])
							{
								if(i<9)
									cout<<0<<""<<i+1;
								else
									cout<<i+1;
							}
						}
						break;
					default:
						break;
				}
			}
			//literals are checked here
			else if(check=isLiteral(word)==1)
			{
					cout<<": literal";	
			}
			else if(check=isNumber(word)==1)
			{
				cout<<": Number(constant)";
			}
			else
			{
				cout<<": Label";
			}
			if(word == "END")
				break;
			//initialse word to empty string to reset value of variable word				
			word = "";			
		}
		//add characters to word till this condition is satisfied
		if(c!=' ' && c!=',' && c!='\n' && c!='\t')
			word+=c;
	}
}
//return 1 if word is mnemonic op code else return -1
int isMnemonic(string word,struct keyword k)
{
	for(int i=0;i<14;i++)
	{		
		//alternative if condition can be word==k.mop[i]
		if(!strcmp(word.c_str(),k.mop[i].c_str()))
		{	
			return 1;
		}
	}
	return -1;
}
//return 1 if word is assembler directive else return -1
int isAD(string word,struct keyword k)
{
	for(int i=0;i<6;i++)
	{
		if(!strcmp(word.c_str(),k.ad[i].c_str()))
			return 1;	
	}
	return -1;
}
//return 1 if word is declarative statement else return -1
int isDL(string word,struct keyword k)
{
	for(int i=0;i<3;i++)
	{
		if(!strcmp(word.c_str(),k.dl[i].c_str()))
			return 1;
	}		
	return -1;	
}
//return 1 if word is register else return -1
int isReg(string word,struct keyword k)
{
	for(int i=0;i<4;i++)
	{
		if(!strcmp(word.c_str(),k.reg[i].c_str()))
			return 1;
	}
	return -1;
}
int isLiteral(string word)
{
	if(word[0]=='=' && word[1]=='\'')
	{
		return 1;	
	}
	else 
		return -1;
}
int isNumber(string word)
{
	int flag=0;
	for(int i=0;i<word.length();i++)
	{
		if(isdigit(word[i])==false)
		{
			return -1;
		}
		else
			return 1;
	}
}
//all the functions to check various keywords are available in this function
int isKey(string word, struct keyword k)
{
	//return 1 if keyword is mnemonic opcode
	if(isMnemonic(word,k)==1)
		return 1;
	//return 2 if keyword is assembler directive
	if(isAD(word,k)==1)
		return 2;
	//return 3 if keyword is declarative statement
	if(isDL(word,k)==1)
		return 3;
	//return 4 if keyword is register
	if(isReg(word,k)==1)
		return 4;
	//return -1 if no proper keyword is found
	else
		return -1;
}
