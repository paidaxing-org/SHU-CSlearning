#include <stdio.h>
int main()
{
    int n,a,b,c=0,i;
    scanf("%d",&n);
    a=1;b=2;
    if(n==1)
        printf("1");
    else if(n==2)
        printf("2");
    else
        for(i=1;i<=(n-2);i++)
        {
            c=a+b;
            a=b;
            b=c;
        }
    printf("%d",c);
    return 0;
}
