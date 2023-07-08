#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void random_number(int a[],int len)
{
	int i;
	for(i=0;i<len;i++)
	{
		a[i] = rand()%100;
	}
}
void merge(int a[], int b[], int c[], int a_len, int b_len)
{
	int i = 0, j = 0, k = 0;
	while (i < a_len && j < b_len)
	{
		if (a[i] < b[j])
		{
			c[k] = a[i];
			k++;
			i++;
		}
		else
		{
			c[k] = b[j];
			j++;
			k++;
		}
	}
	if (i > a_len)
	{
		while (j <= b_len)
		{
			c[k] = b[j];
			k++;
			j++;
		}
	}
	else
	{
		while (i <= a_len)
		{
			c[k] = a[i];
			k++;
			i++;
		}
	}
}
int main()
{
	int a[10];
	int len_a = sizeof(a) / sizeof(a[0]);
	random_number(a,len_a);
	int b[5];
	int len_b = sizeof(b) / sizeof(b[0]);
	random_number(b,len_b);
	
	printf("\nValues in first array");
	for(int i=0;i<len_a;i++)
	{
		printf("\t%d",a[i]);
	}
	printf("\nValues in second array");
	for(int i=0;i<len_b;i++)
	{
		printf("\t%d",b[i]);
	}
	int c[len_a + len_b];
	merge(a, b, c, len_a, len_b);
	printf("\n\nThird array");
	for (int i = 0; i < (len_a + len_b); i++)
	{
		printf("\t%d", c[i]);
	}
	return 0;
}