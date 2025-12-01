#include <stdio.h>
int main()
{
    int n,i,cheng=1;
    printf("Enter a number:");
    scanf("%d",&n);
    for (i=1;i<=n;i++)
        cheng=cheng*i;
    printf("%d!=%d",n,cheng);
    return 0;
}
