#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	char c[30];
	fstream File;
	File.open("testfile2.txt");
	File.seekg(ios::beg);
	while(!File.eof())
	{
		File>>c;	
		cout<<c;
	}
	File.close();
	return(0);
}
