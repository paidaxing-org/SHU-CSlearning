#include <stdio.h>
int main()
{
    int j,b,i,sum=0;
    int flag,count=0;
        for(int i=1; i<=1000; i++)
        {
            j=i;
            b=j*j;
            while(j)
            {
                if(j%10==b%10)
                {
                    j=j/10;
                    b=b/10;
                    flag=1;
                }
                else
                {
                    flag=0;
                    break;
                }
            }
            if(flag==1)
            {
                printf("%6d",i);
                sum=sum+1;
                if(sum%5==0)
                    printf("\n");
            }
        }
        return 0;
}

