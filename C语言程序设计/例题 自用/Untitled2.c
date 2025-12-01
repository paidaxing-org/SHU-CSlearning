#include <stdio.h>
int isPrime(int k)
{   int a,b,i,c;
    for(i=2;i<c;i++)
    {
        if ((c%i)==0)
            a=1;
    }
    if (a==0)
        b=1;
}
int main()
{   int n,k,he=0;
    scanf("%d",&n);
    do{
        k=n%10;
        he=he+char(k);
        n=n/10;
    }while(n!=0);
    if(isPrime(n)&&isPrime(he))
        printf("OK");
    else
        printf("Err");
    return 0;
}
