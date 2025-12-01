#include <stdio.h>
#include <string.h>
int main()
{
    int s,i=0,number=0,length;
    char a[81];
    printf("Enter a string:");
    gets(a);
    length=strlen(a);
    a[length]='\0';
    for(i=0;i<length;i++)
    {
        if(a[i]>='0'&&a[i]<='9')
         number=number*10+(a[i]-'0');
    }
    printf("digit=%d",number);
    return 0;
}
