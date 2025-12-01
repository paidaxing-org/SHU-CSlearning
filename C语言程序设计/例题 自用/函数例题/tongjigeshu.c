#include <stdio.h>
void countdigit(int number)
{
    int s=0;
    while(number!=0)
    {
        if(number%10==2)
            s=s+1;
        number=number/10;
    }
    printf("Number of digit 2:%d",s);
}
int main()
{
    int number,digit;
    printf("Input an integer:");
    scanf("%d",&number);
    countdigit(number);
    return 0;
}
