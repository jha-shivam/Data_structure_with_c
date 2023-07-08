#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
// Choice function
void choices()
{
    printf("\n1. Insert Beg");
    printf("\n2. Insert After");
    printf("\n3. Insert At Position");
    printf("\n4. Delete Beg");
    printf("\n5. Delete After");
    printf("\n6. Delete At Position");
    printf("\n7. Print List");
    printf("\n8. Reverse List");
    printf("\n9. Exit\n");
}
// Count node
int count(struct node *head)
{
    int i;
    while (head != NULL)
    {
        head = head->next;
        i++;
    }
    return i;
}

// Insert node

void insertBeg(struct node **head, int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = *head;
    *head = temp;
}
void insertAfter(struct node **head, int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    struct node *temp_1 = *head;
    if ((*head) == NULL)
    {
        insertBeg(head, data);
    }
    else
    {
        while (temp_1->next != NULL)
        {
            temp_1 = temp_1->next;
        }
        temp_1->next = temp;
    }
}
void insertAtPos(struct node **head, int pos, int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    struct node *temp_1 = *head;
    while (pos < 1 || pos > count(*head))
    {
        printf("\nThe index is invalid...");
    }
}

// Delete Node
void deleteBeg(struct node **head)
{
    struct node *temp_1 = *head;
    if (temp_1 == NULL)
    {
        printf("\nThere is no data in list.....");
    }
    else
    {
        *head = (temp_1)->next;
        free(temp_1);
    }
}
void deleteAfter(struct node **head, int data)
{
}
void deletePos(struct node **head, int data)
{
}

// Reverse List
void reverseList(struct node **head)
{
    struct node *next_l, *prev, *now;
    now = *head;
    prev = NULL;
    next_l = *head;
    while (now != NULL)
    {
        next_l = now->next;
        now->next = prev;
        prev = now;
        now = next_l;
    }
    *head = prev;
}

// Print List

void listPrint(struct node *head)
{
    int count_l = count(head);
    count_l--;
    int i;
    for (i = 0; i < count_l; i++)
    {
        printf("\n%d", head->data);
        head = head->next;
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
            insertAfter(&head, data);
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

            break;

        case 6:

            break;

        case 7:
            listPrint(head);
            break;
        case 8:
            reverseList(&head);
            break;

        case 9:
            exit(0);
            break;

        default:
            break;
        }
    }
    return 0;
}