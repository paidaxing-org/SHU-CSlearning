#include <stdio.h>
#include <string.h>
int main()
{
    char s[20];
    int i,j,length;
    gets(s);
    length=strlen(s);
    for(i=0;i<length;i++)
    {
        printf("%d:",i);
        for(j=0;j<length;j++)
        {
            if(j>=i)
              printf("%c",s[j]);
        }
        printf("\n");
    }
    return 0;
}
