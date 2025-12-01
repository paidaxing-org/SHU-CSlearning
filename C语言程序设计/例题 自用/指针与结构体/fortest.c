#include <stdio.h>
int main()
{
    int a;
    int *pa;
    pa=&a;
    scanf("%d",&a);
    printf("%d %d",pa,*pa);
    return 0;
}
