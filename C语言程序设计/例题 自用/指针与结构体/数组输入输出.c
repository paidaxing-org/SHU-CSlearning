#include <stdio.h>
int main()
{
    int i=0,s,a[20]={0};
    for(i=0;i<10;i++)
        scanf("%d",a+i);
    s=i;
    for(i=0;i<10;i++)
        printf("%d ",*(a+i));
    return 0;
}
