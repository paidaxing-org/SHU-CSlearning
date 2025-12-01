#include <stdio.h>
#include <string.h>
int main()
{
    int n,i=0,j=0,k,weishu,s,x,r;
    int a[10],c[10];
    char b[10];
    printf("Please input a integer:");
    scanf("%d",&n);
    s=n;
     while(s!=0)
    {
        s=s/10;
        i++;
    }
    weishu=i;
    i=i-1;
    s=n;
    while(s!=0)
    {
        a[i]=s%10;
        s=s/10;
        i--;
    }
    x=n;
    while(x!=0)
       {
            r=x%2;
            x=x/2;
            c[j]=r;
            j++;
       }
       printf("n=");
       for(i=j-1;i>=0;i--)
        printf("%d",c[i]);
    return 0;
}
