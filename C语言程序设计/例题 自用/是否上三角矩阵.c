#include <stdio.h>
int main()
{
    int a[6][6]={{0},{0}},i,j,flag=1,n;
    printf("Input n:");
    scanf("%d",&n);
    printf("Input array:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
             scanf("%d",&a[i][j]);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
             if(i>j)
                if(a[i][j]!=0)
                    flag=0;
    if(flag==0)
        printf("NO");
    else
        printf("YES");
    return 0;
}
