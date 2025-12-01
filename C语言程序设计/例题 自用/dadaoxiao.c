#include <stdio.h>
int main()
{
    int n,i,j,k,t;
    int a[10]={0};
    printf("Input n:");
    scanf("%d",&n);
    printf("Input %d integers:",n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(j=1;j<n;j++)
        for(k=0;k<n-1;k++)
            if(a[k]<a[k+1])
            {
                t=a[k];
                a[k]=a[k+1];
                a[k+1]=t;
            }
    printf("After sorted:");
    for(i=0;i<n;i++)
        printf("%4d",a[i]);
    return 0;
}
