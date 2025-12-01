#include <stdio.h>
int sum=0,s=1;
int fn(int a)
{
    sum=a*s+sum*10;
    s=s+1;
    return sum;
}
int main()
{
    int a,n,i;
    printf("Input a&n:");
    scanf("%d%d",&a,&n);
    for(i=1;i<=n;i++)
        fn(a);
    printf("sum=%d",sum);
    return 0;
}
