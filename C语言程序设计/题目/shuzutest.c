#include <stdio.h>
#include <string.h>
int main()
{
    int c,d,e,f;
    char a[5]={'a','b'};
    char b[]={'a','b'};
    c=sizeof(a);
    d=sizeof(b);
    e=strlen(a);
    f=strlen(b);
    puts(a);
    puts(b);
    printf("%d %d %d %d",c,d,e,f);

    return 0;
}
