#include <stdio.h>
int main()
{
    int a[10]={0},i,temp,j,min,s=0;
    for(i=0;i<10;i++)
        scanf("%d",&a[i]);
    for(i=1;i<10;i++)
        for(j=0;j<9;j++)
        if(a[j]<a[j+1])
        {    temp=a[j+1];
             a[j+1]=a[j];
             a[j]=temp;
        }
    for(i=0;i<10;i++)
        printf("%4d",a[i]);
    printf("\n");
    min=a[9];
    for(i=0;i<10;i++)
        if(a[i]==min)
        s=s+1;
    printf("count=%d",s);
    return 0;
}
