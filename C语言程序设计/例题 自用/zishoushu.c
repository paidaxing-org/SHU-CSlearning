#include <stdio.h>
int main()
{
    int a;
    printf("请输入一个整数:");
    scanf("%d",&a);
    if (a>0)
        printf("正");
    else
        printf("负");
    if (a%2==0)
         printf("偶数");
    else
        printf("奇数");
    return 0;
}
