#include <stdio.h>
int main()
{
    int n,numou=0,numji=0,he1=0,he2=0;
    float avgji,avgou;
    scanf("%d",&n);
    while(n!=0)
    {
        if(n%2==0)
        {  numou+=1;
           he1=he1+n;
        }
        else
        {
            numji+=1;
            he2=he2+n;
        }
        scanf(" %d",&n);
    }
    avgji=he2*1.0/numji;
    avgou=he1*1.0/numou;
    printf("Number of even:%d;Average of even:%.2f\n",numji,avgou);
    printf("Number of odd:%d;Average of odd:%.2f\n",numou,avgji);
    return 0;
}
