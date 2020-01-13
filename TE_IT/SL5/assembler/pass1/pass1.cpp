/*			LC : manually calculated
START 400
READ X 			400
READ Y			401
MOVER AREG,X		402
ADD AREG,Y		403
MOVEM AREG,Z		404
MULT AREG,='5'		405	409
MOVEM CREG,='6'		406	410
SUM AREG,A		407
COMP AREG,ONE		408
LTORG
PRINT Z			411
STOP			412
X DS 100		512
Y DS 2			514
ONE DC '0'		515
Z DS 3			518
A DS 1			519
END
*/

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
	string literal; //actual literal
	int address; //address of the literal
}littab[20];

//structure to maintain symbol table
struct symbol_table{
	string symbol; //symbol
	int address; //address of sybmol
	int length; //length of the symbol
}symtab[20];

//array to maintain pool table
int pooltab[20];

//all iterator variables for structures
int symtab_i=0,littab_i=0,litpool_i=0,pooltab_i=0;


//Following functions are used for tokenization return -1 if no proper keyword is found
int isMnemonic(string word,struct keyword k);
int isAD(string word,struct keyword k);
int isDL(string word,struct keyword k);
int isReg(string word,struct keyword k);
int isLiteral(string word);
int isNumber(string word);
void print_symbol_table(struct symbol_table symtab[]);
void print_literal_pool(string literal_pool[]);
void print_literal_table(struct literal_table littab[]);
void print_pool_table(int pool_table[]);

//all keywords are called in this function
int isKey(string word,struct keyword k);

//this function is used to check for duplicate labels in the symbol table
bool isSym(string word,struct symbol_table symtab[])
{
	for(int sym_check=0;sym_check<symtab_i;sym_check++)
	{
		if(!symtab[sym_check].symbol.compare(word))
		{
			return false;
		}
	}
	return true;
}

