#include <stdio.h>
int factorsum(int a)
{   int i,sum=0;
    for(i=1;i<a;i++)
       if(a%i==0)
          sum=sum+i;
    return sum;
}
int main()
{
    int i,m,n;
    printf("Input m:");
    scanf("%d",&m);
    printf("Input n:");
    scanf("%d",&n);
    if(m==1)
        printf("%5d",m);
    for(i=m;i<=n;i++)
        if((factorsum(i))==i)
           printf("%5d",i);
    return 0;
}
