#include <stdio.h>
int main()
{
    int a,b=0;
    printf("Please input the number:");
    scanf("%d",&a);
    printf("Inversed number is: ");
    do{
        printf("%d",a%10);
        a=a/10;
        b=b+1;
    }while(a!=0);
    printf("\nIt has %d bits.",b);
    return 0;
}
