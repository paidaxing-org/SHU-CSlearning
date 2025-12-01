#include <stdio.h>
int main()
{
    int a,b,c,d,e,f,daoxu;
    scanf("%d",&a);
    b=a/10000;
    c=(a-10000*b)/1000;
    d=(a-10000*b-1000*c)/100;
    e=(a-10000*b-1000*c-100*d)/10;
    f=a%10;
    daoxu=10000*f+1000*e+100*d+10*c+b;
    printf("%d",daoxu);
    return 0;
}
