#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

int main()
{
	fstream file,f2;
	char word[20],keyword[20];
	
	file.open("keyword.cpp");
	f2.open("keywordlist.txt");
	
	while(f2 >> keyword && file >> word)
	{
			if(strcmp(word,keyword))
			{
				cout<<"\nKeyword found: "<<keyword;	
			}
	}
	return 0;
}
