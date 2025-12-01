#include <stdio.h>
#include <string.h>
int length;
void delchar(char s[],char c)
{
    int i,j;
    for(i=0;i<length;i++)
    {
         if(s[i]==c)
         {
             for(j=i;j<length;j++)
                s[j]=s[j+1];
         }
    }
    printf("After deleted,the string is:");
    puts(s);
}
int main()
{
    char s[81],c;
    printf("Enter a string:");
    gets(s);
    length=strlen(s);
    printf("Enter a char:");
    scanf("%c",&c);
    delchar(s,c);
    return 0;
}
