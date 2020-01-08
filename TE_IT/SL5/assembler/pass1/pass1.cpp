//header files

#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<fstream>
#include<string>

using namespace std;

//structure for all keywords
struct keyword{
//various keyword array for comparison
	string mop[13]={"STOP","ADD","SUB","MULT","MOVER","MOVEM","COMP","BC","DIV","READ","PRINT","STORE","LOAD"}; //STRING ARRAY for machine opcode
	string ad[6]={"START","END","EQU","ORIGIN","LTORG"}; //STRING ARRAY for assembler directive
	string reg[5]={"AREG","BREG","CREG","DREG"}; //STRING ARRAY for registers
	string dl[3]={"DS","DC"}; //STRING ARRAY for declarative statements
}k;

//string array to maintain literal pool
string literal_pool[10];

//structure to maintain literal table
struct literal_table{
	int index; //index
	string lit; //actual literal
	int addresss; //address of the literal
}littab[20];

//structure to maintain symbol table
struct symbol_table{
	string symbol; //symbol
	int address; //address of sybmol
	int length; //length of the symbol
}symtab[20];

//array to maintain pool table
int pooltab[20];

//tokenization
//Following functions return -1 if no proper keyword is found
int isMnemonic(string word,struct keyword k);
int isAD(string word,struct keyword k);
int isDL(string word,struct keyword k);
int isReg(string word,struct keyword k);
int isLiteral(string word);
int isNumber(string word);
void print_symbol_table();

//all keywords are called in this function
int isKey(string word,struct keyword k);

//main function
int main()
{
	//variable declaration
	
	struct keyword k;
	struct symbol_table symtab[20];
	struct literal_table littab[20];

	int LC=0; //Location counter
	bool lc_flag=0, ds_flag=0,end_flag=0; //lc_flag used to assign proper address to LC
	
	string word; //buffer to store seperated words
	int symtab_i=0,littab_i=0,litpool_i=0,pooltab_i=0; //all iterator variables for structures
	char c;
	//fstream object to operate the file
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
			//set the lc_flag when START is encountered
			if(word=="START")
			{
				lc_flag=true;
			}
			//printing all seperated words
			cout<<endl<<word;
			//check if lc_flag is set and the word is a number			
			
			
			if(lc_flag && isNumber(word) ==1 )
			{
				//convert string to integer
				//assign the given address to LC
				LC=atoi(word.c_str());
				LC-=2;
				//reset the lc_flag
				lc_flag=0;
			}
			if(word=="DS")
			{
				ds_flag=1;
				LC--;
			}
			if(ds_flag && isNumber(word))
			{
				LC=LC+(atoi(word.c_str()));
			}
			
			//Increment the Location counter whenever newline is encountered and don't increment when word is assembler directive
			if(c=='\n' && isAD(word,k)!=1)
			{
				if(LC)
					LC++;
					//cout<<"LC for this line is : "<<LC;
			}
			//function isKey() is called for tokenization
			int check=isKey(word,k);
			//checking for all types of keyword
			if(check!=-1)
			{
				switch(check)
				{
					case 1:
						cout<<": mnemonic opcode";
						//loop to print the insrtuction opcode
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
						//loop to print the insrtuction opcode
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
						//loop to print the insrtuction opcode
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
						//loop to print the insrtuction opcode
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
					
					literal_pool[litpool_i]=word;
					litpool_i++;
			}
			else if(check=isNumber(word)==1)
			{
				cout<<": Number(constant)";
			}
			else
			{
				int i=0;
				if(symtab[i].symbol==word)
				{
					cout<<": Duplicate Label";
					i++;	
				}
				else
				{
					cout<<": Label";
					symtab[symtab_i].symbol=word;
					symtab[symtab_i].address=LC;
					symtab[symtab_i].length=1;
					symtab_i++;
					i++;
				}
				i++;
				
			}			
			if(word == "END")
			{
				break;
				end_flag=1;
			}
			//initialse word to empty string to reset value of variable word				
			word = "";			
		}
		//add characters to word till this condition is satisfied
		if(c!=' ' && c!=',' && c!='\n' && c!='\t')
		{
			word+=c;			
		}
	}
	cout<<"\nLC value is: "<<LC;
	cout<<"\n-------------------SYMBOL TABLE-------------------";
	cout<<"\n\tSYMBOL\t\tADDRESS\t\tLENGTH";
	cout<<"\n--------------------------------------------------";
	
	for(int i=0;i<symtab_i;i++)
	{
		cout<<"\n\t"<<symtab[i].symbol<<"\t\t"<<symtab[i].address<<"\t\t"<<symtab[i].length;
	}
	cout<<"\n--------------------------------------------------";
	
	cout<<"\n-------------------LITERAL POOL-------------------";
	cout<<"\n\tLITERAL";
	cout<<"\n--------------------------------------------------";
	
	for(int i=0;i<litpool_i;i++)
	{
		cout<<"\n\t"<<literal_pool[i];
	}
	cout<<"\n--------------------------------------------------";
	
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
void print_symbol_table(struct symbol_table symtab[])
{
	cout<<"\n-------------------SYMBOL TABLE-------------------";
	cout<<"\n\tSYMBOL\t\tADDRESS\t\tLENGTH";
	for(int i=0;i<symtab[i].symbol.length();i++)
	{
		cout<<symtab[i].symbol<<"\t\t"<<symtab[i].address<<"\t\t"<<symtab[i].length;
	}
}
