#include <stdio.h>
int main()
{
    char a[100],n;
    int s=0,i;
    while(n!='\n')
    {   scanf("%c",&n);
        if(n>='a'&&n<='z'||n>='A'&&n<='Z')
        {
            a[s]=n;
            s=s+1;
        }
    }
    for(i=s-1;i>=0;i--)
        printf("%c",a[i]);
    return 0;
}
