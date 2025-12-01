#include <stdio.h>
#include <string.h>
#define N 81
int main()
{
    char a[N],ch;
    int i,j,n;
    printf("Enter a string:");
    gets(a);
    n=strlen(a);
    scanf("%c",&ch);
    for(i=0;i<n;i++)
    {
        if(a[i]==ch)
        {
           for(j=i;j<n;j++)
              a[j]=a[j+1];
           n=n-1;
           i--;
        }
    }
    puts(a);
    return 0;
}
