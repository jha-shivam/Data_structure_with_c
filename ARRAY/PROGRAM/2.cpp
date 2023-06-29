#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Array
{
    int capacity;
    int lastIndex;
    int *ptr;
};

struct Array *createArray(int value)
{
    struct Array *a = (struct Array *)malloc(sizeof(struct Array));
    a->capacity = value;
    a->lastIndex = -1;
    a->ptr = (int *)malloc(sizeof(int) * a->capacity);
    return a;
}
int count(struct Array *a)
{
    return a->lastIndex;
}
void doubleArray(struct Array *a)
{
   int *temp;
   temp = (int *)malloc(sizeof(a->capacity*2));
   int i=0;
   for(i=0;i<a->lastIndex;i++)
   {
    temp[i] = a->ptr[i];
   }
   free(a->ptr);
   a->capacity = a->capacity*2;
   a->ptr = temp;
}

void halfArray(struct Array *a)
{
   int *temp;
   temp = (int *)malloc(sizeof(a->capacity/2));
   int i=0;
   for(i=0;i<a->lastIndex;i++)
   {
    temp[i] = a->ptr[i];
   }
   free(a->ptr);
   a->capacity = a->capacity/2;
   a->ptr = temp;
}

void appendValue(struct Array *a, int value)
{
    if (a->lastIndex + 1 == a->capacity)
         doubleArray(a);

    a->lastIndex++;
    a->ptr[a->lastIndex] = value;
}

void insert(struct Array *a, int data, int position)
{
    if (position < 0 || position > a->lastIndex + 1)
    {
        printf("\nAn invalid index");
    }
    else if (a->lastIndex == a->capacity - 1)
    {
        doubleArray(a);
    }

    for (int i = a->lastIndex; i >= position; i--)
    {
        a->ptr[i + 1] = a->ptr[i];
    }
    a->ptr[position] = data;
    a->lastIndex++;
}

void editVal(struct Array *a1, int index, int data)
{
    a1->ptr[index] = data;
}

void deleteItem(struct Array *a1, int position)
{
    if (a1->capacity < position)
    {
        printf("\nInvalid index");
    }
    else if (a1->capacity < 0)
    {
        printf("\nArray underflow");
    }
    else
    {
        int i;
        for (i = position; i < a1->lastIndex; i++)
        {
            a1->ptr[i] = a1->ptr[i + 1];
        }
        a1->lastIndex--;
        a1->capacity--;
        if(a1->capacity>1 && count(a1)<=(a1->capacity)/2){

            halfArray(a1);
        }
    }
}

void release(struct Array *a1)
{
    free(a1->ptr);
    free(a1);
}

void printArray(struct Array *a)
{
    int i = 0;
    for (i = 0; i <count(a); i++)
    {
        printf("\n%d", (a->ptr[i]));
    }
}
int main()
{
    struct Array *a;
    a = createArray(3);
    appendValue(a, 10);
    appendValue(a, 10);
    appendValue(a, 10);
    printf("%d",a->capacity);
    appendValue(a, 10);
    appendValue(a, 10);
    appendValue(a, 10);
    printf("%d",a->capacity);
    printArray(a);

    return 0;
}