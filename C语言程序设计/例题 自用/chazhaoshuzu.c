#include <stdio.h>
int main()
{
    int a[10]={0};
    int x,j,s=0,i,flag=0;
    for(i=0;i<=9;i++)
    {
        scanf("%d",&a[i]);
    }
    scanf("%d",&x);
    for(j=0;j<=9;j++)
    {
        if(a[j]==x)
        {
            printf("Index is %d",j);
            flag=1;
        }
    }
    if(flag==0)
        printf("Not Found");

    return 0;
}
