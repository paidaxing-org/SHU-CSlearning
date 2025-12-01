#include <stdio.h>
int main()
{
    int a[4][4]= {{0},{0}},i,j;
    for(i=0; i<4; i++)
        for(j=0; j<4; j++)
            if(i>=j)
                a[i][j]=1;
    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
            printf("%3d",a[i][j]);
        printf("\n");
    }
    return 0;
}
