#include <stdio.h>
int main()
{
    int n,m,i,j,s;
    scanf("%d%d",&n,&m);
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<=2*m;j++)
        {
             if(j==m)
                printf("C");
             else
                printf(" ");
        }
        printf("\n");
    }
    for(j=0;j<2*m;j++)
    {
        if(j>=m&&j<=m+(m+1)/2)
            printf("C");
        else
            printf(" ");
    }
    printf("\n");
    for(i=n;i<2*n-1;i++)
    {
        for(j=0;j<=2*m;j++)
        {
             if(j==m)
                printf("C");
             else
                printf(" ");
        }
        printf("\n");
    }
    for(j=0;j<=2*m;j++)
        printf("C");
    return 0;
}
