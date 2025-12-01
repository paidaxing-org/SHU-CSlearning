#include <stdio.h>
int main()
{
    int a,b,i,ji=1,j,s;
    scanf("%d%d",&a,&b);
    for(i=1; i<=a; i++);
    {
        s=0;
        ji=a;
        a=0;
        if(a%i==0)
        {
        for(j=2; j<i; j++)
        {
            if ((i%j)==0)
                    a=1;
        }
        if (a==0)
            ji=ji*j;

        }
    }
    if(ji==b)
        printf("OK");
    else
        printf("Err");
    return 0;
}
