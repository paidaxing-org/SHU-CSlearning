#include <stdio.h>
int main()
{
    char n;
    printf("Input a lowercase letter:");
    n=getchar();
    printf("A capital letter:");
    putchar(n-32);
    return 0;
}
