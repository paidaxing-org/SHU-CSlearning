#include <stdio.h>
#include <string.h>
#define N 20
int main()
{
    char a[N];
    char n;
    int i,s,weishu,flag=0;
    printf("Enter a string:");
    gets(a);
    scanf("%c",&n);
    weishu=strlen(a);
    for(i=0;i<weishu;i++)
        if (a[i]==n)
        {
            flag=1;
            break;
        }
    if(flag==1)
        printf("Found the char at %d",i+1);
    else
        printf("Not found");
    return 0;
}
