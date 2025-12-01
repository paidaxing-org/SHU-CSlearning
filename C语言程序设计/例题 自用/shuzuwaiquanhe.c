#include <stdio.h>
int main()
{
    int a[5][5]={{0},{0}};
    int n,i,j,sum=0;
    for(i=0;i<5;i++)
        for(j=0;j<5;j++)
           scanf("%d",&a[i][j]);
    for(i=0;i<5;i=i+4)
      for(j=0;j<5;j++)
        sum=sum+a[i][j];
    for(i=0;i<5;i++)
        for(j=0;j<5;j=j+4)
          sum=sum+a[i][j];
    sum=sum-a[0][0]-a[4][4]-a[0][4]-a[4][0];
    printf("sum=%d",sum);
    return 0;
}
