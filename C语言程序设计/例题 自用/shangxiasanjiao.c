#include <stdio.h>
int main()
{
    int a[9][9]= {{0},{0}};
    int i,j,n;
    printf("Input n:");
    scanf("%d",&n);
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            scanf("%d",&a[i][j]);
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
            printf("%4d",a[i][j]);
        printf("\n");
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {   if(i>=j)
            printf("%4d",a[i][j]);
        }
        printf("\n");
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {   if(i<=j)
            printf("%4d",a[i][j]);
            else
            printf("    ");
        }
        printf("\n");
    }
    return 0;
}
