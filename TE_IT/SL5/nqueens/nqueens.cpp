#include<iostream>
#include<math.h>
#include<stdlib.h>
using namespace std;

//int chessboard[20][20];

int array[50];
//where k is no of queens and n is index of chessboard

bool place(int k,int i)
{
	for(int j=1;j<=k-1;j++)
	{
		//check row and diagonal condition
		if((array[j]==i) || abs(array[j] - i) == abs(j - k))
			return false;
	}
	return true;
}


void nqueens(int k,int n)
{
	for(int i=1;i<=n;i++)
	{
		if(place(k,i))
		{
			array[k]=i;
			if(k==n)
			{
				cout<<"\n";			
				for(int i=1;i<=n;i++)
				{	
					cout<<"\t"<<array[i];
				}
			}
			else
				nqueens(k+1,n);
		}
	}
}

int main()
{
	//size of chessboard

	//no of queens
	int no=0;
	
	cout<<"\nEnter no of queens :";
	cin>>no;
	
	cout<<"\nYour chessboard is of size "<<no<<" X "<<no;
	
	//call nqueens function
	nqueens(1,no);
	cout<<endl;

	return 0;
}
