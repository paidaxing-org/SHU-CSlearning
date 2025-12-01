#include <stdio.h>
int a,b,*pa,*pb;
void Swap(int *pa,int *pb)
{
    int temp;
    temp=*pa;
    *pa=*pb;
    *pb=temp;
}
int main()
{
    a=1;
    b=2;
    pa=&a;
    pb=&b;
    Swap(pa,pb);
    printf("a=%d b=%d",a,b);
    return 0;
}
