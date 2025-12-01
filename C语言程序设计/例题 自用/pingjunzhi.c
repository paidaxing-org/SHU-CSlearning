#include <stdio.h>
int main()
{
    double a[10]={0},sum=0,avg;
    int i;
    printf("Please insert 10 scores:\n");
    for(i=0;i<=9;i++)
    {
        scanf("%lf",&a[i]);
        sum=sum+a[i];
    }
    avg=sum*1.0/10;
    printf("\n");
    printf("The average is:%.2lf",avg);
    return 0;
}
