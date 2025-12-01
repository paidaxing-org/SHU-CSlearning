#include <stdio.h>
#include <math.h>
int main()
{
    float a,b,c,x1,x2,dt,d,e;
    scanf("%f%f%f",&a,&b,&c);
    if (a==0&&b==0&&c==0)
        printf("Infinite roots!\n");
    else if (a==0&&b==0&&c!=0)
        printf("No roots!\n");
    else if (a==0&&b!=0)
        printf("Single root: %f\n",-c/b);
    else if (a!=0)
    {
        dt=b*b-4*a*c;
        if (dt>0)
        {
            x1=-b/(a*2)+sqrt(fabs(dt))/(2*a);
            x2=-b/(a*2)-sqrt(fabs(dt))/(2*a);
            printf("Real roots: %f and %f",x1,x2);
        }
        else if (dt<0)
        {
            d=-b/(2*a);
            e=sqrt(fabs(dt))/(2*a);
            printf("Complex roots: %f+%fi, %f-%fi\n",d,e,d,e);
        }
    }
    return 0;
}
