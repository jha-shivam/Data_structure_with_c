#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};
struct node *rear=NULL;
struct node *front = NULL;

void insertData(int data)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	if((front == NULL && rear == NULL))
	{
		front = rear = temp;
		temp->next = NULL;
	}
	else
	{
		rear->next = temp;
		rear = temp;
		temp->next = NULL;
	}
}
void deleteData()
{
	if(front == NULL && rear ==NULL)
	{
		printf("\nQueue is empty");
	}
	else{
		if(front == rear)
		{
			front=rear=NULL;
		}
		else{
			printf("\nThe deleting data is %d",front->data);
			front = front->next;
		}
	}
}
void displayData()
{
	struct node *temp =front;
	if(front == NULL && rear == NULL)
	{
		printf("\n Queue is empty....");
	}
	else{
		do{
			printf("\n%d",temp->data);
			temp= temp->next;
		}
		while(temp!=rear->next);
	}
}
int main()
{
	insertData(10);
	insertData(20);
	insertData(30);
	displayData();
	deleteData();
	displayData();
	deleteData();
	displayData();
	return 0;
}
