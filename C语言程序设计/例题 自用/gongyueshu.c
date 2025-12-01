#include <stdio.h>
int main()
{
    int m,n,p,flag,temp,a,b;
    printf("Input m,n:");
    scanf("%d%d",&m,&n);
    while (m<1||n<1)

    {
        printf("Input again!\n");
        scanf("%d%d",&m,&n);
    }
    if(m<n)
    {
        a=m;
        b=n;
        temp=m;
        m=n;
        n=temp;
    }
    p=m*n;
    flag=m%n;
    while(flag!=0)
    {
        m=n;
        n=flag;
        flag=m%n;
    }
    printf("%d和%d的最大公约数:%d\n",a,b,n);
    printf("%d和%d的最小公倍数:%d\n",a,b,p/n);
    return 0;
}


