#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
void choices()
{
    printf("\n1. Insert Beg");
    printf("\n2. Insert After");
    printf("\n3. Insert At Position");
    printf("\n4. Delete Beg");
    printf("\n5. Delete After");
    printf("\n6. Delete At Position");
    printf("\n7. Print List");
    printf("\n8. Exit\n");
}
int count(struct node *head)
{
    int i;
    while ((head) != NULL)
    {
        head = (head)->next;
        i++;
    }
    return i;
}
void insertBeg(struct node **head, int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->prev = NULL;
    temp->next = *head;
    if (*(head) == NULL)
    {
        *head = temp;
    }
    else
    {
        (*head)->prev = temp;
        *head = temp;
    }
}
void insertLast(struct node **head, int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;
    struct node *temp_1 = *head;
    while (temp_1->next != NULL)
    {
        temp_1 = temp_1->next;
    }
    temp_1->next = temp;
    temp->prev = temp_1;
}
void insertAtPos(struct node **head, int pos, int data)
{
    int i = 0;
    if(*head==NULL)
    {
    	printf("\nThere is no nodes in linked list.....");
	}
	else{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    struct node *temp_1 = *head;
	temp->data = data;
    temp->next = temp_1->next;
    temp->prev = temp_1;
    
    
    for (i = pos; i > 0; i--)
    {
            temp_1 = temp_1->next;
    }
    if(temp_1->next!=NULL)
    {
		temp_1->next->prev = temp;
    	temp->next = temp_1->next;
    	temp_1->next = temp;
    	temp->prev = temp_1;
    }
    else{
		temp_1->next = temp;
		temp->next=NULL;
		temp->prev = temp_1;
	}
  }
}
//Deleting nodes from linked list
void deleteBeg(struct node **head)
{
	struct node *temp = *head;
	if(temp==NULL)
	{
		printf("\nThere is no node in the list....");
	}
	else{
	(*head) = (*head)->next;
	if((*head)!=NULL)
	{
		(*head)->prev = NULL;
	}
	free(temp);
}
}

void deleteLast(struct node **head)
{
	struct node *temp = *head;
	if(temp==NULL)
	{
		printf("\nThere is no node in the list....");
	}
	else{

	if(temp->next==NULL)
	{
		free(temp);
		*head =NULL;
	}
	else{
	while(temp->next!=NULL)
	{
		temp = temp->next;
	}
	temp->prev->next=NULL;
	free(temp);
}
}
}


void deleteAfterPos(struct node **head,int pos)
{
	int count_l = count(*head);
	if((*head)==NULL)
	{
		printf("\nThere is no node in the linked list...");
	}
	else if(pos<1 || pos>count_l){
		printf("\nPlease enter the correct index to delete...");
	}
	else if(pos == 1)
	{
		if((*head)->next==NULL)
		{
			struct node *temp = *head;
			free(temp);
			*head=NULL;
		}
	}
	else{
		int i=0;
		struct node *temp = *head;
		for(i=pos;i>0;i--)
		{
			temp = temp->next;
		}
		temp->next->prev = temp->prev;
		temp->prev->next=temp->next;
		free(temp);
	}
}
void listPrint(struct node *head)
{
	if(head==NULL)
	{
		printf("\nThere is no nodes to display...");
	}
	else{
    while (head != NULL)
    {
        printf("\n%d", head->data);
        head = head->next;
    }
}
}
int main()
{
    int i, choice = 0, position = 0;
    struct node *head = NULL;
    while (true)
    {
        int data;
        printf("\n");
        printf("Enter the choice: ");
        choices();
        scanf("%d", &choice);
        switch ((choice))
        {
            // Insert
        case 1:
            printf("\nEnter the data: ");
            scanf("%d", &data);
            insertBeg(&head, data);
            break;
        case 2:
            printf("\nEnter the data: ");
            scanf("%d", &data);
            insertLast(&head, data);
            break;
        case 3:
            printf("\nEnter the data: ");
            scanf("%d", &data);
            printf("\nEnter the position: ");
            scanf("%d", &position);
            insertAtPos(&head, position, data);
            break;

        // Delete
        case 4:
            deleteBeg(&head);
            break;

        case 5:
			deleteLast(&head);
            break;

        case 6:
        	printf("\nEnter the position: ");
            scanf("%d", &position);
			deleteAfterPos(&head,position);
            break;

        case 7:
            listPrint(head);
            break;
        case 8:
            exit(0);
            break;

        default:
            break;
        }
    }
    return 0;
}
