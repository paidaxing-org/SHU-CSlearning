#include <stdio.h>
int main()
{
    int a;
    scanf("%d",&a);
    if(a>=0)
       a=a;
    else
        a=-a;
    printf("%d",a);
    return 0;
}
