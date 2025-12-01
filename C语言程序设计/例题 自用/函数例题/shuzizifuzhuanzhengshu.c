#include <stdio.h>
#include <string.h>
int length;
void intoint(char a[])
{
    int digit=0,i,erdigit;
    for(i=0;i<length;i++)
        if(a[i]>='0'&&a[i]<='9')
            digit=digit*10+a[i]-'0';
    erdigit=digit*2;
    printf("digit=%d,%d",digit,erdigit);
}
int main()
{
    char a[80];
    printf("Enter a string:");
    gets(a);
    length=strlen(a);
    intoint(a);
    return 0;
}
