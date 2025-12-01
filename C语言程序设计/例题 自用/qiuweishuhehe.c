#include <stdio.h>
int main()
{
    int s,n,weishu,sum=0,k=0,shu;
    printf("Input n:");
    scanf("%d",&n);
    shu=n;
    while(n!=0)
    {
        s=n%10;
        sum=sum+s;
        n=n/10;
        k=k+1;
    }
    if(shu<0)
        sum=-sum;
    printf("count=%d,sum=%d",k,sum);
    return 0;
}
