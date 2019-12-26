#include<iostream>
using namespace std;
class myexception
{
	int x,y,z;//tryagain;
	public:
	void input()
	{
		cout<<"Enter two numbers to divide\n";
		cin>>x;cout<<"\n";cin>>y;
	}
	void calculate()
	{
	try{
		if(y!=0)
		{
			z=x/y;
			cout<<"The divison is:"<<z;
		}
		else
		throw(y);
	}
	catch(int e)
	{
		throw e;
		//cout<<"Denominator can't be zero";
	}
	}
	//cout<<"\nTry again?(1/0)\n";
	//cin>>tryagain;
	//if(tryagai==1)
	//{
	//}
};
int main()
{
	myexception e1;
	try{
	e1.input();
	e1.calculate();
	}
	catch(int e)
	{
		cout<<"Denominator can't be zero\nPlease Try again with valid inputs\n";
		e1.input();
		e1.calculate();
	}
}