//main function
int main()
{
	//variable declaration
	
	//structure for all available keyword arrays
	struct keyword k;
	//structure array for symbol table
	struct symbol_table symtab[20];
	//structure array for literal table
	struct literal_table littab[20];

	int LC=0; //Location counter
	
	int lp_to_lt_i=0; //iterator for pushing literals from literal pool to literal table
	
	//all flag variables are here
	bool lc_flag=0, ds_flag=0,end_flag=0,ltorg_flag=0,symbol_flag=0; //lc_flag used to assign proper address to LC
	
	string word; //buffer to store seperated words
	char c;//buffer for all characters to be stored in buffer of word
	
	//fstream object to operate the code file and output ic file
	fstream file,out;
	
	//ic code file i.e output file is opened here
	out.open("intermediate_code.txt" , ios :: out);
	if(!out)
		cout<<"\nERROR: CANNOT OPEN FILE";
	else
		cout<<"\nINFO: Output File opened!!"<<endl;
	
	//input assembly code file is opened here
	file.open("pass1.txt");
	if(!file)
		cout<<"\nERROR: CANNOT OPEN FILE";
	else
		cout<<"\nINFO:Code File opened!!"<<endl;
	
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
			//if the word encountered is Declarative statement then set the ds_flag and decrement lc by one
			if(word=="DS")
			{
				ds_flag=1;
				LC--;
			}
			//if declarative flag is set and word is number add the constant to the lc
			if(ds_flag && isNumber(word))
			{
				LC=LC+(atoi(word.c_str()));
			}
			//if newline is encountered in input code write same in output ic code file
			if(c=='\n')
			{
				out<<"\n";
			}
			if(isSym(word,symtab)==0)
			{
				symbol_flag=1;
			}
			for(int i=0;i<symtab_i;i++)
			{
				if(symbol_flag && ds_flag )//&& symtab[i].address==0)
				{
					if(word==symtab[i].symbol)
					{
						symtab[i].address=LC;
					}
				}
			}
			//Increment the Location counter whenever newline is encountered and don't increment when word is assembler directive
			if(c=='\n' && isAD(word,k)!=1)
			{
				if(LC)
					LC++;
					//cout<<"LC for this line is : "<<LC;
			}
			//ltorg_flag to set proper address to literals
			if(word=="LTORG")
			{
				ltorg_flag=1;
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
						//loop to print the instruction opcode
						for(int i=0;i<11;i++)
						{
							if(word==k.mop[i])
							{
								if(i<9)
									out<<"(IS"<<","<<0<<""<<i+1<<")";
								else
									out<<"(IS"<<","<<i+1<<")";
							}
						}
						break;
					case 2:
						cout<<": assembler directive";
						//loop to print the instruction opcode
						for(int i=0;i<6;i++)
						{
							if(word==k.ad[i])
							{
								if(i<9)
									out<<"(AD"<<","<<0<<""<<i+1<<")";
								else
									out<<"(AD"<<","<<i+1<<")";
							}
						}
						break;
					case 3:
						cout<<": declarative statement";
						//loop to print the instruction opcode
						for(int i=0;i<3;i++)
						{
							if(word==k.dl[i])
							{
								if(i<9)
									out<<"(DL"<<","<<0<<""<<i+1<<")";
								else
									out<<"(DL"<<","<<i+1<<")";
							}
						}
						break;
					case 4:
						cout<<": register";
						//loop to print the instruction opcode
						for(int i=0;i<4;i++)
						{
							if(word==k.reg[i])
							{
									out<<"("<<i+1<<")";
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
					out<<"(L,"<<word<<")";
					
					literal_pool[litpool_i]=word;
					litpool_i++;
			}
			else if(ltorg_flag)
			{	
				
				for(lp_to_lt_i ;lp_to_lt_i<litpool_i;lp_to_lt_i++)
				{
					littab[littab_i].index=lp_to_lt_i+1;
					littab[littab_i].literal=literal_pool[lp_to_lt_i];
					littab[littab_i].address=LC;
					
					LC++;
					littab_i++;
					literal_pool[lp_to_lt_i]="";
				}	
				int i;
				pooltab[i]=litpool_i;
				i++;			
			}
			//check that is the encountered word is number i.e constant
			else if(check=isNumber(word)==1)
			{
				out<<"(C,"<<word<<")";
			}
			else
			{
				//if the condition is satified then label is valid symbol and not duplicate
				if(isSym(word,symtab) && ((word[0]!='\'' && word[2]!='\'') || word[0]!='\'' && word[3]!='\''))
				{
					cout<<": Label";
					symtab[symtab_i].symbol=word;
					symtab[symtab_i].address=0;
					symtab[symtab_i].length=1;
					symtab_i++;
				}
				//label is not valid symbol or label is duplicate
				else
				{
					cout<<" : Duplicate Symbol\n";
				}
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
		if(c=='\n')
			cout<<"LC is: "<<LC;
	}
	cout<<"\nLC value is: "<<LC;
	
	//calling print_symbol_table function here
	print_symbol_table(symtab);
	
	//calling print_literal_pool function here
	//print_literal_pool(literal_pool);
	
	//calling print_literal_table function here
	print_literal_table(littab);
	
	//print pool table
	print_pool_table(pooltab);

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
//return 1 if word is literal else return -1
int isLiteral(string word)
{
	if(word[0]=='=' && word[1]=='\'')
	{
		return 1;	
	}
	else 
		return -1;
}
//return 1 if word is number else return -1
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
//function to print symbol table
void print_symbol_table(struct symbol_table symtab[])
{
	cout<<"\n-------------------SYMBOL TABLE-------------------";
	cout<<"\n\tSYMBOL\t\tADDRESS\t\tLENGTH";
	cout<<"\n--------------------------------------------------\n";
	for(int i=0;i<symtab_i;i++)
	{
		cout<<"\n\t"<<symtab[i].symbol<<"\t\t"<<symtab[i].address<<"\t\t"<<symtab[i].length;
	}
	cout<<"\n--------------------------------------------------\n";
}
//function to print literal pool
void print_literal_pool(string literal_pool[])
{
	cout<<"\n-------------------LITERAL POOL-------------------";
	cout<<"\n\n\t\tLITERAL";
	cout<<"\n--------------------------------------------------";
	
	for(int i=0;i<litpool_i;i++)
	{
		cout<<"\n\t\t"<<literal_pool[i];
	}
	cout<<"\n--------------------------------------------------";
}
//function to print literal table
void print_literal_table(struct literal_table littab[])
{
	cout<<"\n-------------------LITERAL TABLE-------------------";
	cout<<"\n\tINDEX\t\tLITERAL\t\tADDRESS";
	cout<<"\n--------------------------------------------------\n";
	for(int i=0;i<littab_i;i++)
	{
		cout<<"\n\t"<<littab[i].index<<"\t\t"<<littab[i].literal<<"\t\t"<<littab[i].address;
	}
	cout<<"\n--------------------------------------------------\n";
}
//function to print pool table
void print_pool_table(int pool_table[])
{
	cout<<"\n-------------------POOL TABLE-------------------";
	cout<<"\n\tINDEX";
	cout<<"\n--------------------------------------------------\n";
	for(int i=0;i<pooltab_i;i++)
	{
		cout<<"\n\t"<<pool_table[i];
	}
	cout<<"\n--------------------------------------------------\n";
}
