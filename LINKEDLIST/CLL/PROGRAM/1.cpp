#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    int data;
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
	int count;
	struct node *temp;
	temp = head;
	while(temp!=head)
	{
		count++;
		temp->next=temp;
	}
	return count;
}
void insertBeg(struct node **head,int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next=NULL;
    if((*head)==NULL)
    {
        (*head) = temp;
        temp->next=*head;
    }
    else{
        temp->next=(*head)->next;
        (*head)->next = temp;
    }
}
void insertLast(struct node **head,int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next=NULL;
    if((*head)==NULL)
    {
        (*head) = temp;
        temp->next=*head;
    }
    else{
        temp->next = (*head)->next;
        (*head)->next = temp;
        *head = temp;
    }
}
void insertAfter(struct node **head,int pos,int data)
{
	int count_l = count(*head);
	if(pos>count_l || pos<1)
	{
		printf("\nInvalid index number....");
	}
	else{
		if((*head)==NULL)
		{
			printf("\nThere is no nodes in list so data will be added to first position....");
		}
		else{
			struct node *temp,*temp_l;
			temp_1 = (struct node *)malloc(sizeof(struct node));
			temp = *head;
			temp_l->data=data;
			while(pos--)
			{
				temp=temp->next;
			}
			if(temp == (*head))
			{
				temp_l->next = temp->next;
				*head = temp_l;
			}
			else{
				temp_l->next = temp->next;
				temp->next = temp_l;
			}
			
		}
	}
}
void listPrint(struct node *head)
{
	struct node *temp;
	temp =head;
	if(temp==NULL)
	{
		printf("\nThere is no nodes to display...");
	}
	else{
		do{
			 printf("\n %d", temp->data);
        	 temp = temp->next;		
		}while (temp != head);
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
            //insertLast(&head, data);
            break;
        case 3:
            printf("\nEnter the data: ");
            scanf("%d", &data);
            printf("\nEnter the position: ");
            scanf("%d", &position);
            insertAf	ter(&head, position, data);
            break;

        // Delete
        case 4:
            //deleteBeg(&head);
            break;

        case 5:
			//deleteLast(&head);
            break;

        case 6:
        	printf("\nEnter the position: ");
            scanf("%d", &position);
			//deleteAfterPos(&head,position);
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
