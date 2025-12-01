#include <stdio.h>
int main()
{
    int sum=0,i;
    for (i=1;i<=100;i=i+2)
    sum=sum+i;
    printf("sum=%d",sum);
    return 0;
}
