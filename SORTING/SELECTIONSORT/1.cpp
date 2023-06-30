#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void sorting(int arr[],int len)
{
    int i,j,min_idx;
    for(i=0;i<len-1;i++)
    {
        min_idx = i;
        for(j=i+1;j<len;j++)
        {
            if(arr[min_idx]>arr[j])
            {
                min_idx = j;
            }   
        }
        if(min_idx!=i)
        {
            int temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
        }
    }
}
int main()
{
    int a[10] = {3,1,200,40,20,5,7,22,14,6};
    sorting(a,10);
    for(int i =0;i<10;i++)
    {
        printf("\n%d",a[i]);
    }
    return 0;
}

