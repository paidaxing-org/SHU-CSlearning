#include <stdio.h>
int main()
{
    int a[3][2]= {{0},{0}};
    int i,j,n,s=0,t=0;
    printf("Enter 6 integers:\n");
    for(i=0; i<=2; i++)
        for(j=0; j<=1; j++)
            scanf("%d",&a[i][j]);
    for(i=0; i<=2; i++)
    {
        for(j=0; j<=1; j++)
            printf("%4d",a[i][j]);
        printf("\n");
    }
    for(i=0; i<=2; i++)
        for(j=0; j<=1; j++)
            if(a[i][j]>a[s][t])
            {
                s=i;t=j;
            }
     printf("max=a[%d][%d]=%d",s,t,a[s][t]);
    return 0;
}
