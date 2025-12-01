#include <stdio.h>
int main()
{
    int m,n,i,j,a,b=1;
    printf("Input m,n:");
    scanf("%d%d",m,n);
    if (m<=0||n<=0)
    {
        printf("Input again!");
        scanf("&d&d",&m,&n);
    }
    a=m*n;
    for(i=1; i<=m*n; i++)
    {
        if(i%m==0 && i%n==0 && i<a)
            a=i;
    }
    for (j=1;j<=m*n;j++)
    {
        if(m%j==0 && n%j==0 && j>b)
            b=j;
    }
    printf("%d和%d的最大公因数:%d",m,n,b);
    printf("%d和%d的最小公倍数:%d",m,n,a);
    return 0;
}
