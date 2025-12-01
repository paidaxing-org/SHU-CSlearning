#include <stdio.h>
void swap(int x,int y)
{   int t;
    t=x;
    x=y;
    y=t;
    printf("in swap:x=%d,y=%d\n",x,y);
}
int main()
{
    int a=2,b=3;
    printf("before swap:a=%d,b=%d\n",a,b);
    swap(a,b);
    printf("after swap:a=%d,b=%d\n",a,b);
    return 0;
}
