#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct node
{
    int data;
    int priority;
    struct node *next;
};
void addNode(struct node **head, int data, int priority)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->priority = priority;
    if ((*head)==NULL)
    {
        temp->next = NULL;
        (*head) = temp;
    }
    else{
    	struct node *temp_1 = (*head);
 		if(temp->priority>temp_1->priority)
		{
			temp->next = temp_1;
			*head= temp;
		}
		else{
			while(temp_1->next!=NULL)
			{
				if(temp_1->next->priority < temp->priority)
				{
					temp->next = temp_1->next;
					temp_1->next=temp;
				}
				else{
					temp->next= NULL;
					temp_1->next = temp;
				}
			}
		}   	
	}
}

void displayData(struct node *head)
{
    if(head==NULL)
    {
    	printf("\nUnderflow");
	}
	else{
		struct node *temp=head;
		while(temp!=NULL)
		{
			printf("\n%d",temp->data);
			printf("\n%d",temp->priority);
			temp = temp->next;
		}
	}
}

int main()
{
    struct node *head = NULL;
    addNode(&head, 11, 1);
    addNode(&head, 12, 3);
    addNode(&head, 1, 1);
    displayData(head);
    return 0;
}
