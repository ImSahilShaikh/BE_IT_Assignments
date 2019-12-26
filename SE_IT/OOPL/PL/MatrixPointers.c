/*
 ============================================================================
 Name        : MatrixPointers.c
 Author      : Sahil Shaikh(23376)
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void getMatrix(int *m1, int r, int c) {
	int i, j;
	printf("Enter Elements Of Matrix :");
	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++) {
			scanf("%d", (m1+i*c+j));
		}
	}

}

void DisplayMatrix(int *m1, int r, int c) {
	int i, j;
	printf("\n Matrix Is :\n");
	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++) {
			printf("%4d", *(m1+i*c+j));
		}
		printf("\n");
	}
}

void Transpose(int *m1, int r, int c) {
	int i, j;
	printf("\n Matrix Is :\n");
	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++) {
			printf("%d\t", *(m1+j*c+i));
		}
		printf("\n ");
	}
}

void Addition(int *m1, int *m2, int *m3, int r, int c, int r1, int c1) {
	int i, j;
	if(r == r1 && c == c1)
	{
		for (i = 0; i < r; i++)
		{
			for (j = 0; j < c; j++)
			{
				*(m3+i*c+j) = *(m1+i*c+j) + *(m2+i*c+j);
			}
		}
		DisplayMatrix(m3,r,c);
	}
	else
	{
		printf("\nPlease Enter Equal Number Of Rows And Columns For Matrices");
	}
}
void Subtraction(int *m1, int *m2, int *m3, int r, int c,int r1, int c1) {
	int i, j;
	if(r == r1 && c == c1)
	{
			for (i = 0; i < r; i++)
			{
				for (j = 0; j < c; j++)
				{
					*(m3+i*c+j) = *(m1+i*c+j) - *(m2+i*c+j);
				}
			}
			DisplayMatrix(m3,r,c);
	}
	else
	{
			printf("\nPlease Enter Equal Number Of Rows And Columns For Matrices");
	}

}

void Multiplication(int *m1, int *m2, int *m3, int r, int c, int r1, int c1) {


	int i, j, k;
	if(r == r1 && c == c1)
	{
		for (i = 0; i < r; i++)
		{
			for (j = 0; j < c; j++)
			{
				for (k = 0; k < r; k++)
				{
					*(m3+i*c+j) = *(m3+i*c+j) + *(m1+i*c+k) * (*(m2+k*c+j));
				}
			}
		}
		DisplayMatrix(m3,r,c);
	}
	else
	{
		printf("\nPlease Enter Equal Number Of Rows And Columns For Matrices");
	}


}

void Saddle(int *m1, int r, int c) {
	int i,k, j, min, max, pos1, pos2, pos3, pos4;

	for(i=0;i<r;i++)
	{
		min = (*m1+i*c+0);
		for(j=0;j<c;j++)
		{
			if(min >= (*m1+i*c+j))
			{
				min = (*m1+i*c+j);
				pos1 = i;
				pos2 = j;
			}
		}

	}

	j = pos2;

	for(k=0;k<r;k++)
	{
		max = (*m1+0*c+j);
		if(max <= (*m1+k*c+j))
		{
			max = (*m1+k*c+j);
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

	int *m1, *m2, *m3, r, c, choice,r1,c1;

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
			m1 = (int*)malloc((r*c)*sizeof(int));
			getMatrix(m1, r, c);

			printf("Enter Number Of Rows and Columns For Second Matrix: ");
			scanf("%d%d", &r1, &c1);
			m2 = (int*)malloc((r1*c1)*sizeof(int));
			getMatrix(m2, r1, c1);

			break;

		case 2:

			DisplayMatrix(m1, r, c);
			DisplayMatrix(m2, r1, c1);
			break;

		case 3:
			m3 = (int*)malloc((r1*c1)*sizeof(int));

			Addition(m1, m2, m3, r, c,r1,c1);
			free(m3);
			break;
		case 4:
			m3 = (int*)malloc((r1*c1)*sizeof(int));

			Subtraction(m1, m2, m3, r, c,r1,c1);
			free(m3);
			break;
		case 5:
			m3 = (int*)malloc((r1*c1)*sizeof(int));
			Multiplication(m1, m2, m3, r, c,r1,c1);

			free(m3);
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
