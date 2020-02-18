#include<iostream>
#include<fstream>

using namespace std;

int main()
{
	fstream input_file;
	input_file.open("hello.c");
	
	char c;
	string word;
	
	while(input_file.get(c))
	{		
		if(c==' ' || c==',' || c=='\n' || c=='\t' || c==';' || c=='=' || c=='#' || c=='<' || c=='>' || c=='(' || c==')' || c=='{' || c=='}')
		{
			if(c == '{' || c == '(' || c == ')' || c == '}' || c == '=' || c == '+' || c == ',' || c == ';' || c=='#' || c=='<' || c=='>' || c==' ')
			{
				if(c==' ')
					continue;
				cout<<word<<endl;
				cout << c << endl;
				word.clear();
			}
		}
		if(c!=' ' && c!=',' && c!='\n' && c!='\t' && c !=';' && c!='=' && c!='#' && c!='<' && c!='>' && c!='(' && c!= ')' && c!='{' && c!='}')
		{
			word+=c;
		}
	}
	return 0;
}
