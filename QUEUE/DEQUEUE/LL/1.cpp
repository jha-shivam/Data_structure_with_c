#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{
	struct node *prev,*next;
	int data;
};

struct Deque{
	struct node *front;
	struct node *rear;
};
void intialize(struct Deque *q)
{
	q->front = NULL;
	q->rear = NULL;
}

void insertFront(struct Deque *q,int data)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->prev=NULL;
	temp->next = q->front;
	if(q->front == NULL)
	{
		q->front = temp;
		q->rear = temp;
	}
	else{
		q->front->prev = temp;
		q->front = temp;
	}
}
void insertRear(struct Deque *q,int data)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data=data;
	temp->prev=q->rear;
	temp->next=NULL;
	if(q->front == NULL)
	{
		q->front = temp;
		q->rear = temp;
	}
	else{
		q->rear->next = temp;
		q->rear = temp;
	}
}
void deleteFront(struct Deque *q)
{
	if(q->front == NULL)
	{
		printf("\nThere is no data in the Dequeue");
	}
	else if(q->front == q->rear){
		free(q->front);
		q->front = NULL;
		q->rear= NULL;
	}
	else{
		q->front->prev = NULL;
		struct node *temp;
		temp = q->front;
		q->front = q->front->next;
		free(temp);
	}
}
void deleteRear(struct Deque *q)
{
	if(q->front == NULL)
	{
		printf("\nUnderflow");
	}
	else if(q->front ==q->rear)
	{
		free(q->front);
		q->front = NULL;
		q->rear = NULL;
	}
	else{
		q->rear = q->rear->prev;
		free(q->rear->next);
		q->rear->next = NULL;
	}
}
void display(struct Deque *q)
{
	struct node *temp;
	temp = q->front;
	if(q->front==NULL)
	{
		printf("\nThere is no data");
	}
	else{
	do{
		printf("\n%d",temp->data);
		temp = temp->next;	
	}while(temp!=q->rear->next);
}
}
int main()
{
	struct Deque *q = (struct Deque *)malloc(sizeof(struct Deque));
	
	insertFront(q,10);
	insertFront(q,20);
	insertFront(q,30);
	insertFront(q,40);
	return 0;
}
