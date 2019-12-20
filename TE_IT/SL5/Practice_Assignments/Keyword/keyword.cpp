//Read the file and print all the keywords
#include<iostream>
#include<fstream>
#include<vector>
#include<string.h>
using namespace std;

int main()
{
	fstream file;
	string word;
	int count=0;
	string ar[]={"auto","break","case","char","const","continue","default","do","double","else","enum","extern","float","for","goto","if","int","long","register","return","short","signed","sizeof","static","struct","switch","typedef","union","unsigned","void","volatile","while" };
	char c;
	file.open("/home/oslab-15/33364/Wordcount/wc.c");
	//read character by character
	while(file.get(c))
	{
		//start of line can contain these characters with keywords so skip these
		if(c=='}' || c==')' || c== '=')
		{
			word="";
			continue;
		}
		//if these characters are encountered then compare
		if(c==' ' || c== '(' || c== '{' || c=='=' || c=='\n' || c=='\t')
		{
			//loop to check our word with array
			for(int i=0;i<32;i++)
			{
				//print after comparing array with our extracted word
				if(!(strcmp(word.c_str(),ar[i].c_str())))
				{
					count++;
					cout<<"\n"<<word;
									
				}
			}
			//reset the word to get next word
			word="";
			//skip the if condition
			continue;
		}
		//add character to the word that is string extracted
		word+=c;	
	}
	cout<<"\nTotal Keywords encountered: "<<count;
	return 0;
}
