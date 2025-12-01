#include <stdio.h>
#define PI 3.141592
int main()
{
    double n,m;
    printf("请输入圆的半径：");
    scanf("%lf",&n);
    m=n*n*PI;
    printf("圆的面积为：%.2lf\n",m);
    return 0;
}
