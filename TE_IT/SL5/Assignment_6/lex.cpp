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
		
		if(c==' ' || c==',' || c=='\n' || c=='\t')
		{
			cout<<word<<endl;

			word="";
		}
		if(c!=' ' && c!=',' && c!='\n' && c!='\t')
		{
			word+=c;
		}
	}
	return 0;
}
