#include<iostream>
#include<vector>
#include<fstream>
#include<string.h>
#include<stdlib.h>

using namespace std;

//fstream objects to open various files
fstream ic,literal_table,out;

//variable to keep count of available literals in literal table structure
int lit_count=0;

//stucture declared to store literal table
struct literal_table{
	int index;
	string literal;
	int address;
};

//array of structure
struct literal_table lt[50];

//function to read literal table from file and store into structure
void read_LT()
{
	char buff;

	string word;
	vector<string> temp; 
		
	literal_table.open("literal_table.txt");
	
	while(literal_table.get(buff))
	{
		if(buff=='\t' || buff=='\n')
		{
			temp.push_back(word);

			if(buff=='\n')
			{	
				lt[lit_count].index = atoi(temp[0].c_str());
				lt[lit_count].literal = temp[1];
				lt[lit_count].address = atoi(temp[2].c_str());

				lit_count++; 
				
				/*cout<<"\nINDEX\tLITERAL\tADDRESS";
				for(int i=0;i<lit_count;i++)
				{
					cout<<"\n\n"<<lt[i].index<<"\t"<<lt[i].literal<<"\t"<<lt[i].address;

				}*/
				temp.clear();
			}
			word="";
			//temp.clear();
		}
		if(buff!='\t' && buff!='\n')
		{
			word+=buff;
		}
		
	}
	cout<<"\nNOTE: Literal table reading successful!";
}

int search_Literal(int index)
{
	for(int i=0;i<lit_count;i++)
	{
		if(index==lt[i].index)
		{
			return i;
		}
	}
	return 0;
}

int main()
{
	
	char c;

	string word;
	vector<string> file;
	
	int reg=0;

	cout<<"\nNOTE: Reading Literal Table...";
	read_LT();
	
	cout<<"\nNOTE: Reading Intermediate Code...";
	ic.open("IC.txt",ios::in);
	
	out.open("machine_code.txt",ios::out);
	out<<"CODE\tINDEX\tREG\tADDRESS\n";
	
	while(ic.get(c))
	{
		if(c=='(' || c==',' || c=='\t' || c=='\n' || c==')')
		{
			//cout<<word<<endl;
			file.push_back(word);
			if(c=='\n')
			{
				//no machine code should be generated if AD DS or DC is present
				if(file[2]=="AD" || file[2]=="DS" || file[2]=="DC")
				{
					out<<"----------------------------\n";
				}
				if(file[2]=="IS")
				{
					int index = search_Literal(atoi(file[6].c_str()));
					
					if(!index==0)
					{
						out<<file[3]<<"\t"<<index<<"\t"<<reg<<"\t"<<lt[index].address<<endl;
					}
					else
						cout<<"Literal not found in literal table";
				}
					
			}
			if(c=='\n')
				file.clear();
			
			word="";
			
		}
		if(c!='(' && c!=',' && c!='\t' && c!='\n' && c!=')')
		{
			word+=c;
		}
	}
	cout<<"\nMachine code generated!";
}
