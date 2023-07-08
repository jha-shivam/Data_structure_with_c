// Stack using linked list
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node * next;
};
void push(struct node **head,int data)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next=(*head);    
    (*head)=temp;
    
}
void pop(struct node **head)
{
    struct node *temp;
    temp = *head;
    *head = (*head)->next;
    printf("The poped element is: %d",temp->data);
    free(temp);
}
void peek(struct node *head)
{
    printf("The top element is: %d",(head)->data);
}
void emptyOrnot(struct node *head)
{
    if(head==NULL)
    {
        printf("\nStack is empty");
    }
    else{
        printf("\nStack have element");
    }
}
void printStack(struct node *head)
{
    while(head!=NULL)
    {
        printf("\t%d",head->data);
        head = head->next;
    }
}
int main()
{
    struct node *top=NULL;
    emptyOrnot(top);
    push(&top,15);
    push(&top,18);
    push(&top,19);
    printStack(top);
    return 0;
}