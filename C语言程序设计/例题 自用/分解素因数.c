#include <stdio.h>
int main()
{
    int n,a,b,c,i;
    scanf("%d",&n);
    printf("%d",n);
    printf("=");
    for(i=2;i<=n;i++)
    {   while(i!=n)
        {
        if(n%i==0)
          {  printf("%d*",i);
             n=n/i;
          }
        else{ break;
        }
        }
    }
    printf("%d",n);
    return 0;
}
