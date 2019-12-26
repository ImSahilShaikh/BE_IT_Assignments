#include<iostream>
#include<stdlib.h>
#include<fstream>
using namespace std;
int main()
{
	int choice;
	fstream outFile,openFile;
	char ch[50];
	do{
	cout<<"\n1.Write\t2.Read\n";
	cin>>choice;
	switch(choice)
	{
	case 1:
	
	outFile.open("testfile.txt",ios::app);
	cout<<"Enter your data:\n";
	cin>>ch;
	outFile<<ch;
	outFile.close();
	break;
	case 2:

	openFile.open("testfile.txt",ios::in);
	openFile.seekg(ios::beg);
	while(!openFile.eof())
	{
		openFile>>ch;	
		cout<<ch;
	}
	openFile.close();
	break;
	case 3:
	exit(0);
	}
	}while(choice!=3);
return(0);
}
