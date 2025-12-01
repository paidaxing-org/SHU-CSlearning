#include <stdio.h>
int main()
{
    int i,n,a,b,c;
    for(i=1; i<=1000; i++)
    {
        n=i;
        a=0;
        do
        {
            b=i%10;
            a=a+b*b*b;
            i=i/10;
        }
        while(i!=0);
        i=n;
        if(n==a) printf("%d\n",n);
    }
    return 0;
}
