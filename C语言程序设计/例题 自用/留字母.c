#include <stdio.h>
int main()
{
    char a='a';
    scanf("%c",&a);
    if(a>='a'&&a<='z'||a>='A'&&a<='Z')
        printf("%c",a);
    while(a!='\n')
    {
        if((a>='a'&&a<='z')||(a>='A'&&a<='Z'))
            printf("%c",a);
        scanf("%c",&a);
    }
    return 0;
}

