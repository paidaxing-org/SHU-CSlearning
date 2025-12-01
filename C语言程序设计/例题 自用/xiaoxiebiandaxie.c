#include <stdio.h>
#include <string.h>
int daxie(char c)
{
    if(c>='a'&&c<='z') return c=c-32;
    return c;
}
int main()
{
    char a[20];
    int i;
    printf("Enter a string:");
    gets(a);
    for(i=0;i<strlen(a);i++)
        a[i]=daxie(a[i]);
    puts(a);
    return 0;
}
