#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<sys/time.h>
long long timeInMiliseconds(void)
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return (((long long)t.tv_sec) * 1000) + (t.tv_usec / 1000);
}
void randomNumber(int a[],int size)
{
    for(int i=0;i<size;i++)
    {
        a[i] = rand()%1000;
    }
}
int partition_s(int a[],int lb,int ub)
{
    int 
}
void quickSort(int array[],int start,int end)
{
    if(start<end)
    {
        int loc = partition_s(a,start,end);
        quickSort(a,start,loc-1);
        quickSort(a,loc+1,end);
    }
}
int main()
{
    int a[100];
    int size = sizeof(a)/sizeof(a[0]);
    randomNumber(a,size);
    long long c = timeInMiliseconds();
    quickSort(a,0,size);
    long long d = timeInMiliseconds()-c;
    for(int i=0;i<size;i++)
    {
        printf("\t%d",a[i]);
    }
    printf("\nTime taken for sorting is: %0.8lli",d);
    return 0;
}