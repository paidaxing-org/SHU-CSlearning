#include<stdio.h>
#include<math.h>
int fib(int n)
{
    if(n==1)
        return 1;
    if(n==2)
        return 1;
    else
    {
        int a,b,fib,i;
        a=1;b=1;
        for(i=3;i<=n;i++)
        {
            fib=a+b;
            a=b;
            b=fib;
        }
        return fib;
    }
}

int main()
{
    int m,n,i;
    printf("Input m:");
    scanf("%d",&m);
    printf("Input n:");
    scanf("%d",&n);
    for(i=1;i<100;i++)
        if(fib(i)>=m&&fib(i)<=n)
            printf("%d\n",fib(i));
    return 0;
}
