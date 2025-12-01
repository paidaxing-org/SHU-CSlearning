#include <stdio.h>
int n;
void nixu(int b[])
{
    int i,j,temp;
    for(i=0,j=n-1;i<j;i++,j--)
    {  temp=b[i];
       b[i]=b[j];
       b[j]=temp;
    }
    for(i=0;i<n;i++)
        printf("%3d",b[i]);
}
int main()
{
    int i,a[20];
    printf("Enter n:");
    scanf("%d",&n);
    printf("Enter %d integers:",n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    nixu(a);
    return 0;
}
