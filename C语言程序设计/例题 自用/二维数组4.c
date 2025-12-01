#include <stdio.h>
int main()
{
    int a[4][4]= {{0},{0}},i,j;
    for(i=0; i<4; i++)
        for(j=0; j<4; j++)
            a[i][j]=i+j;
    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
            printf("%3d",a[i][j]);
        printf("\n");
    }
    return 0;
}
