// Merge sort in C

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <sys/time.h>
long long timeInMilliseconds(void)
{
    struct timeval tv;

    gettimeofday(&tv, NULL);
    return (((long long)tv.tv_sec) * 1000) + (tv.tv_usec / 1000);
}
void random_number(int a[])
{
    int i;
    int f = 20000;
    for (i = 0; i < f; i++)
    {
        a[i] = rand() % 20000;
    }
}

// Merge two subarrays L and M into arr
void merge(int arr[], int p, int q, int r)
{

    // Create L ← A[p..q] and M ← A[q+1..r]
    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1], M[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = arr[q + 1 + j];

    // Maintain current index of sub-arrays and main array
    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    // Until we reach either end of either L or M, pick larger among
    // elements L and M and place them in the correct position at A[p..r]
    while (i < n1 && j < n2)
    {
        if (L[i] <= M[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = M[j];
            j++;
        }
        k++;
    }

    // When we run out of elements in either L or M,
    // pick up the remaining elements and put in A[p..r]
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = M[j];
        j++;
        k++;
    }
}

// Divide the array into two subarrays, sort them and merge them
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {

        // m is the point where the array is divided into two subarrays
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Merge the sorted subarrays
        merge(arr, l, m, r);
    }
}

// Print the array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program
int main()
{
    int arr[20000];
    random_number(arr);
    int size = sizeof(arr) / sizeof(arr[0]);
    long long aa = timeInMilliseconds();
    mergeSort(arr, 0, size - 1);
    long long b = timeInMilliseconds();
    double c = (double)b - aa;
    
    printf("Sorted array: \n");
    printArray(arr, size);
    printf("\n\n\n\tTime taken for sorting the array %6.5f miliseconds", c);
}