#include <stdio.h>
int main()
{
    int s,j,i=0,k,m,n,a[20],cishu=0,c,sum=0,h;
    double beishu;
    scanf("%d%d",&n,&m);
    s=n;
    while(s!=0)
    {
        s=s/10;
        i++;
    }
    s=n;
    for(h=i-1;h>=0;h--)
    {
        a[h]=s%10;
        s=s/10;
    }
    for(j=0;j<i-1;j++)
    {
        if(a[j]==m)
        {
            for(k=j;k<i-1;k++)
            {
                a[k]=a[k+1];
            }
            cishu++;
        }
    }
    if(cishu==0)
        printf("not find n in m");
    else
    {
       for(c=0;c<i-cishu;c++)
            sum=sum*10+a[c];
       beishu=n*1.0/sum*1.0;
       for(c=0;c<i-cishu;c++)
        printf("%d",a[c]);
       printf(",");
       printf("%.2f",beishu);
    }
    return 0;
}
