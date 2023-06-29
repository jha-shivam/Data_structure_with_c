// Given an array of integers and integer target, return indices of the two numbers such that they add up to target

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main()
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int i, j;
    int target;
    int temp;
    int k = 0;
    printf("\nEnter your target: ");
    scanf("%d", &target);
    int len = 10;
    for (i = 0; i < 10; i++)
    {
        for (j = 1; j < 10; j++)
        {
            temp = a[i] + a[j];
            if (temp == target)
            {
                printf("\n Your %d pair is: ", k);
                printf("\n Indiced of number is : %d %d and your target is: %d", i, j, target);
                printf("\n value of number is : %d %d and your target is: %d \n", a[i], a[j], target);
                k++;
            }
        }
    }

    return 0;
}