#include <stdio.h>
#include <string.h>
int main()
{
    int a[20],n,i=0,s,weishu,sum=0,j=10;
    char b[100];
    printf("Please input a integer:");
    scanf("%d",&n);
    s=n;
    while(s!=0)
    {
        a[i]=s%10;
        s=s/10;
        printf("%d\n",a[i]);
        i++;
    }
    weishu=i;
    for(i=weishu-1; i>=0; i--)
       {   if(a[i-1]>=2)
           {
               a[i]=a[i]+a[i-1]/2;
               a[i-1]=a[i-1]%2;
               b[j]='a[i-1]';
               j--;
           }
       }
    b[j+1]='\0';
    printf("n=");
    puts(b);
    return 0;
}
