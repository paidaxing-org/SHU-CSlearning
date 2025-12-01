#include <stdio.h>
int main()
{
    int a,b;
    printf("请输入两个数字:");
    scanf("%d %d",&a,&b);
    a=a+b;
    b=a-b;
    a=a-b;
    printf("交换后两数字为:%d %d\n",a,b);
    return 0;
}
