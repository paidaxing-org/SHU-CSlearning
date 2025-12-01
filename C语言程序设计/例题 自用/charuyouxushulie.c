#include <stdio.h>
int main()
{
    int a[10]={0},i,n,charu,temp,j;
    printf("Enter n:");
    scanf("%d",&n);
    printf("Enter %d integers:",n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("Enter insert integer:");
    scanf("%d",&charu);
    a[n]=charu;
    for(i=1;i<n+1;i++)
        for(j=0;j<n;j++)
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
    for(i=0;i<n+1;i++)
        printf("%4d",a[i]);
    return 0;
}
