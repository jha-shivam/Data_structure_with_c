#include <stdio.h>
#include <conio.h>
#include <sys/time.h>
#include <stdlib.h>

// Calculation of time
long long timeInMilliseconds(void)
{
    struct timeval tv;

    gettimeofday(&tv, NULL);
    return (((long long)tv.tv_sec) * 1000) + (tv.tv_usec / 1000);
}

// Generating random numbers for array
void random_number(int a[])
{
    int i;
    int f = 90000;
    for (i = 0; i < f; i++)
    {
        a[i] = rand() % 200000;
    }
}

// Sorting function
void sorting(int a[], int n)
{
   int i,j;
   for(i=0;i<n;i++)
   {
    for(j=0;j<n-1;j++)
    {
        if(a[j]>a[j+1])
        {
            int temp = a[j];
            a[j] = a[j+1];
            a[j+1] = temp;
        }
    }
   }
}

// Main function
int main()
{
    int i;
    int a[90000];
    // Generating random numbers
    random_number(a);

    int len = sizeof(a) / sizeof(a[0]);
    // Taking snapshot or sample of time in miliseconds before sorting function starts its execution
    long long aa = timeInMilliseconds();

    // Actual sorting perform here
    sorting(a, len);

    // Taking snapshot or sample of time in miliseconds After sorting function ends its execution
    long long b = timeInMilliseconds();

   // Printing the array before sorting
    printf("\nArray After sorting");
    for (i = 0; i < len; i++)
    {
        printf("%d ", a[i]);
    }
    double c = (double)b-aa;
    printf("\n\nTime taken for sorting the array %6.1f miliseconds", c);
    return 0;
}
