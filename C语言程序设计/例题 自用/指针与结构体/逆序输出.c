#include <stdio.h>
int main()
{
    int a[20];
    int *pa,*pb,temp;
    for(pa=a;pa<a+10;pa++)
        scanf("%d",pa);
    for(pa=a,pb=a+9;pa<pb;pa++,pb--)
    {
        temp=*pa;
        *pa=*pb;
        *pb=temp;
    }
    printf("After reverse:");
    for(pa=a;pa<a+10;pa++)
        printf("%d ",*pa);
    return 0;
}
