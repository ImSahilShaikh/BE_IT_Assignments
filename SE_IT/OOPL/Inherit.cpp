#include<iostream>
#include<string.h>
using namespace std;
class human
{
	protected:
	char name[40];
	int dob;
	char blood[4];
	public:
		void getdata1()
		{
			cout<<"\nEnter name of person\n";
			cin.ignore();
			cin.getline(name,39);
			cout<<"Enter dob\n";
			cin>>dob;
			cout<<"blood group\n";
			cin>>blood;
		}
};
class physic
{
	protected:
		int ht;
		int wt;
	public:
		void getdata2()
		{
			cout<<"Enter height of person\n";
			cin>>ht;
			cout<<"Enter weight of person\n";
			cin>>wt;
		}
};
class info
{
	protected:
	long unsigned int policy;
	char address[50];
	public:
		void getdata3()
		{
			cout<<"Enter policy number\n";
			cin>>policy;
			cout<<"Enter address of person\n";
			cin.ignore();
			cin.getline(address,49);
		}
};
class person: public human, public physic, public info
{
	private:
		long unsigned int tele;
		long unsigned int lisence;
	public:
		void getdata();
		void display();
		int search();
		
};

void person::getdata()
{
	getdata1();
	getdata2();
	getdata3();
	cout<<"Enter telephone number\n";
	cin>>tele;
	cout<<"Enter lisence number\n";
	cin>>lisence;
}

void person::display()
{
	cout<<"\nNAME: "<<name<<endl;
	cout<<"DOB: "<<dob<<endl;
	cout<<"BLOOD GROUP: "<<blood<<endl;
	cout<<"HEIGHT: "<<ht<<endl;
	cout<<"WEIGHT: "<<wt<<endl;
	cout<<"POLICY NO: "<<policy<<endl;
	cout<<"LISENCE NO: "<<lisence<<endl;
	cout<<"TELE-PHONE NO: "<<tele<<endl;
	cout<<"ADDRESS: "<<address<<endl;
}

int main()
{
	int i,op,n,m=0,n1;
	char temp[40];
	person p[50];
	cout<<"Enter the number of records to be added in database\n";
	cin>>n;
	cout<<"Enter basic information of persons in database:\n\n";
	for(i=0;i<n;i++)
	{
		p[i].getdata();
		m++;
	}
	do
	{
		cout<<"\t\nMENU\n\n";
		cout<<"1.Insert more records\n2. Display records\n3.Search a record\n4.Edit a record\n5.Delete a record\n6.Exit\n";
		cout<<"Enter your choice number\n";
		cin>>op;
		switch(op)
		{
			case 1:
				cout<<"Enter number of records to be added in database\n";
				cin>>m;
				n=n+n1;
				for(i=m;i<n;i++)
				{
					p[i].getdata();
				}
				break;
			case 2:
				cout<<"\nDatabase of basic information of person:\n";
				for(i=0;i<n;i++)
				{
					p[i].display();
				}
				break;
			case 3:
				break;
		}
	}while(op!=6);
}
                                                              

