#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>

int i,j,r1,c1,r2,c2,t,k,mat1[3][3],mat2[3][3],res[3][3];
int status=0;
void input(int r,int c,int mat[3][3])
{
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
			scanf("%d",&mat[i][j]);
}

void display(int r,int c,int mat[3][3])
{
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("%d\t",mat[i][j]);
		}
		printf("\n");
	}
}
void* multiply(void *arg)
{
	int count=status++;
	
		for(j=0;j<c2;j++)
		{
			res[count][j]=0;
			for(k=0;k<c1;k++)
			{
				res[count][j]+=mat1[count][k]*mat2[j][k];
			}
		}
	
}


int main()
{
	int tot;
	int rr1,rc2=0;
	printf("\nEnter rows and columns for matrix 1:");
	scanf("%d %d",&r1,&c1);
	printf("\nEnter rows and columns for matrix 2:");
	scanf("%d %d",&r2,&c2);
	rr1=r1;
	rc2=c2;
	if(c1!=r2){
		printf("\nInvalid order of matrix");		
	}
	else
		tot=(r1*c2);

	printf("Threads to be created: %d",tot);
	
	
	printf("\nEnter the first matrix: \n");	
	input(r1,c1,mat1);
	
	printf("\nEnter the second matrix: \n");	
	input(r2,c2,mat2);
	
	printf("\nFirst matrix is:\n");
	display(r1,c1,mat1);
	
	printf("\nSecond matrix is:\n");
	display(r2,c2,mat2);

	pthread_t threads[tot];
	printf("outside create");
	for(i=0;i<tot;i++)
	{
		int *p;
		pthread_create(&threads[i],NULL,multiply,(void*)(p));
	}
	for(i=0;i<tot;i++)
	{
		pthread_join(threads[i],NULL);
	}
	printf("\nMultiplication of two matrices is: \n");
	for(i=0;i<rr1;i++)
        {
           printf("\n");
           for(j=0;j<rc2;j++)
             	printf("%d\t",res[i][j]);   
        } 
	return 0;
}

