#include <stdio.h>
int prime(int n)
{
    int j,flag=0;
    for(j=2; j<n; j++)
        if(n%j==0)
            break;
    if(j==n)
        flag=1;
    return flag;
}
int main()
{
    int i,s=0;
    for(i=1; i<=100; i++)
        if(prime(i))
        {
            printf("%6d",i);
            s=s+1;
            if(s%10==0)
                printf("\n");
        }
    return 0;
}
