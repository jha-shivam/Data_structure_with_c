#include <stdio.h>
#include <conio.h>

int main()
{
    int i, j, k, z = 0;
    for (i = 0; i < 5; i++)
    {
        z=0;
        for (j = 0; j < 5 - i-1; j++)
        {
            printf(" ");
        }
        for (k = 0; k <i; k++)
        {
            printf(" %d", z);
            z++;
        }
        printf("\n");
    }
    return 0;
}