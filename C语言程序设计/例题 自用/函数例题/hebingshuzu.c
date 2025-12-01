#include <stdio.h>
int n,m;
int c[20];
void hebing(int a[],int b[])
{
    int i=0,j=0,k=0;
    for(k=0; k<n+m; k++)
    {
        if(a[i]>=b[j])
        {
            c[k]=b[j];
            j++;
            printf("%4d",c[k]);
        }
        else
        {
            c[k]=a[i];
            i++;
            printf("%4d",c[k]);
        }
        if(i==n)
            a[i]=20000;
        if(j==m)
            b[j]=20000;
    }
}
int main()
{
    int a[20]= {0},b[20]= {0},i,j;
    printf("Enter n:");
    scanf("%d",&n);
    printf("Enter %d integers:",n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("Enter m:");
    scanf("%d",&m);
    printf("Enter %d integers:",m);
    for(i=0;i<m;i++)
        scanf("%d",&b[i]);
    hebing(a,b);
}
