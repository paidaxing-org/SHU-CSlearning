#include <stdio.h>
int main()
{
    int n,k,i,s,x;
    int a[20]={0};
    scanf("%d%d",&n,&k);
    x=n;
    for(i=0;i<k;i++)
    {
        while(x!=0)
        {
            a[i]=a[i]+(x%10)*(x%10);
            x=x/10;
        }
        x=a[i];
    }
    printf("[%d]",n);
    for(i=0;i<k;i++)
    printf("{%d}%d ",i+1,a[i]);
    return 0;
}
