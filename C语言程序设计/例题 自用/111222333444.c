#include <stdio.h>
int main()
{
    char a;
    int b;
    while ((a=getchar())!='\n')
    {
        if (a>='0'&&a<='9')
        {
            b+=1;
            printf("%c ",a);
        }
    }
    printf("\nThere are %d digits!",b);
    return 0;
}
