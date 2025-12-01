#include <stdio.h>
#include <string.h>
int main()
{
    char a[100];
    int length,j,i,k;
    gets(a);
    length=strlen(a);
    for(j=0;j<length;j++)
    {   printf("%d:",j+1);
        for(k=0;k<j;k++)
            printf(" ");
        for(i=length-1;i>=0;i--)
        {

             if(i>=j)
            printf("%c",a[i]);
        }
        printf("\n");
    }
    return 0;
}
