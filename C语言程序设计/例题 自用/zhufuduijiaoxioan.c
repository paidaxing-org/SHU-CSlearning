#include <stdio.h>
int main()
{
    int a[5][5]={{0},{0}},i,j;
    for(i=0;i<5;i++)
        for(j=0;j<5;j++)
            if(i==j||(i+j)==4)
            a[i][j]=1;
    for(i=0;i<5;i++)
     {
          for(j=0;j<5;j++)
             printf("%3d",a[i][j]);
     printf("\n");
     }
     return 0;
}
