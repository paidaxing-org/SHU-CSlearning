#include <stdio.h>
#include <string.h>
int length;
void daxie(char a[])
{
    int i,j;
    for(i=0; i<length; i++)
        if(a[i]>='A'&&a[i]<='Z')
            break;
    if(i==length)
        printf("No Captial Letter");
    else
    {
        for(j=i;j<length;j++)
            printf("%c",a[j]);
    }
}
int main()
{
    char a[20];
    gets(a);
    length=strlen(a);
    daxie(a);
    return 0;
}
