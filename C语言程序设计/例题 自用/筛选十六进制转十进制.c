#include <stdio.h>
#include <string.h>
int main()
{
    char a[10],b[10];
    int i,j=0,n,sum=0,number,factor=1;
    printf("Enter a string:");
    gets(a);
    for(i=0; i<strlen(a); i++)
        if(a[i]>='0'&&a[i]<='9'||a[i]>='a'&&a[i]<='f'||a[i]>='A'&&a[i]<='F')
        {
            b[j]=a[i];
            j=j+1;
        }
    b[j]='\0';
    printf("New string:");
    puts(b);
    i=strlen(b)-1;
    while(b[i]!='\0')
    {
        if(b[i]>='0'&&b[i]<='9')
            number=b[i]-'0';
        if(b[i]>='a'&&b[i]<='f')
            number=b[i]-'a'+10;
        if(b[i]>='A'&&b[i]<='F')
            number=b[i]-'A'+10;
        number=number*factor;
        sum=sum+number;
        factor=factor*16;
        i--;
    }
    printf("number=%d",sum);
    return 0;
}
