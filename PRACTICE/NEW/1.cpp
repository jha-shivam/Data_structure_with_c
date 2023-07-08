#include<stdio.h>
#include<time.h>
#include<sys/time.h>
#include<unistd.h>
long long timeInMilliseconds(void) {
    struct timeval tv;

    gettimeofday(&tv,NULL);
    return (((long long)tv.tv_sec)*1000)+(tv.tv_usec/1000);
}
int main()
{
   long long a = timeInMilliseconds();
   printf("\n\n%lli",a);
   int i;
   printf("\n\n");
//    for(i=0; i<5000;i++)
//     {
//         int j;
//         j = ("%d", (i*1)+(1^4));
//         printf("%d",j);
//     }
    sleep(5);
    long long b = timeInMilliseconds();
    printf("\n\n%lli",b);

    printf("\n\n\n\nHello: %lli",b-a);
   return 0;

}