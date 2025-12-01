#include <stdio.h>
#include <string.h>
int length;
void fuke(char a[],int m)
{
    char b[80];
    int i,j=0;
    for(i=m-1;i<length;i++)
    {
        b[j]=a[i];
        j++;
    }
    b[j]='\0';
    puts(b);
}
int main()
{
    int m;
    char a[80];
    printf("Enter a string:");
    gets(a);
    length=strlen(a);
    printf("Enter m:");
    scanf("%d",&m);
    fuke(a,m);
    return 0;
}
