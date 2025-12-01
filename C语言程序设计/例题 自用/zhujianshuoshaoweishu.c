#include <stdio.h>
#include <string.h>
#define N 20
int main()
{
    char a[N];
    int i,j,s,weishu;
    printf("Enter a string:");
    gets(a);
    weishu=strlen(a);
    for(i=0; i<weishu; i++)
    {
        printf("%d:",i+1);
        for(j=0; j<weishu; j++)
        {
            if(j>=i)
                printf("%c",a[j]);
            else
                printf(" ");
        }
        printf("\n");
        j=0;
    }
    return 0;
}
