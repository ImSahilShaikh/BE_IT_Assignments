#include<stdio.h>



void inputMatrix(int *matrix,int row,int col)
{
	int i=0,j=0;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			printf("INFO: Enter element for [%d][%d] location: ",i,j);
			scanf("%d",(matrix+i*col+j));
		}		
	}
}

void display(int *matrix,int row,int col)
{
	int i=0,j=0;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			printf("%d",*(matrix+i*col+j));
			printf("\t");
		}
		printf("\n");
	}
}
void multiply(int *matrix1,int *matrix2,int *resultantMat)
{
	int row,col,i,j,sum=o;
	for(i=0;i<col;i++)
	{
		sum+=(*(martix1+row)+i) * (*(martix2+row)+i);
	}
}

int main()
{
	int *mat1,*mat2,*resmat,row,col;
	printf("\nINFO: Enter the row and columns for matrix");
	scanf("%d%d",&row,&col);

	inputMatrix(mat1,row,col);
	display(mat1,row,col);	
	
	return 0;
}
