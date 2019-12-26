/*
 ============================================================================
 Name        : SLL.c
 Author      : Sahil Shaikh(23376)
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct node{
	struct node *next;
	//struct node *head=NULL;
	int data;
}*head;

void insert_first(int val)
{
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=val;
	if(head==NULL)
	{
		head=newnode;
		newnode->next=NULL;
	}
	else
	{
		newnode->next=head;
		head=newnode;
	}
}
void display()
{
	if(head==NULL)
	{
		printf("List is empty\n");
	}
	else
	{
		struct node *temp=head;
		printf("\nElements are: ");
		while(temp->next!=NULL)
		{
			printf("%d->",temp->data);
			temp=temp->next;
		}
		printf("%d->NULL\n",temp->data);
	}
}
int main(void) {

	int ch,value;
	do{
	printf("=============================================================================\n");
	printf("Which operation you want to perform?\n");
	printf("\n1.Insert\n2.Delete\n3.Display\n4.Display Reverse\n5.Revert SLL\n6.Exit\n");
	scanf("%d",&ch);
	printf("=============================================================================\n");
	switch(ch)
	{
		case 1:
			int ch1;
			printf("=============================================================================\n");
			printf("Where you want to insert the element\n");
			printf("\n1.First\n2.Random\n3.Last\n4.Exit from insert\n");
			scanf("%d",&ch1);
			printf("=============================================================================\n");
			switch(ch1);
			{
				case 1:
					printf("Enter the value to be entered\n");
					scanf("%d",&value);
					insert_first(value);
					printf("\nData added Successfully");
					break;
			}
		case 2:
			printf("\nData in the list is:\n");
			display();
			break;
		case 6:
			return 0;
	}
	}while(ch!=6);
	return EXIT_SUCCESS;
}
