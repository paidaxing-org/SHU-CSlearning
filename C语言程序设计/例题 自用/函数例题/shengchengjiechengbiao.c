#include <stdio.h>
void fact(int n)
{
    int x=n,i,jiecheng=1;;
    for(i=1;i<=n;i++)
        jiecheng=jiecheng*i;
    printf("%d!=%d\n",x,jiecheng);
}
int main()
{
    int i;
    for(i=1;i<=5;i++)
            fact(i);
    return 0;
}
