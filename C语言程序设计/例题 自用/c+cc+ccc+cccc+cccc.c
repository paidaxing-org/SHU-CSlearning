#include <stdio.h>
int main()
{
    int s[10],a,n,i,sum;
    printf("Input a&n:");
    scanf("%d%d",&a,&n);
    s[0]=a;
    sum=a;
    for(i=1;i<n;i++)
    {   a=a*10;
        s[i]=s[i-1]+a;
        sum=sum+s[i];
    }
    printf("s=%d",sum);
    return 0;
}
