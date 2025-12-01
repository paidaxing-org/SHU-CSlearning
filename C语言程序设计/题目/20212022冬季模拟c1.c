#include <stdio.h>
int main()
{
    int a[20]={0};
    int x,i,j,temp;
    for(i=0;i<10;i++)
        scanf("%d",&a[i]);
    scanf("%d",&x);
    if(x<0)
        for(i=0,j=9;i<5,j>=5;i++,j--)
                {
                     temp=a[i];
                     a[i]=a[j];
                     a[j]=temp;
                }

    for(i=0;i<10;i++)
        printf("%d ",a[i]);
    return 0;
}
