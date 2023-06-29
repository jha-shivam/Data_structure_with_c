#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


struct queue{
	int cap;
	int front,rear;
	int *ptr;
};

struct queue* intializeQueue(int cap)
{
	struct queue *q = (struct queue* )malloc(sizeof(struct queue));
	q->cap=cap;
	q->front = -1;
	q->rear = -1;
	q->ptr = (int *)malloc(sizeof(int)*cap);
	return q;
}
int isEmpty(struct queue *q)
{
	if(q->front == -1 || q->rear == -1)
	{
		return 1;
	}
	else{
		return 0;
	}
}

int isFull(struct queue *q)
{
	if(q->front==0 && q->rear == q->cap-1)
	{
		return 1;
	}
	else if(q->front == q->rear+1)
	{
		return 1;
	}
	else{
		return 0;
	}
}
void insertData(struct queue *q,int data)
{
	if(isEmpty(q))
	{
		q->front=0;
		q->rear = 0;
		q->rear ++;
		q->ptr[q->rear] = data;	
	}
	else if(isFull(q)){
		printf("\nQueue is full you can't add another data into it");	
	}
	else{
		q->rear++;
		q->ptr[q->rear] = data;
	}
}
void deleteData(struct queue *q)
{
	if(isEmpty(q))
	{
		printf("\nQueue is empty you can't delete another data from it");
	}
	else if(q->rear == q->front)
	{
		q->front =-1;
		q->rear=-1;
	}
	else if(q->front == q->cap-1){
		q->front = -1;
	}
	else{
		q->front++;
	}
}
int getFront(struct queue *q)
{
	if(q->front!=-1)
	{
	return q->ptr[q->front];	
	}
	else{
		return -1;
	}
	
}
void displayData(struct queue *q)
{
	if(isEmpty(q))
	{
		printf("\nThe queue is empty");
	}
	else{
		int i;
		printf("\n\nThe data in the queue's are \n\n");
		for(i=q->front;i<=q->rear;i++)
		{
			printf("\n%d",q->ptr[i]);
		}
	}
}
int main()
{
    struct queue *q;
    q= intializeQueue(10);
    insertData(q,10);
    insertData(q,20);
    insertData(q,30);
    insertData(q,40);
    insertData(q,50);
    insertData(q,60);
    insertData(q,70);
    insertData(q,80);
    insertData(q,90);
    displayData(q);
    deleteData(q);
    displayData(q);
    return 0;
}
