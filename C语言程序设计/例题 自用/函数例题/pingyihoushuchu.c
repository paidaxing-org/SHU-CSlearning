#include <stdio.h>
#include <string.h>
int m;
void rotate(char b[81])
{   int length,i,j;
    char temp;
    length=strlen(b);
    for(j=1;j<=m;j++)
    {
    temp=b[length-1];
    for(i=length-1;i>=0;i--)
        b[i]=b[i-1];
    b[0]=temp;
    }
    puts(b);
}
int main()
{   int i;
    char a[81];
    printf("Enter a string:");
    gets(a);
    printf("Enter m:");
    scanf("%d",&m);
    printf("After rotate right %d bits:",m);
    rotate(a);

    return 0;
}
