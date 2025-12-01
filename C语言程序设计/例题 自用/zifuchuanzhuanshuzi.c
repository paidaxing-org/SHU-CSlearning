#include <stdio.h>
#include <string.h>
#define N 81
int main()
{
    int i,number;
    char a[N];
    printf("Enter a string:");
    i=0;
    while((a[i]=getchar())!='\n')
        i++;
    a[i]='\0';
    number=0;
    for(i=0;i<strlen(a);i++)
        if(a[i]>='0'&&a[i]<='9')
         number=number*10+(a[i]-'0');
    printf("count=%d",number);
    return 0;
}
