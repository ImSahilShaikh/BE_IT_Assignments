#include<iostream>
#include<vector>
#include<fstream>

using namespace std;

int symtab_i=0,littab_i=0;


struct symbol_table{
	int index;
	string symbol;
	int address;
}symtab[20];

struct literal_table{
	int index;
	string literal;
	int address;
}littab[20];

void readSymbolTable()
{
	vector<string> buff;
	fstream symbol;
	char c;
	string word;
	
	symbol.open("symbol_table.txt");
	
	if(!symbol)
		cout<<"\nWARNING: No symbol table found";
	
	while(symbol.get(c))
	{
		if(c=='\n' || c=='\t')
		{
			buff.push_back(word);
			word="";
			if(c=='\n')
			{
				if(buff.size()>=4)
				{
					symtab[symtab_i].index=atoi((buff.at(1)).c_str());
					symtab[symtab_i].symbol=buff.at(2);
					symtab[symtab_i].address=atoi((buff.at(3)).c_str());
					symtab_i++;
				}
			}
			buff.clear();
		}
		else
			word+=c;
	}
}
void readLiteralTable()
{
	vector<string> buff;
	fstream literal;
	char c;
	string word;
	
	literal.open("literal_table.txt");
	
	if(!literal)
		cout<<"\nWARNING: No literal table found";
		
	while(literal.get(c))
	{
		if(c=='\n' || c=='\t')
		{
			buff.push_back(word);
			word="";
			if(c=='\n')
			{
				if(buff.size()>=4)
				{
					littab[littab_i].index=atoi((buff.at(1)).c_str());
					littab[littab_i].literal=buff.at(2);
					littab[littab_i].address=atoi((buff.at(3)).c_str());
					littab_i++;
				}
			}
			buff.clear();
		}
		else
			word+=c;
	}
}
int symInd(int index)
{
	int add = symtab[index-1].address;
	return add;
}
int litInd(int index)
{
	int add = littab[index-1].address;
	return add;
}
int main()
{
	fstream ic,machine;
	
	readSymbolTable();
	readLiteralTable();
	
	vector<string> temp;
	char c;
	string word;
	
	ic.open("ic.txt");
	machine.open("machine_code.txt",ios::out);
	
	int a=0;
	
	if(!ic)
		cout<<"\nWARNING: No intermediate code found";
	
	while(ic.get(c))
	{
		if(c=='(' || c==' ')
		{	
			continue;
		}
		if(c=='\n' || c=='\t' || c=='(' || c==',' || c==')' || c=='|')
		{
			temp.push_back(word);
			word="";
			if(c=='\n')
			{
				if(temp.size()==7)
				{
					if(!temp.at(1).compare("AD"))
						machine << "\n--\t\t--\t\t--\t\t--";
					else if(!temp.at(1).compare("IS"))
					{
						int address=0;
						if(!temp.at(3).compare("S"))
						{
							address = symInd(atoi((temp.at(4)).c_str()));
							machine <<"\n"<< temp.at(0)<<"\t\t"<<temp.at(2)<<"\t\t"<<temp.at(3)<<"\t\t"<<address;
						}
						else
						{
							address = litInd(atoi((temp.at(4)).c_str()));
							machine <<"\n"<< temp.at(0)<<"\t\t"<<temp.at(2)<<"\t\t"<<temp.at(3)<<"\t\t"<<address;
						}
					}
					else
					{
						machine << "\n--\t\t--\t\t--\t\t--";
					}
				}
				if(temp.size()==6)
				{
					if(!temp.at(1).compare("AD"))
						machine << "\n--\t\t--\t\t--\t\t--";
					else if(!temp.at(1).compare("IS"))
					{
						int address=0;
						if(!temp.at(3).compare("S"))
						{
							address = symInd(atoi((temp.at(4)).c_str()));
							machine <<"\n"<< temp.at(0)<<"\t\t"<<temp.at(2)<<"\t\t--\t\t"<<address;
						}
						else
						{
							address = litInd(atoi((temp.at(4)).c_str()));
							machine <<"\n"<< temp.at(0)<<"\t\t"<<temp.at(2)<<"\t\t--\t\t"<<address;
						}
					}
					else
					{
						machine << "\n--\t\t--\t\t--\t\t--";
					}
				}
				if(temp.size()==4)
				{
					if(!temp.at(1).compare("AD"))
					{
						machine << "\n--\t--\t--\t--";
					}
					else if(!temp.at(1).compare("IS"))
					{
						machine<<"\n"<<temp.at(0)<<"\t\t"<<temp.at(2)<<"\t\t--\t\t--\n\n";
					}
					else
					{
						machine << "\n--\t\t--\t\t--\t\t--";
					}	
				}
				temp.clear();
			}
		}
		else
			word+=c;
		a=1;
	}
	cout<<a;
	return 0;
}
