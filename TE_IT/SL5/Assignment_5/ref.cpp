#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct tape
{
	vector <int> stored_prog;
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

void RR_Store(vector <int> prog,tape tape[],int tape_count)
{
	int j,count=0;
	for(int i=0;i<prog.size();i++)
	{
		for(j=0;i<tape_count;j++)
		{
			if(tape[j].capacity>=prog[i])
			{
				tape[j].stored_prog.push_back(prog[i]);
				tape[j].capacity=tape[j].capacity-prog[i];
				count=j+1;
				if(count==tape_count)
				{
					count=0;
				}
				break;
			}
			else
				continue;
		}
	}
	for(int i=0;i<tape_count;i++)
	{
		int sum=0;
		float mrt;
		cout<<"Tape ["<<i+1<<"] : ";
		for(int j=0;j<tape[i].stored_prog.size();j++)
		{
			sum = sum + tape[i].stored_prog[j];
			mrt = mrt + sum;
			cout<<" | "<<tape[i].stored_prog[j]<<" | ";
		}
		tape[i].mrt=mrt/tape[i].stored_prog.size();
		cout<<"\nMRT of the tape is : "<<tape[i].mrt;
	}
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

	sort(temp_tape.begin(),temp_tape.end());
		
	cout<<"Store: \n";
	
	/*for(int i=0;i<temp_tape.size();i++)
	{
		cout<<"\nhere";
		for(int j=0;j<n;j++)
		{
			cout<<"\n\ninner";
			if(t[j].capacity>=0)
			{
				t[j].tape.push_back(temp_tape[i]);
				t[j].capacity=t[j].capacity-temp_tape[i];
				break;
			}
			else
				continue;
		}
	}	
	
	display(t[1].tape);
	*/
	
	RR_Store(temp_tape,t,tape_count);
	
	return 0;
}
