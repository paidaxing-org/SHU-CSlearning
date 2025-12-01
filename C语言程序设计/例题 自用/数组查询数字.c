#include <stdio.h>
int main()
{
    int a[20],i,n,flag=0,s=0;
    for(i=0;i<10;i++)
        scanf("%d",&a[i]);
    scanf("%d",&n);
    for(i=0;i<10;i++)
        if(a[i]==n)
            flag=1;
    if(flag==1)
    {
        printf("Index is:");
        for(i=0;i<10;i++)
        {
             if(a[i]==n)
                printf("%3d",s);
             s=s+1;
        }
    }
    else
        printf("Not Found");
    return 0;
}
