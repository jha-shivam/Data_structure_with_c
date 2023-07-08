#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};

// ...................................................This section is for inserting........................................
void insertBeg(struct node **head, int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->link = (*head);
    *head = temp;
}

int count(struct node *head)
{
    int i = 0;
    while (head != NULL)
    {
        i++;
        head = head->link;
    }
    return i;
}

void insertLast(struct node **head, int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;
    struct node *ch = *head;
    if (ch == NULL)
    {
        ch = temp;
    }
    else
    {
        while (ch->link != NULL)
        {
            ch = ch->link;
        }
        ch->link = temp;
    }
}

void insertAfter(struct node *head, int position, int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;
    int count_s = count(head);
    if (position < 1 || position > count_s)
    {
        printf("\nInvalid index......");
    }
    else
    {
        position--;
        while (position--)
        {
            head = head->link;
        }
        temp->link = head->link;
        head->link = temp;
    }
}

// ...............................This section is for deleting......................................

void deleteBeg(struct node **head)
{
    struct node *temp;
    temp = *head;
    if (*head == NULL)
    {
        printf("\nThere is no node available");
    }
    else
    {
        *head = temp->link;
        free(temp);
    }
}

void deleteLast(struct node **head)
{
    struct node *temp;
    temp = *head;
    if (*head == NULL)
    {
        printf("\nThere is no node available");
    }
    else
    {
        while (temp->link != NULL)
        {
            temp = temp->link;
        }
        free(temp);
    }
}

void print(struct node *head)
{
    int i = count(head);
    int j;
    for (j = 0; j < i; j++)
    {
        printf("\n%d", head->data);
        head = head->link;
    }
}

void reverse_list(struct node **head)
{
    struct node *prev, *curr, *next;
    struct node *temp = *head;
    prev = NULL;
    curr = temp;
    next = NULL;
    while (curr != NULL)
    {
        next = curr->link;
        curr->link = prev;
        prev = curr;
        curr = next;
    }
    temp = prev;    
}
int main()
{
    struct node *head = NULL;

    insertBeg(&head, 40);
    insertBeg(&head, 30);
    insertBeg(&head, 20);
    insertBeg(&head, 10);
    insertLast(&head, 50);
    insertLast(&head, 70);
    insertLast(&head, 80);
    insertAfter(head, 5, 60);
    reverse_list(&head);
    print(head);
    return 0;
}