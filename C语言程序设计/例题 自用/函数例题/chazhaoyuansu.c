#include <stdio.h>
int a[10]= {0};
int search(int a[],int n,int x)
{
    int i,j,s=0;
    for(i=0; i<=n-1; i++)
        if(a[i]==x) break;
    for(j=0; j<=n-1; j++)
        if(a[i]==x)
            s=s+1;
    if(s==0)
        return 0;
    else
        return i;
}
int main()
{
    int x,n,i=0;
    printf("Input n:");
    scanf("%d",&n);
    printf("Input %d integers:",n);
    for(i=0; i<=n-1; i++)
        scanf("%d",&a[i]);
    printf("Input x:");
    scanf("%d",&x);
    if(search(a,n,x)==0)
        printf("Not Found\n");
    else
        printf("index=%d\n",search(a,n,x));
    return 0;
}
