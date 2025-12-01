#include <stdio.h>
int factorsum(int number)
{   int i,sum=0
    for(i=0;i<number;i++)
        if(number%i==0)
            sum=sum+i;
    return sum;
}


int main()
{   int m,n;
    printf("Input m:");
    scanf("%d",&m);
    printf("Input n:");
    scanf("%d",&n);



    return 0;
}
