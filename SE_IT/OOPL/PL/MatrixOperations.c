/*
 ============================================================================
 Name        : MatrixOperations.c
 Author      : Sahil Shaikh(23376)
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void getMatrix(int a[10][10], int r, int c) {
	int i, j;
	printf("Enter Elements Of Matrix :");
	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++) {
			scanf("%d", &a[i][j]);
		}
	}

}

void DisplayMatrix(int a[10][10], int r, int c) {
	int i, j;
	printf("\n Matrix Is :\n");
	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++) {
			printf("%d\t", a[i][j]);
		}
		printf("\n ");
	}
}

void Transpose(int a[10][10], int r, int c) {
	int i, j;
	printf("\n Matrix Is :\n");
	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++) {
			printf("%d\t", a[j][i]);
		}
		printf("\n ");
	}
}

void Addition(int a[10][10], int b[10][10], int cm[10][10], int r, int c, int r1, int c1) {
	int i, j;
	if(r == r1 && c == c1)
	{
		for (i = 0; i < r; i++)
		{
			for (j = 0; j < c; j++)
			{
				cm[i][j] = a[i][j] + b[i][j];
			}
		}
		DisplayMatrix(cm,r,c);
	}
	else
	{
		printf("\nPlease Enter Equal Number Of Rows And Columns For Matrices");
	}
}
void Subtraction(int a[10][10], int b[10][10], int cm[10][10], int r, int c,int r1, int c1) {
	int i, j;
	if(r == r1 && c == c1)
	{
			for (i = 0; i < r; i++)
			{
				for (j = 0; j < c; j++)
				{
					cm[i][j] = a[i][j] - b[i][j];
				}
			}
			DisplayMatrix(cm,r,c);
	}
	else
	{
			printf("\nPlease Enter Equal Number Of Rows And Columns For Matrices");
	}

}

void Multiplication(int a[10][10], int b[10][10], int cm[10][10], int r, int c, int r1, int c1) {


	int i, j, k;
	if(r == r1 && c == c1)
	{
		for (i = 0; i < r; i++)
		{
			for (j = 0; j < c; j++)
			{
				for (k = 0; k < r; k++)
				{
					cm[i][j] = cm[i][j] + a[i][k] * b[k][j];
				}
			}
		}
		DisplayMatrix(cm,r,c);
	}
	else
	{
		printf("\nPlease Enter Equal Number Of Rows And Columns For Matrices");
	}


}

void Saddle(int a[10][10], int r, int c) {
	int i,k, j, min, max, pos1, pos2, pos3, pos4;

	for(i=0;i<r;i++)
	{
		min = a[i][0];
		for(j=0;j<c;j++)
		{
			if(min >= a[i][j])
			{
				min = a[i][j];
				pos1 = i;
				pos2 = j;
			}
		}

	}

	j = pos2;


	for(k=0;k<r;k++)
	{
		max = a[0][j];
		if(max <= a[k][j])
		{
			max = a[k][j];
			pos3 = k;
			pos4 = j;
		}
	}

	if(min == max )
	{
		if(pos1 == pos3)
		{
			if(pos2 == pos4)
			{
				printf("\nSaddle Point Is at (%d,%d) : %d",pos1,pos2,min);
			}
		}
	}


}

int main(void)
{

	int m1[10][10], m2[10][10], m3[10][10], r, c, choice,r1,c1;

	do {
		printf("\n\n1.Get Matrix"
				"\n2.Display Matrix"
				"\n3.Addition Of Matrix"
				"\n4.Subtraction Of Matrix"
				"\n5.Multiplication Of Matrix"
				"\n6.Transpose"
				"\n7.Saddle Point"
				"\n8.Exit");
		printf("\nEnter Your Choice : ");
		scanf("%d", &choice);

		switch (choice) {
		case 1:

			printf("Enter Number Of Rows and Columns For First Matrix: ");
			scanf("%d%d", &r, &c);

			getMatrix(m1, r, c);

			printf("Enter Number Of Rows and Columns For Second Matrix: ");
			scanf("%d%d", &r1, &c1);

			getMatrix(m2, r1, c1);

			break;

		case 2:

			DisplayMatrix(m1, r, c);
			DisplayMatrix(m2, r1, c1);
			break;

		case 3:
			Add:
			Addition(m1, m2, m3, r, c,r1,c1);
			break;
		case 4:
			Sub:
			Subtraction(m1, m2, m3, r, c,r1,c1);
			break;
		case 5:
			mul:
			Multiplication(m1, m2, m3, r, c,r1,c1);
			break;
		case 6:

			Transpose(m1, r, c);

			Transpose(m2, r1, c1);
			break;
		case 7:
			Saddle(m1, r, c);
			Saddle(m2, r1, c1);
			break;
		case 8:
			return 0;
		default:
			printf("\nEnter Valid Choice..");

		}

	} while (choice != 8);

	return 0;
}
