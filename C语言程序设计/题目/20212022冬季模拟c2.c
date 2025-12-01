#include <stdio.h>
int main()
{
    int kanshu,shangwang,i;
    scanf("%d%d",&kanshu,&shangwang);
    if(kanshu>6&&shangwang>6)
        printf("全能");
    else if(kanshu>6)
        printf("书迷");
    else if(shangwang>6)
        printf("网迷");
    else
        printf("一般");

    return 0;
}
