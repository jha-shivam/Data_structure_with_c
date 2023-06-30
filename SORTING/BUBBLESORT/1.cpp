#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void sorting(int a[],int len)
{
    int i,j;
    for(i=0;i<len;i++)
    {
        for(j=0;j<len;j++)
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
int main()
{
    int a[10] = {1,43,2,6,54,70,80,0,11,9};
    sorting(a,10);
    for(int i=0;i<10;i++)
    {
        printf("\n%d",a[i]);
    }
    return 0;
}