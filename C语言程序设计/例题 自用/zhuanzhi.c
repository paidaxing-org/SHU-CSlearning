#include <stdio.h>
int main()
{
    int a[6][6]= {{0},{0}};
    int n,j,i,temp;
    printf("Enter n:");
    scanf("%d",&n);
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            scanf("%d",&a[i][j]);
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            if(i<j)
            {
                temp=a[i][j];
                a[i][j]=a[j][i];
                a[j][i]=temp;
            }
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
            printf("%4d",a[i][j]);
        printf("\n");
    }
    return 0;
}
