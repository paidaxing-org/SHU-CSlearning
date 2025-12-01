#include <stdio.h>
int main()
{
    int n,i,sum=0,c=2,s=0;
    float jiage,avg;
    scanf("%f%d",&jiage,&n);
    for(i=1; i<=n/2; i++)
    {
        if(sum>n)
            break;
        sum=sum+c;
        c=c*2;
        s=s+1;
    }
        sum=sum-c/2;
        s=s-1;
    avg=(sum*1.0*jiage)/s;
    printf("1个苹果价钱是%.1f元，购买的最大总个数不超过%d，则平均每天买苹果花了%.2f元。",jiage,n,avg);
    return 0;
}
