#include <stdio.h>
#include <math.h>
int main()
{
    float a,b,c,x1,x2,dt;
    scanf("%f %f %f",&a,&b,&c);
    if (a==0&&b==0&&c==0)
        printf("该方程解为任意实数");
    else if (a==0&&b==0&&c!=0)
        printf("该方程无实数解");
    else if (a==0&&b!=0)
        printf("该方程有唯一实数解 x=%f\n",-c/b);
    else if (a!=0)
    {
        dt=b*b-4*a*c;
        if (dt>0)
        {
            x1=-b/(a*2)+sqrt(fabs(dt))/(2*a);
            x2=-b/(a*2)-sqrt(fabs(dt))/(2*a);
            printf("该方程有两个实数解 x1=%f x2=%f\n",x1,x2);
        }
        else if (dt<0)
            printf("该方程无实数解");
        else if (dt=0)
            printf ("刚方程有一个实数解 x=%f\n",-b/(2*a));
    }
    return 0;
}

