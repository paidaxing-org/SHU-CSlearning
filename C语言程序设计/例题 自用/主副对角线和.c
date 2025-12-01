#include <stdio.h>
int main()
{
    int a[4][4]={{0},{0}},i,j,sum=0;
    for(i=0;i<4;i++)
        for(j=0;j<4;j++)
            scanf("%d",&a[i][j]);
    for(i=0;i<4;i++)
        for(j=0;j<4;j++)
            if(i==j||i+j==3)
                sum=sum+a[i][j];
    printf("sum=%d",sum);
    return 0;
}
