#include <stdio.h>
void zuidazhi(int a,int b,int *max,int *min)
{
    *max=a>b?a:b;
    *min=a<b?a:b;
}
int main()
{
    int a,b,max,min;
    scanf("%d%d",&a,&b);
    zuidazhi(a,b,&max,&min);
    printf("max=%d min=%d",max,min);
    return 0;
}
