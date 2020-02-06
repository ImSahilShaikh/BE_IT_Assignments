#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//vector declaration
vector <int> temp,tape;

//display the vector i.e tape
void display(vector<int> v)
{
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i]<<"\t";
	}
	cout<<"\n";
}

//calculate the total retrieval time for the tape
int store(vector<int> tape)
{
	int sum=0;
	float temp=0;
	for(int i=0;i<tape.size();i++)
	{
		sum=tape[i]+sum;
		temp=temp+float(sum);
	}
	return temp;
}

int main()
{
	//n: total number of programs to be stored, temp1 used for taking input and push into vector
	int n,temp1;
	//capacity for tape
	int capacity;
	
	//mean retrieval time
	float mrt;
	
	//take input for total number of programs to be stored on the tape
	cout<<"\nEnter the number of programs to be stored on tapes: ";
	cin>>n;
	
	//input capacity for the tape
	cout<<"\nEnter the capacity of tape: ";
	cin>>capacity;
	
	//input size of all programs
	cout<<"\nEnter the program sizes: ";
	for(int i=0;i<n;i++)
	{
		cin>>temp1;
		temp.push_back(temp1);
	}
	
	//sort the temp vector
	sort(temp.begin(),temp.end());	
	
	//iterator variable
	int j=0;
	//populate tape until capacity is not zero
	while(capacity>0)
	{
		//push the program from temporary vector to tape vector
		tape.push_back(temp[j]);
		//decrement the capacity
		capacity=capacity-temp[j];
		//increment the temporary vector
		j++;		
	}
	//display the tape
	display(tape);
			
	//total to store the total retrieval time of all programs		
	int total=store(tape);
	//calculate mean retrieval time
	mrt = float(total)/tape.size();	
	//display mean retrieval time
	cout<<"MRT: "<<mrt;	
	return 0;
}
