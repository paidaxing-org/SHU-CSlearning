#include <stdio.h>
int main()
{
    int h,m,s;
    scanf("%d:%d:%d",&h,&m,&s);
    if(s==59)
    {
        s=00;
        m+=1;
        if(m==60)
        {
            m=00;
            h+=1;
            if(h==24)
                h=00;
        }
    }
    else
    {
        s+=1;
        m=m;
        h=h;
    }
    printf("%02d:%02d:%02d",h,m,s);
    return 0;
}
