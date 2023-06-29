#include<stdio.h>
#include<conio.h>

int main()
{
    int i,j,k=0;
    for(i=0;i<=5;i++)
    {
        for(k=0;k<(i+1);k++)
        {
            printf(" ");
        }
        for(j=0;j<=5;j++)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}