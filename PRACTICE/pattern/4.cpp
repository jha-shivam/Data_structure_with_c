#include<stdio.h>
#include<conio.h>

int main()
{
    int i,j,k=0;
    for(i=5;i>=0;i--)
    {
        for(j=0;j<=i;j++)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}