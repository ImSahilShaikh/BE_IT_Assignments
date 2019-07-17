#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>Pr
#include <pthread.h>

#define SIZE 10

int A[SIZE][SIZE], B[SIZE][SIZE];
long int C[SIZE][SIZE];
int t=1;

void *mul_thread(void *arg)
{
	int i,k,row,col,*rcArgs,z;
	long int return_val=0;
	rcArgs = (int *) arg;
	row = rcArgs[0];
	col = rcArgs[1];
	k = rcArgs[2];
	printf("\n\n\n\nThread %d start\n",t);
	for(i=0;i<k;i++)
	{
		return_val = return_val+(A[row][i]*B[i][col]);
	}
	printf("Thread %d calculated as %ld \n",t,return_val);
	printf("Thread %d exit\n\n\n\n",t++);
	pthread_exit((void *) return_val);
}

void accept_matrix(int M[SIZE][SIZE], int rows, int cols) 
{
	int i, j;
	printf("\n");
	for(i=0;i<rows;i++)
	{
		for(j=0;j<cols;j++) 
		{
			printf("Value at [%d][%d]: ",i+1,j+1);
			scanf("%d",&M[i][j]);
		}
	}
}

void display_matrix(int M[SIZE][SIZE], int rows, int cols) 
{
	int i, j;
	printf("\n");	
	for(i=0;i<rows;i++)
	{
		for(j=0;j<cols;j++)
		{
			printf("%d  ",M[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	int rows_A, cols_A, rows_B, cols_B;
	int rcArgs[3];
	int i, j, k, *status;
	pthread_t P[SIZE][SIZE];
	do
	{
		printf("\nEnter no. of rows in matrix A: ");
		scanf("%d",&rows_A);
		printf("Enter no. of columns in matrix A: ");
		scanf("%d",&cols_A);
		printf("\nEnter no. of rows in matrix B: ");
		scanf("%d",&rows_B);
		printf("Enter no. of columns in matrix B: ");
		scanf("%d",&cols_B);
		if(cols_A != rows_B) 
		{
			printf("\n Matrix multiplication not possible.");
		}
	}while(cols_A != rows_B);
	accept_matrix(A, rows_A, cols_A);
	accept_matrix(B, rows_B, cols_B);
	for(i=0;i<rows_A;i++)
	{
		for(j=0;j<cols_B;j++)
		{
			if(pthread_create(&P[i][j],NULL,mul_thread,rcArgs)!=0)
				printf("\n\tCannot create thread.\n");
			else
			{
				printf("\nThread No %d Created",t);
				sleep(2);
			}
		}
	}
	
	for(i=0;i<rows_A;i++) 
	{
		for(j=0;j<cols_B;j++) 
		{
				if(pthread_join(P[i][j],(void **) &status) != 0)
					printf("\nThread join failed.\n");
				C[i][j] = (long int)status;
		}
	}
	
	printf("\n\nResultant Matrix:\n");
	for(i=0;i<rows_A;i++)
	{
		for(j=0;j<cols_B;j++)
		{
			printf("%ld  ",C[i][j]);
		}
		printf("\n");
	}
	printf("\n------------------------------------------------------\n\n");
	
}
