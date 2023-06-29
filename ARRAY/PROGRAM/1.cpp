#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Array
{
    /* data */
    int capacity;
    int lastIndex;
    int *ptr;
};

/*      This is basic opetions           */
struct Array *a1;
/* function to create the array*/
void createArray(int capacity)
{
    a1 = (struct Array *)malloc(sizeof(struct Array));
    a1->capacity = capacity;
    a1->lastIndex = -1;
    a1->ptr = (int *)malloc(sizeof(int) * capacity);
}

// Counting the total number of element present in array
int count()
{
    return (a1->lastIndex + 1);
}

// Appending the value in array means adding it to the end of array
void appendValue(int value)
{
    if (a1->capacity - 1 == a1->lastIndex)
    {
        printf("\nArray is overflowed");
    }
    else
    {
        a1->lastIndex = a1->lastIndex + 1;
        a1->ptr[a1->lastIndex] = value;
    }
}

// Add element in array at specific index
void addValue(int value, int position)
{
    a1->capacity = a1->capacity + 1;
    int i = 0;
    int j = a1->lastIndex;
    for (i = a1->lastIndex; i >= position; i--)
    {
        a1->ptr[i + 1] = a1->ptr[i];
    }
    a1->ptr[position] = value;
    a1->lastIndex = a1->lastIndex + 1;
}

// Deleting the item from specific index
void deleteItem(int position)
{
    int i;
    for (i = position; i < a1->lastIndex; i++)
    {
        a1->ptr[i] = a1->ptr[i + 1];
    }
    a1->lastIndex--;
    a1->capacity--;
}

// Editing the value at given index
void editVal(int index, int data)
{
    a1->ptr[index] = data;
}

// Checking the array is full or not
int checkFull()
{
    if (a1->lastIndex == a1->capacity)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

// Checking the array is empty or not
int checkEmpty()
{
    if (a1->lastIndex == -1 || a1->capacity == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

// Printing the elements of array
void printArray()
{
    int i = 0;
    for (i = 0; i <= a1->lastIndex; i++)
    {
        printf("\n%d", (a1->ptr[i]));
    }
}

// Deleting the reference object of array and also object
void release()
{
    free(a1->ptr);
    free(a1);
}

/*      This is advance opetions          */
// For sorting the array
void sort()
{
    int r, i, t;
    for (r = 1; r < count(); r++)
    {
        for (i = 0; i <= count() - 1 - r; i++)
        {
            if (a1->ptr[i] > a1->ptr[i + 1])
            {
                t = a1->ptr[i];
                a1->ptr[i] = a1->ptr[i + 1];
                a1->ptr[i + 1] = t;
            }
        }
    }
}

// Finding greatest element from array
int big_Num()
{
    int big = a1->ptr[0];
    int i, j;
    for (i = 0; i <= count(); i++)
    {

        if (big < a1->ptr[i])
        {
            big = a1->ptr[i];
        }
    }
    return big;
}

// Finding smallest element from array
int small_Num()
{
    int small = a1->ptr[0];
    int i, j;
    for (i = 0; i <= count(); i++)
    {

        if (small > a1->ptr[i])
        {
            small = a1->ptr[i];
        }
    }
    return small;
}

//Searching the element in array
void search(int data)
{
    int i;
    int flag=0;
     for (i = 0; i <= count(); i++)
    {

        if (data  == a1->ptr[i])
        {
            
           flag = 1;
           break;
        }
    }
    if(flag==1)
    {
        printf("Available");
    }
    else{
        printf("Not available");
    }
}

int main()
{
    int capacity, total, choice = 0, position;
    int data, temp = 0;
    printf("\nEnter the size of array: ");
    scanf("%d", &capacity);
    createArray(capacity);
    appendValue(300);
    appendValue(20);
    appendValue(401);
    appendValue(8);
    appendValue(0);
    appendValue(510);
    appendValue(1001011);
    appendValue(60);
    return 0;
}