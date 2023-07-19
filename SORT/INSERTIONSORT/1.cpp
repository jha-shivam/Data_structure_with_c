#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<sys/time.h>
#include<unistd.h>

long long timeInMiliseconds(void)
{
	struct timeval t;
	gettimeofday(&t,NULL);
	return (((long long)t.tv_sec)*1000)+(t.tv_usec/1000);
}
void randomNumbers(int a[],int size)
{
	for(int i=0;i<size;i++)
	a[i] = rand()%1000;
}
void insertionSort(int a[],int size)
{
	int i,j,temp;
	for(i=1;i<size;i++)
	{
		temp = a[i];
		for(j=i-1;j>=0;j--)
		{
			if(a[j]>temp)
			{
				a[j+1] = a[j];
			}
			else{
				break;
			}
		}
		a[j+1] = temp;
	}
}
int main()
{
	int a[100000];
	int size = sizeof(a)/sizeof(a[0]);
	randomNumbers(a,size);
	long long c = timeInMiliseconds();
	insertionSort(a,size);
	long long b = timeInMiliseconds()-c;
	float sec = ((b+500)/1000);
	for(int i=0;i<size;i++)
	printf("\t%d",a[i]);
	
	printf("\n%f",sec);
	return 0;
}
