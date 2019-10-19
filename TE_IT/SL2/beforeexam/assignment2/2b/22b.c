//Header files 
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

//Function For Binary Search
void binary_search(int num[10],int first,int last){

			int key=0;
			
			printf("\nINFO: Enter The Value To Be Searched:");
			scanf("%d",&key);
			
			int mid = 0;
			
			while(first <= last)
			{
				mid = (first + last) / 2 ;
				if(key < num[mid])
				{
					last = mid-1;
				}
				else if(key > num[mid])
				{
					first = mid+1;
				}
				else
				{
					printf("\nINFO: Element %d Found At %d Location",key,mid+1 );
					return;
				}
			}
			printf("\nINFO: Element %d not found!!\n",key);
}

//Main Function
int main(int argc,char *argv[]){
	
	//Variable Declaration
	int num[argc-1];
	int i=0;

	printf("%d",argc);

	printf("\nINFO: Converting Strings To Integer Values");
	//Converting Strings To Array
	for(i=0;i<argc;i++){
		num[i] = atoi(argv[i]);
	}
	
	
	//Calling Function binary_search()
	binary_search(num,0,argc);
	printf("\n");
	return 0;
}
