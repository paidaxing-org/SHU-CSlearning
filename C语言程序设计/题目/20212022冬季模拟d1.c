#include <stdio.h>
int main()
{
    int i,x;
    int a[10];
    for(i=0;i<10;i++)
        scanf("%d",&a[i]);
    scanf("%d",&x);
    for(i=0;i<10;i++)
        if(a[i]>=x)
             printf("%d ",a[i]);
    return 0;
}
