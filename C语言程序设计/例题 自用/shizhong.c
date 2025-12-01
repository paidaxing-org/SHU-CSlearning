#include <stdio.h>
int main()
{
    int h1,h2,m1,m2,x,a,b;
    scanf("%d:%d",&h1,&m1);
    scanf("%d:%d",&h2,&m2);
    if(h1*60+m1<h2*60+m2)
    {
        x=h2*60+m2-h1*60-m1;
        a=x/60;
        b=x-a*60;
        printf("%d:%02d",a,b);
    }
    else
    {
        x=h1*60+m1-h2*60-m2;
        a=x/60;
        b=x-a*60;
        printf("%d:%02d",a,b);
    }
    return 0;
}
