#include<iostream>
using namespace std;

void merge(int *array,int start,int mid,int end)
{
	//temp variable of same size that of array
	int temp[end-start+0];
	//two variables to traverse through both array from start and mid+1
	int i=start,j=mid+1,k=0;
	
	//append small elements into temp array
	while(i <= mid && j<=end)
	{
		if(array[i] < array [j])
		{
			temp[k++]=array[i++];
		}
		else
			temp[k++]=array[j++];
	}
	while(i<=mid)
	{
		temp[k++]=array[i++];
	}
	while(j<=end)
	{
		temp[k++]=array[j++];
	}
	for(i=start;i<=end;i++)
	{
		array[i]=temp[i-start];
	}
	
}

void mergesort(int *array,int start,int end)
{
	int mid=0;
	//check for last element
	if(start!=end)
	{
		//calculate mid
		mid = (start+end)/2;
		//recursive call for left part of array
		mergesort(array,start,mid);
		//recursive call for right part of array
		mergesort(array,mid+1,end);
		//after sort merge
		merge(array,start,mid,end);
	}
}


int main()
{
	int *array,n;
	array=new int[10];
	cout<<"\n----------MERGE SORT----------";
	cout<<"\nEnter size of array : ";
	cin>>n;
	cout<<"\nEnter array elements: ";
	for(int i=0;i<n;i++)
		cin>>array[i];
	cout<<"\nEntered Elements are: \n";
	for(int i=0;i<n;i++)
		cout<<*(array+i)<<"\t";
	
	mergesort(array,0,n);		
	
	cout<<"\nSorted array: \n";
	for(int i=1;i<=n;i++)
		cout<<*(array+i)<<"\t";
			
	return 0;
}
