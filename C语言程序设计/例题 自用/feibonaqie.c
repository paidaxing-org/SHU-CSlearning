#include <stdio.h>
int main()
{
    int a[100]={0};
    a[0]=1;
    a[1]=1;
    int i,n;
    printf("Please select I number to be printed:");
    scanf("%d",&n);
    for(i=2;i<n;i++)
     {
         a[i]=a[i-2]+a[i-1];
     }
    printf("The number is %d",a[n-1]);
    return 0;
}
