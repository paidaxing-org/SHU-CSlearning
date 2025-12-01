#include <stdio.h>
#include <string.h>
#define N 20
int main()
{
    char a[N],b[N];
    int i,j,weishu,flag=1;
    printf("Enter a string:");
    gets(a);
    weishu=strlen(a);
    for(i=0;i<=weishu-1;i++)
    {
        b[i]=a[weishu-i-1];
        if(b[i]!=a[i])
            flag=0;
    }
    if(flag==1)
        printf("It is a palindrome");
    else
        printf("It is not a palindrome");
    return 0;
}
