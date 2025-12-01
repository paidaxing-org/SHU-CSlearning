#include <stdio.h>
#include <string.h>
int main()
{
    char a[20]={0},zifu;
    int weizhi,i;
    printf("Enter a string:");
    for(i=0;i<3;i++)
        scanf("%c",&a[i]);
    scanf("%d\n%c",&weizhi,&zifu);
    for(i=strlen(a)+1; i>weizhi; i--)
        a[i]=a[i-1];
    a[weizhi]=zifu;
    puts(a);
    return 0;
}
