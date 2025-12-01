#include <stdio.h>
int main()
{
    int shu,a,b,c,d;
    scanf("%d",&shu);
    a=shu/100;
    b=(shu-100*a)/10;
    c=shu%10;
    d=100*c+10*b+a;
    printf("%d\n",d);
    return 0;
}
