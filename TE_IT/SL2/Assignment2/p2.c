#include<stdio.h>

int binSearch(int a[], int f, int l, int key)
{
        if(l >= f)
        {
                int mid = f+(l-f)/2;
                
                if(a[mid] == key)
                        return mid;
                if(a[mid] > key)
                        return binSearch(a, f, mid-1, key);
                return binSearch(a, mid+1, l, key);
        }
        return -1;
}

int main(int argc,char *argv[])
{
	int arr[argc],key,res;
	
//convert to int array

	for(int i=0;i<argc;i++)
	{
		arr[i] = atoi(argv[i]);
	}
	
	
	printf("Enter key to be searched :");
        scanf("%d",&key);  
        
        res = binSearch(arr, 0, argc-1, key);
        if(res == -1) 
                printf("%d not found..",key); 
        else
                printf("%d Found at location %d",key,res+1);
	return 0;

}
