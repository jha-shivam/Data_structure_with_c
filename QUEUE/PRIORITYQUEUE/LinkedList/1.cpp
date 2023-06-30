#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node
{
	int data;
	int priority;
	struct node *next;
};

void addData(struct node **head, int data, int priority)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->priority = priority;
	if ((*head) == NULL)
	{
		temp->next = NULL;
		*head = temp;
	}
	else
	{
		struct node *temp_1 = (*head);
		if(temp_1->priority<temp->priority)
		{
			temp->next = temp_1;
			*head =  temp;
		}
		else{
			while(temp_1->next!=NULL)
			{
				if(temp_1->next->priority<temp->priority)
				{
					temp_1 = temp_1->next;
				}
			}
			temp->next = temp_1->next;
			temp_1 = temp;
		}
	}
}
void displayData(struct node *head)
{
	if (head == NULL)
	{
		printf("\nUnderflow");
	}
	else
	{
		while (head != NULL)
		{
			printf("\n%d", head->data);
			head = head->next;
		}
	}
}
int main()
{
	struct node *head = NULL;
	addData(&head, 11, 4);
	addData(&head, 12, 5);
	addData(&head, 13, 6);
	addData(&head, 14, 7);
	addData(&head, 15, 8);
	addData(&head, 15, 3);
	addData(&head, 15, 2);
	addData(&head, 15, 1);
	
	displayData(head);
	return 0;
}