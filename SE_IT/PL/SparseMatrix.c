/*
 ============================================================================
 Name        : SparseMatrix.c
 Author      : Sahil Shaikh
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct sparsematrix
{
	int row;
	int col;
	int value;
}sm;
void transpose(sm a[],sm b[])
{
	int n,i,j,currentb;
	n=a[0].value;
	b[0].row=a[0].col;
	b[0].col=a[0].row;
	b[0].value=n;
	if(n>0)
	{
		currentb=1;
		for(i=0;i<a[0].col;i++)
		{
			for(j=0;j<=n;j++)
			{
				if(a[j].col==i)
				{
					b[currentb].row=a[j].col;
					b[currentb].col=a[j].row;
					b[currentb].value=a[j].value;
					currentb++;
				}
			}
		}
	}

}
void fasttranspose(sm a[],sm b[])
{
	int row_terms[20];
	int start_pos[20];
	int i,j,num_cols=a[0].col,num_terms=a[0].value;
	b[0].row=num_cols;
	b[0].col=a[0].row;
	b[0].value=num_terms;
	if(num_terms>0)
	{
		for(i=0;i<num_cols;i++)
		{
			row_terms[i]=0;
		}
		for(i=1;i<num_terms;i++)
		{
			row_terms[a[i].col]++;
		}
		for(i=1;i<=num_cols;i++)
		{
			//row_terms[a[i].col]++;
			start_pos[i]=start_pos[i-1]+row_terms[i-1];
		}
		for(i=1;i<=num_terms;i++)
		{
			j=start_pos[a[i].col]++;
			b[j].row=a[i].col;
			b[j].col=a[i].col;
			b[j].value=a[i].value;
		}
	}
}
void acceptMatrix(int a[10][10], int r, int c) {
	int i, j;
	printf("\nEnter Elements Of Matrix :\n");
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
}
void sparseconvert(int a[10][10],int r,int c,sm sparse[20])
{
	int i,j,k;
	k=1;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			if(a[i][j]!=0)
			{
				sparse[k].row=i;
				sparse[k].col=j;
				sparse[k].value=a[i][j];
				k++;
			}
		}
	}
	sparse[0].row=r;
	sparse[0].col=c;
	sparse[0].value=k-1;
}
void display(int a[10][10], int r, int c)
{
	int i, j;
	printf("\n Matrix :\n");
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
		{
			printf("%d\t", a[i][j]);
		}
		printf("\n ");
	}
}
void displaysparse(sm sp[20]){
	int i;
	printf("Row\tColumn\tValue\n");
	printf("===============================================================================\n");
	for(i=0;i<=sp[0].value;i++)
	{
		printf("\n%d\t%d\t%d\n",sp[i].row,sp[i].col,sp[i].value);
	}
}
void addsparse(sm a[20],sm b[20],sm add[20])
{
	int i,j,k;
	i=j=k=1;
	while(i<=a[0].value && j<=b[0].value)
	{
		if(a[i].col==b[j].col && a[i].row==b[j].row)
		{
			add[k].row=a[i].row;
			add[k].col=a[i].col;
			add[k].value=a[i].value+b[j].value;
			i++;
			j++;
			k++;
		}
		if(a[i].row==b[j].row && a[i].col<b[j].col)
		{
			add[k].row=a[i].row;
			add[k].col=a[i].col;
			add[k].value=a[i].value;
			i++;
			k++;
		}
		if(a[i].row==b[j].row && a[i].col>b[j].col)
		{
			add[k].row=b[j].row;
			add[k].col=b[j].col;
			add[k].value=b[j].value;
			j++;
			k++;
		}
		if(a[i].row<b[j].row)
		{
			add[k]=a[i];
			i++;
			k++;
		}
		if(a[i].row>b[j].row)
		{
				add[k]=b[j];
				j++;
				k++;
		}
	}
	while(i<=a[0].value)
	{
		add[k]=a[i];
		i++;
		k++;
	}
	while(j<=b[0].value)
	{
		add[k]=b[j];
		j++;
		k++;
	}
	add[0].row=a[0].row;
	add[0].col=a[0].col;
	add[0].value=k-2;
}
int main()
{
	int a[10][10],b[10][10],r, c,choice;
	sm sparse[20],sparse1[20],ans[20];
	do{
	printf("===============================================================================");
	printf("\n\n1.Accept Matrix\n\n2.Display Matrix\n\n3.Display Sparse\n\n4.Transpose\n\n5.Add\n\n6.Fast Transpose\n\n7.Exit\n\n");
	printf("===============================================================================\n");
	printf("Enter your Choice\n");
	printf("===============================================================================\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			printf("Enter Number Of Rows and Columns for Matrix: ");
			scanf("%d%d", &r, &c);
			acceptMatrix(a,r,c);
			break;
		case 2:
			display(a,r,c);
			break;
		case 3:
			sparseconvert(a,r,c,sparse);
			displaysparse(sparse);
			break;
		case 4:
			transpose(sparse,sparse1);
			displaysparse(sparse1);
			break;
		case 5:
			printf("Enter Number Of Rows and Columns for 1st Matrix: ");
			scanf("%d%d", &r, &c);
			acceptMatrix(a,r,c);
			printf("Enter Number Of Rows and Columns for 2nd Matrix: ");
			scanf("%d%d", &r, &c);
			acceptMatrix(b,r,c);
			sparseconvert(a,r,c,sparse);
			sparseconvert(b,r,c,sparse1);
			//displaysparse(sparse);
			//displaysparse(sparse1);
			addsparse(sparse,sparse1,ans);
			displaysparse(ans);
			break;
		case 6:
			fasttranspose(sparse,sparse1);
			displaysparse(sparse1);
			break;
		case 7:
			break;
		default:
			printf("\nEnter proper choice\n");
	}
	}while(choice!=8);
	 return 0;
}
