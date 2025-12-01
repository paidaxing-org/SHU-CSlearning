#include <stdio.h>
int main()
{
    int a[10]={0};
    int i,j,s,temp;
    for(i=0;i<10;i++)
        scanf("%d",&a[i]);
    for(i=0;i<10;i++)
        for(j=0;j<10;j++)
            if(a[i]>a[j])
            {
                   temp=a[i];
                   a[i]=a[j];
                   a[j]=temp;
            }
    printf("Award1:%d\n",a[0]);
    printf("Award2:%d\n",a[2]);
    printf("Award3:%d\n",a[5]);
    return 0;
}
