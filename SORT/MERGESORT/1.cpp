#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
// To calculate the time
long long timeInMiliSecond(void)
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return (((long long)t.tv_sec) * 1000) + (t.tv_usec / 1000);
}
// To generated the array
void random_number(int a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        a[i] = rand() % 200000;
    }
}
// All about merge sort here is started....
// The main merge sorting is execute here.....
void merge(int a[], int start, int mid, int end)
{
    int n1 = mid - start + 1;
    int n2 = end - mid;
    int left[n1];
    int right[n2];

    for (int i = 0; i < n1; i++)
        left[i] = a[start + i];

    for (int j = 0; j < n2; j++)
        right[j] = a[mid + 1 + j];
    
    int i = 0, j = 0, k = start;
    while (i < n1 && j < n2)
    {
        if (left[i] < right[j])
        {
            a[k] = left[i];
            i++;
        }
        else
        {
            a[k] = right[j];
            j++;
        }
        k++;
    }
    while (j < n2)
    {
        a[k] = right[j];
        k++;
        j++;
    }

    while (i < n1)
    {
        a[k] = left[i];
        i++;
        k++;
    }
}
// Recursion part here
void mergeSort(int a[], int start, int end)
{
    int mid;
    if (start < end)
    {
        mid = start + (end - start) / 2;
        mergeSort(a, start, mid);
        mergeSort(a, mid + 1, end);
        merge(a, start, mid, end);
    }
}

int main()
{
    int a[200000];
    random_number(a, 200000);
    int len = sizeof(a) / sizeof(a[0]);
    long long c = timeInMiliSecond();
    mergeSort(a, 0, len - 1);
    long long d = timeInMiliSecond() - c;
    for (int i = 0; i < len; i++)
    {
        printf(" %d", a[i]);
    }

    printf("\n\n\nTime taken by merge sort is %lli miliseconds", d);
    return 0;
}