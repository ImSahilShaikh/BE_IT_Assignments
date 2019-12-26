#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class Sdatabase
{
	int roll;
	string name;
	fstream file;
	string line;
	void get()
	{
		file.open("MyDatabase.txt",ios::app);
		cout<<"\nEnter Rollno";
		cin>>roll;
		file<<name;
		cout<<"\nEnter name";
		cin>>name;
		file<<roll;
		file.close();
	}
	void display()
	{
		file.open("MyDatabase.txt",ios::in);
		while(!file.eof())
		{
			getline(file,line);
			cout<<line;
		}
	}
};
int main()
{
	
}
