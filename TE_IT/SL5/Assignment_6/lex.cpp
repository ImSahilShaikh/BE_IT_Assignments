#include<iostream>
#include<stdlib.h>

#include<fstream>

using namespace std;

string key[] = {"auto","break","case","char","const","continue","default","do","double","else","enum","extern","float","for","goto","if","int","long","register","return","short","signed","sizeof","static","struct","switch","typedef","union","unsigned","void","volatile","while"};

int n = sizeof(key)/sizeof(key[0]);

vector <string> keywords (key,key+n);

char special_characters[]={'~','!','#','$','%','^','&','*','(',')','_','+','|','\\','`','=','{','}','[',']',':','"',';','<','>','?',',','.'};

bool checkKeywords(string word)
{
	for(int i=0;i<34;i++)
	{
		if(word.compare(key[i]))
		{
			return true;
		}
	}
	return false;
}

bool checkSpecialCharacters(char x)
{
	for(int i=0;i<30;i++)
	{
		if(x==special_characters[i])
		{
			return true;
		}
	}
	return false;
}

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
				/*if(c==' ')
					continue;*/
				
					if(checkKeywords(word));
					{
						if(word==""|| word ==" ")
							continue;
						cout<<word<<": Keyword"<<endl;
					}
					// if(checkSpecialCharacters(c))
					// 	cout<<c<<": Special character"<<endl;
					// if(!checkKeywords(word) && !checkSpecialCharacters(c))
					// {
					// 	cout<<c<<": symbol";
					// }
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
