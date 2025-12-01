#include <stdio.h>
void xingxing()
{
    int j;
    for(j=1;j<=5;j++)
        printf("*");
    printf("\n");
}
int main()
{   int i;
    for(i=1;i<=3;i++)
        xingxing();
    return 0;
}
