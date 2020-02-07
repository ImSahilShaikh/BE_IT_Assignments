#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct tape
{
	vector<int> t;
	int cap;
	float mrt;
};
            
void MRT_hor(vector<int> v,tape tap[],int n)
{
	sort(v.begin(),v.end());
	int j;
	for(int i=0;i<v.size();i++)
	{
		
		for(j=0;j<n;j++)
		{
			if(tap[j].cap>=v[i])
			{
				tap[j].t.push_back(v[i]);
				tap[j].cap = tap[j].cap - v[i];
				break;
			}
			else
			   {continue;}
		}
		/*if(j==n-1)
		{
			cout<<"The program "<<v[i]<<" not stored anywhere\n";
		}*/
	}
	
	for(int i=0;i<n;i++)
	{
		int sum=0;float mtr=0;
		cout<<"\nTape number "<<i+1<<" is:: | ";
		for(int j=0;j<tap[i].t.size();j++)
		{
				sum = sum + tap[i].t[j];
				mtr=mtr+sum;
				cout<<tap[i].t[j]<<" | ";
		}
		tap[i].mrt=mtr/tap[i].t.size();
		cout<<"\n The MRT of tape number "<<i+1<<" is::"<<tap[i].mrt<<"\n";
	}
}        

void MRT_ver(vector<int> v,tape tap[],int n)
{
	sort(v.begin(),v.end());
	int j,count=0;
	for(int i=0;i<v.size();i++)
	{
		
		for(j=count;j<n;j++)
		{
			
			if(tap[j].cap>=v[i])
			{
				tap[j].t.push_back(v[i]);
				tap[j].cap = tap[j].cap - v[i];
				count=j+1;
				if(count==n)
				{
					count = 0;
				}
				break;
			}
			else
			{
			    continue;
			}   
			
		}
		
		/*if(j==n-1)
		{
			cout<<"The program "<<v[i]<<" not stored anywhere\n";
		}*/
	}
	
	for(int i=0;i<n;i++)
	{
		int sum=0;float mtr=0;
		cout<<"\nTape number "<<i+1<<" is:: | ";
		for(int j=0;j<tap[i].t.size();j++)
		{
				sum = sum + tap[i].t[j];
				mtr=mtr+sum;
				cout<<tap[i].t[j]<<" | ";
		}
		tap[i].mrt=mtr/tap[i].t.size();
		cout<<"\n The MRT of tape number "<<i+1<<" is::"<<tap[i].mrt<<"\n";
	}
	
	
}           
            
int main()
{
	int nt,np,x,n; 
	vector<int> prog;
	cout<<"Enter number of tapes::";
	cin>>nt;
	cout<<"Enter tape capacities::";
	struct tape taph[nt];
	struct tape tapv[nt];
	for(int i=0;i<nt;i++)
	{
		cin>>n;
		taph[i].cap=n;
		tapv[i].cap=n;
	}
	cout<<"enter number of programs::";
	cin>>np;
	cout<<"enter programs::";
	for(int i=0;i<np;i++)
	{
		cin>>x;
		prog.push_back(x);
	}		
	cout<<"\nFor horizontal storage::\n";
	MRT_hor(prog,taph,nt);
	
	cout<<"\nFor vertical storage::\n";
	MRT_ver(prog,tapv,nt);
	
		
}                     
