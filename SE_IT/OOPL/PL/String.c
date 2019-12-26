

#include<stdio.h>
#include<stdlib.h>

int length(char *a);
void reverse(char *a);
int palindrome(char *a);
int compare(char *a,char *b);
void copy(char *a, char *b);
int findSubstr(char *a, char *b,int len1,int len2);

void main()
{
	char a[20],b[20];
	int res,choice;
	int l1,l2;
	do{
	printf("\n\n=======================================================\n");
	printf("\nProgram to perform various operations on String!!\n");
	printf("\n=======================================================\n");
	printf("\n1.Length\n\n2:Reverse\n\n3.Palindrome\n\n4.Compare\n\n5.Substring\n\n6.Exit");	
	printf("\nEnter your choice\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
		printf("\nEnter a string:");
		scanf("%s",a);
		res=length(a);
		printf("\nThe length of the String is:%d",res);
		break;
		case 2:
		printf("\nEnter a string");
		scanf("%s",a);
		reverse(a);
		printf("\nReverse of the String is:%s",a);
		break;
		case 3:
		printf("\nEnter a string");
		scanf("%s",a);
		res=palindrome(a);
		if(res==0)
		{
			printf("\nString is not palindrome");
		}
		else
		{
			printf("\nString is palindrome");
		}
		break;
		case 4:
		printf("\nEnter 1st String: ");
		scanf("%s",a);
		printf("\nEnter 2nd String: ");
		scanf("%s",b);	
		res=compare(a,b);
		if(res==0)
		{
			printf("\nBoth string are same");
		}
		else if(res>0)
		{
			printf("\nString 1 is greater");
		}
		else
		{
			printf("\nString 2 is greater");
		}
		break;
		case 5:
		printf("\nEnter 1st String: ");
		scanf("%s",a);
		printf("\nEnter 2nd String: ");
		scanf("%s",b);
		l1=length(a);
		l2=length(b);
		res=findSubstr(a,b,l1,l2);
		/*if(res>-1)
		{
			printf("It is the substring");
		}
		else
		{
			printf("It is not the substring");
		}*/
		case 6:
		exit(0);
		break;
		default:
		printf("Enter proper choice\n");
		
	}
	}while(choice!=6);
}
int length(char *a)
{
	int i=0;
	while(*(a+i)!='\0')
	i++;
	return(i);
}
void reverse(char *a)
{
	char *p,*q,temp;
	p=q=a;
	while(*q!='\0')
	q++;
	q--;
	while(p<q)
	{
		temp=*p;
		*p=*q;
		*q=temp;
		p++;
		q--;
	}
}
int palindrome(char *a)
{
	char *p,*q;
	p=q=a;
	while(*q!='\0')
	q++;
	q--;
	while(p<q)
	{
		if(*p!=*q)
		return(0);
		p++;
		q--;
	}
	return(1);
}
int compare(char *a,char *b)
{
	while(*a!='\0')
	{
		if(*a>*b)
		return(1);
		if(*a<*b)
		return(-1);
		a++;
		b++;
	}
	return(0);
}
int findSubstr(char *a, char *b,int len1,int len2) 
{
    int i,j=0,k=0,pos=0;
    for(i=0;*(a+i)!='\0';i++)
    {
    		if(*(a+i)==*(b+0))
    		{
    			pos=i;
    		}
    }
    k=pos;
    for(i=0;i<k+len1;i++)
    {
    		if(*(a+k+i)==*(b+i))
    		{
    			j++;
    		}
    }
    if(j==len1)
    {
    		printf("\n%s is the substring of %s",a,b);
    }
    else
    {
    		printf("\n%s is not the substring of %s",a,b);
    }
}
