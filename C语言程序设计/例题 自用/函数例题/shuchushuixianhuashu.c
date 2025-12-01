#include <stdio.h>
void is(int number)
{
    int i,sum=0,x=number;
    while(number!=0)
    {
        sum=sum+(number%10)*(number%10)*(number%10);
        number=number/10;
    }
    if(x==sum)
        printf("%d\n",sum);
}
int main()
{
    int m,n,i;
    printf("Input m:");
    scanf("%d",&m);
    printf("Input n:");
    scanf("%d",&n);
    if(n<=m)
        for(i=n;i<=m;i++)
           is(i);
    else
        for(i=m;i<=n;i++)
           is(i);
    return 0;
}
