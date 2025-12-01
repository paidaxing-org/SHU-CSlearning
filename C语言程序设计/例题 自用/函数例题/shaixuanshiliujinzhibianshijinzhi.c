#include <stdio.h>
#include <string.h>
int hexvalue(char a[])
{   int i,j=0,sum=0,factor=1,length,number;
    length=strlen(a);
    char b[81];
    for(i=0;i<length;i++)
        if(a[i]>='0'&&a[i]<='9'||a[i]>='A'&&a[i]<='F'||a[i]>='a'&&a[i]<='f')
        {
            b[j]=a[i];
            j++;
        }
    b[j]='\0';
    i=strlen(b)-1;
    while(b[i]!='\0')
    {
        if(b[i]>='0'&&b[i]<='9')
            number=b[i]-'0';
        else if(b[i]>='a'&&b[i]<='f')
            number=b[i]-'a'+10;
        else if(b[i]>='A'&&b[i]<='F')
            number=b[i]-'A'+10;
        number=number*factor;
        sum=sum+number;
        factor=factor*16;
        i--;
    }
    return sum;
}
int main()
{
    char a[81];
    int i;
    printf("Enter a string(hex):");
    gets(a);
    printf("%sH=%dD\n",a,hexvalue(a));
    return 0;
}
