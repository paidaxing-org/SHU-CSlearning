#include <stdio.h>
int main()
{   int i,a,b,bei,yin;
    scanf("%d%d",&a,&b);
    for(i=1;i<=a;i++)
    {
        if(a%i==0&&b%i==0)
            yin=i;
    }
    bei=a*b/yin;
    printf("最小公倍数:%d 最大公因数:%d",bei,yin);
    return 0;
}
