#include<iostream>
using namespace std;

//min and max variable declaread and assigned with values for comparison
int MIN=9999,MAX=0;

int minmax(int array[],int start,int end)
{
	
	//if only one element is available
	if(start == end)
	{
		if(MIN > array[start])
			MIN = array[start];
		if(MAX < array[start])
			MAX = array[start];
			
		return array[start];
	}
	//if two elements are available
	else if(end == start+1)
	{
		if(array[start] < array[end])
		{
			if(MIN > array[start])
				MIN=array[start];
			if(MAX < array[end])
				MAX = array[end];
		}
		else
		{
			if(MIN > array[end])
				MIN = array[end];
			if(MAX < array[start])
				MAX = array[start];
		}
		return 0;
	}
	//more than two elements 
	else
	{
		//divide array into two parts
		int mid=(start+end)/2;
		//recursively call the minmax function for both part of array
		minmax(array,start,mid);
		minmax(array,mid+1,end);
	}
}

//display array
void display(int array[],int size)
{
	cout<<"\nElements are: \n";
	for(int i=0;i<size;i++)
		cout<<array[i]<<"\t";
}

int main()
{	
	int size;
	
	//accept size of array
	cout<<"\nEnter the size of array: ";
	cin>>size;
	
	int array[size];
	
	//accept elements
	for(int i=0;i<size;i++)
	{
			cout<<"\nEnter ["<<i+1<<"] elements: ";
			cin>>array[i];
	}
	
	display(array,size);
	
	minmax(array,0,size-1);
	
	//result i.e minimum and maximum element printed
	cout<<"\n---------------------------";
	cout<<"\n\nMIN element: "<<MIN;
	cout<<"\nMAX element: "<<MAX;
	cout<<"\n---------------------------";
		
	return 0;
}
