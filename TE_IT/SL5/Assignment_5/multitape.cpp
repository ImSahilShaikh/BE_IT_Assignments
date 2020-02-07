#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct tape
{
	vector <int> tape;
	int capacity;
	float mrt; 
};

void display(vector <int> v)
{
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i]<<"\t";
	}	
	cout<<"\n";
}

int main()
{
	vector <int> temp_tape;
	
	int temp,n,tape_count;

	cout<<"\nEnter the number of tapes: ";
	cin>>tape_count;
	
	struct tape t[tape_count];
	
	cout<<"\nEnter the capacity of tape: ";
	for(int i=0;i<tape_count;i++)
	{
		cout<<"\nTape "<<i+1<<" : ";	
		cin>>t[i].capacity;
	}
	
	cout<<"\nEnter the number of programs you want to store: ";
	cin>>n;
	
	cout<<"\nEnter the program(s) (size(s)) you want to store: -\n";
	for(int i=0;i<n;i++)
	{
		cin>>temp;
		temp_tape.push_back(temp);
	}
	
	cout<<"\nDisplaying Temporary Tape: -\n";
	display(temp_tape);

	cout<<"\nSorting program by their size:\n";
	sort(temp_tape.begin(),temp_tape.end());
	
	cout<<"\nDisplaying sorted programs: \n";
	display(temp_tape);
	
	return 0;
}
