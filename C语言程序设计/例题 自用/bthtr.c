#include <stdio.h>
int main()
{
    char a;
    int b=0;
    scanf("%c",&a);
    while (a!='\n')
    {
        if (a>='0'&&a<='9')
        {
            b=b+1;
            printf("%c ",a);
        }
        scanf("%c",&a);
    }
    printf("\nThere are %d digits!",b);
    return 0;
}
