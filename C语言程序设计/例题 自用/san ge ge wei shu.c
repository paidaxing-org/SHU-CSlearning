#include <stdio.h>
int main()
{
    int shu,a,b,c;
    printf("Input a number:");
    scanf("%d",&shu);
    a=shu/100;
    b=(shu-100*a)/10;
    c=shu%10;
    printf("%d %d %d",a,b,c);
    return 0;
}
