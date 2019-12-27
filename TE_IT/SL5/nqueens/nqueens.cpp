#include<iostream>
#include<math.h>
#include<stdlib.h>
using namespace std;

int array[50];//chessboard

void print(int no)
{
	cout<<"\n";
	for(int i=1;i<=no;i++)
	{	
		cout<<"\t"<<array[i];
	}
}

//k is the number of queen and i is the array index
//function to check the row column and diagonal conditions
bool place(int k,int i)
{
	//j is column number
	for(int j=1;j<=k-1;j++)
	{
		//check row and diagonal condition
		if((array[j]==i) || abs(array[j] - i) == abs(j - k))
			return false;
	}
	return true;
}


//k is number of particular queen and n is total number of queens
//function to place the queen in the array at proper location
void nqueens(int k,int n)
{
	//check the correct place from first location
	for(int i=1;i<=n;i++)
	{
		//checking the correct place to keep the queen
		if(place(k,i))
		{
			//placing the queen in the array
			array[k]=i;
			if(k==n)
			{
				//printing the output when the last queen is placed
				print(n);
			}
			else
				nqueens(k+1,n);
		}
	}
}

int main()
{
	//no of queens
	int no=0;
	
	cout<<"\nINFO: Enter no of queens :";
	cin>>no;
	
	/*if(no<4)
	{
		cout<<"\nWARNING: Please enter atleast 4 queens!!!!";
		exit(0);
	}*/
	cout<<"\nINFO: Your chessboard is of size "<<no<<" X "<<no;
	
	//call nqueens function
	cout<<"\nINFO: All possible solutions for given " <<no<<" X "<<no<< " chessboard are: ";			
	nqueens(1,no);
	cout<<endl;

	return 0;
}
