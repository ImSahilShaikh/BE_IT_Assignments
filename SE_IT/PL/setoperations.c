/*
 ============================================================================
 Name        : setoperations.c
 Author      : Sahil Shaikh(23376)
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


void getSet(int a[50],int size)
{
	int i,j=0;
	enter:
	printf("\nEnter The Elements Of Set :");
	for(i=0;i<size;i++)
	{

		scanf("%d",&a[i]);

			if(i>0 && a[i] == a[i-1])
			{
				printf("\nEnter The Distinct Elements :");
				goto enter;
			}

	}
}

void displaySet(int a[50],int size)
{
	int i;
	printf("{");
	for(i=0;i<size;i++)
	{
		printf("%3d,",a[i]);
	}
	printf("}");

}

void unionSet(int a[50], int b[50], int c[50] ,int s1, int s2,int *p)
{
	int k=0,i,j,flag;
	for(i=0;i<s1;i++)
	{
		c[k] = a[i];
		k++;
	}

	for(i=0;i<s1;i++)
	{
		flag=1;
		for(j=0;j<s2;j++)
		{
			if(a[j] == b[i])
			{
				flag = 0;
				break;
			}

		}
		if(flag == 1)
		{
			c[k] = b[i];
			k++;
		}

	}
	*p = k;
}

void getIntersect(int a[50], int b[50], int c[50], int s1, int s2,int *p)
{
	int k=0,i,j,flag;

	for(i=0;i<s1;i++)
	{
		flag=0;
		for(j=0;j<s2;j++)
		{
			if(a[j] == b[i])
			{
				flag = 1;
				break;
			}
		}
		if(flag == 1)
		{
			c[k] = b[i];
			k++;
		}
	}

	*p = k;
}

void differenceOne(int a[50], int b[50], int c[50], int s1, int s2, int *p)
{
	int k=0,i,j,flag;

	for(i=0;i<s1;i++)
	{
		flag = 1;
		for(j=0;j<s2;j++)
		{
			if(a[i] == b[j])
			{
				flag = 0;
				break;
			}
		}
		if(flag == 1)
		{
			c[k] = a[i];

			k++;
		}
	}
	*p = k;

}

int main(void) {

	int set1[50],set2[50],set3[50],choice,n,n1,choice1,d1,set4[50],set5[50],size,size1;

	do
	{



		printf("\n\t1.Get Values Of Set");
		printf("\n\t2.Display Values Of Set");
		printf("\n\t3.Get Union Of Set");
		printf("\n\t4.Get Intersection Of Set");
		printf("\n\t5.Get Difference Of Set");
		printf("\n\t6.Get Symmetric Difference Of Set");
		printf("\n\t7.Exit");

		printf("\nEnter Your Choice :");
		scanf("%d",&choice);

		switch(choice)
		{

			case 1:
						printf("Enter The Size Of Set 1 :");
						scanf("%d",&n);
						getSet(set1,n);
						printf("Enter The Size Of Set 2 :");
						scanf("%d",&n1);
						getSet(set2,n1);
						break;
			case 2:
						printf("\nElements Of Set1 : ");
						displaySet(set1,n);
						printf("\nElements Of Set2 : ");
						displaySet(set2,n1);
				        break;

			case 3:
						printf("\nElements Of Set1 : ");
						displaySet(set1,n);
						printf("\nElements Of Set2 : ");
						displaySet(set2,n1);
						unionSet(set1,set2,set3,n,n1,&d1);
						printf("\nUnion Of Set1 and Set2 :");
						displaySet(set3,d1);
						break;

			case 4:
						printf("\nElements Of Set1 : ");
						displaySet(set1,n);
						printf("\nElements Of Set2 : ");
						displaySet(set2,n1);
						getIntersect(set1,set2,set3,n,n1,&d1);
						printf("\nIntersection Of Set1 and Set2 :");
						displaySet(set3,d1);
				        break;
			case 5:
						do
						{
							printf("\n\t1.Set1 - Set2");
							printf("\n\t2.Set2 - Set1");
							printf("\n\t3.Return To Main Menu");
							printf("\n\t\t------------------------");

							printf("\nEnter Your Choice :");
							scanf("%d",&choice1);

							switch(choice1)
							{
								case 1:
										printf("\nElements Of Set1 : ");
										displaySet(set1,n);
										printf("\nElements Of Set2 : ");
										displaySet(set2,n1);
										differenceOne(set1,set2,set3,n,n1,&d1);
										printf("\nResult of Set1 - Set2 : ");
										displaySet(set3,d1);
									    break;
								case 2:
										printf("\nElements Of Set1 : ");
										displaySet(set1,n);
										printf("\nElements Of Set2 : ");
										displaySet(set2,n1);
										differenceOne(set2,set1,set4,n,n1,&d1);
										printf("\nResult of Set2 - Set1 : ");
										displaySet(set4,d1);
									    break;
								case 3:
									      break;
								default :
									    printf("\nEnter Valid Choice");
							}
						}while(choice1 != 3);
				        break;
			case 6:

						differenceOne(set1,set2,set3,n,n1,&size);

						printf("\nResult of Set1 - Set2 : ");
						displaySet(set3,size);

						differenceOne(set2,set1,set4,n,n1,&size1);
						printf("\nResult of Set1 - Set2 : ");
						displaySet(set4,size1);

						unionSet(set3,set4,&set5,size,size1,&d1);
						printf("\nSymetric Difference Of Set1 and Set2 : ");
						displaySet(set5,d1);

						break;
			case 7:
				      return 0;
			default:
				      printf("\nPlease Enter Valid Choice");

		}

	}while(choice != 7);
	return EXIT_SUCCESS;
}
