#include <stdio.h>
int prime(int m)
{
    int i;
    for(i=2;i<m;i++)
        if(m%i==0) break;
    if(i==m)
        return 1;
    else
        return 0;
}
int main()
{
    int i,s=0,j;
    for(i=6;i<=100;i=i+2)
    {
            for(j=3;j<=i;j++)
            {
                if(prime(j)==1&&prime(i-j)==1)
                {
                    printf("%4d=%2d+%2d",i,j,i-j);break;
                }
            }
            s=s+1;
            if(s%5==0)
                printf("\n");
    }
    return 0;
}
