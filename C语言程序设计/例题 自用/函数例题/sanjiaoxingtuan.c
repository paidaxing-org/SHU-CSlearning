#include <stdio.h>
#include <math.h>
void szt(int n)
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n-i;j++)
              printf("  ");
        for(j=n-i+1;j<=n-1+i;j++)
              printf("%2d",i-abs(j-n));
        printf("\n");
    }
}
int main()
{
    int n;
    printf("Enter n:");
    scanf("%d",&n);
    szt(n);
    return 0;
}
