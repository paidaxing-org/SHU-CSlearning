#include <stdio.h>
int main()
{
    int b,i,j;
    for (i=1; i<=5; i++)
        for(j=1; j<=5; j++)
        {
            b=i*j;
            printf("%d\t",b);
            if (j%5==0)
                printf("\n");
        }
    return 0;
}
