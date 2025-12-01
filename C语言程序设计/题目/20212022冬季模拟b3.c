#include <stdio.h>
#include <string.h>
int main()
{
    int i,j,s,b[20],temp2;
    double a[20];
    double temp,temp3;
    int c[6];
    for(i=0;i<6;i++)
        scanf("%d:%lf",&b[i],&a[i]);
    for(i=0;i<6;i++)
        for(j=0;j<6;j++)
            if(b[j]>=b[i])
            {
                temp2=b[i];
                b[i]=b[j];
                b[j]=temp2;
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
    for(i=0;i<6;i++)
        for(j=0;j<6;j++)
            if(b[i]==b[j])
                if(a[i]<a[j])
                {
                   temp3=a[i];
                   a[i]=a[j];
                   a[j]=temp3;
                }
    for(i=0;i<6;i++)
        if(a[i]>=10.0)
           printf("%d:%.2lf ",b[i],a[i]);
        else
           printf("%d:0%.2lf ",b[i],a[i]);
    return 0;
}
