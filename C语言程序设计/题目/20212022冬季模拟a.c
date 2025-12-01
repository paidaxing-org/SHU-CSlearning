#include <stdio.h>
int main()
{
    int s,i,a,n,j;
    scanf("%d%d",&a,&n);
    for(i=1;i<=n;i++)
    {
        printf("%d ",a);
        a=a+i;
    }
    return 0;
}
